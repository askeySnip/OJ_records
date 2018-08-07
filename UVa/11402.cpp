/*
ID: leezhen
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

const int N = 1024000;

int t, s[N], n, sn;
char str[55];

struct Node {
	int r, l, b, flag;
	Node() {}
	Node(int l, int r) {
		this->l = l; this->r = r;
		b = flag = 0;
	}
	int len() {
		return r-l+1;
	}
} node[4*N];

void pushup(int x) {
	node[x].b = node[lson(x)].b + node[rson(x)].b;
}

void build(int l, int r, int x=0) {
	node[x] = Node(l, r);
	if(l == r) {
		node[x].b = s[l];
		return;
	}
	int mid = (node[x].l + node[x].r)/2;
	build(l, mid, lson(x));
	build(mid+1, r, rson(x));
	pushup(x);
}

void init() {
	scanf("%d", &n);
	sn = 0;
	while(n--) {
		int num;
		scanf("%d", &num);
		scanf("%s", str);
		int len = strlen(str);
		while(num--) {
			for(int i=0; i<len; i++) s[sn++] = str[i] - '0';
		}
	}
	build(0, sn-1);
}

int getS(int a, int b) {
	if(a == 3 && b == 3) return 0;
	if(a == 3 && b == 1) return 2;
	if(a == 3 && b == 2) return 1;
	if(a == 3 && b == 0) return 3;
	if(a == 2) return 2;
	if(a == 1) return 1;
	return 0;
}

void pushdown(int x) {
	if(node[x].flag) {
		int ls = getS(node[x].flag, node[lson(x)].flag);
		node[lson(x)].flag = ls;
		if(node[x].flag == 2) node[lson(x)].b = 0;
		if(node[x].flag == 1) node[lson(x)].b = node[lson(x)].len();
		if(node[x].flag == 3) node[lson(x)].b = node[lson(x)].len() - node[lson(x)].b;
		int rs = getS(node[x].flag, node[rson(x)].flag);
		node[rson(x)].flag = rs;
		if(node[x].flag == 2) node[rson(x)].b = 0;
		if(node[x].flag == 1) node[rson(x)].b = node[rson(x)].len();
		if(node[x].flag == 3) node[rson(x)].b = node[rson(x)].len() - node[rson(x)].b;
		node[x].flag = 0;
	}
}

void modify(int l, int r, int v, int x = 0) {
	if(node[x].l >= l && node[x].r <= r) {
		int ts = getS(v, node[x].flag);
		if(v==1) node[x].b = node[x].len();
		else if(v == 2) node[x].b = 0;
		else node[x].b = node[x].len() - node[x].b;
		node[x].flag = ts;
		return;
	}
	pushdown(x);
	int mid = (node[x].l + node[x].r) / 2;
	if(l <= mid) modify(l, r, v, lson(x));
	if(r > mid) modify(l, r, v, rson(x));
	pushup(x);
}

int S(int l, int r, int x = 0) {
	if(node[x].l >= l && node[x].r <= r) return node[x].b;
	int mid = (node[x].l + node[x].r) / 2;
	int ans = 0;
	pushdown(x);
	if(l <= mid) ans += S(l, r, lson(x));
	if(r > mid) ans += S(l, r, rson(x));
	pushup(x);
	return ans;
}

int main() {
	int kase = 0;
	scanf("%d", &t);
	while(t--) {
		init();
		int q;
		scanf("%d", &q);
		char Q[5]; int a, b;
		printf("Case %d:\n", ++kase);
		int Qcas = 0;
		while(q--) {
			scanf("%s%d%d", Q, &a, &b);
			if(Q[0] == 'F') modify(a, b, 1);
			if(Q[0] == 'E') modify(a, b, 2);
			if(Q[0] == 'I') modify(a, b, 3);
			if(Q[0] == 'S') printf("Q%d: %d\n", ++Qcas, S(a, b));
		}
	}
	return 0;
}