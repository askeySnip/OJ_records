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

int l[23];
vii co;

int get_ones(int i) {
	int c = 0;
	i = i >> 1;
	while(i) {
		if(i&1) c++;
		i = i>>1;
	}
	return c;
}

int cacul(int k) {
	int ret = 0;
	int tk = k>>1, cnt = 1;
	while(tk) {
		if(tk&1) ret+=l[cnt];
		cnt++;
		tk = tk >> 1;
	}
	for(int i=0; i<co.size(); i++) {
		int t = co[i].first & k;
		int no = get_ones(t);
		if(no > 1) {
			ret -= (no-1)*co[i].second;
		}
	}
	return ret;
}
int main() {
	int n, a, m, kase = 0;
	while(scanf("%d %d", &n, &a), n||a) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &l[i]);
		}
		co.clear();
		scanf("%d", &m);
		int t, v, b;
		for(int i=0; i<m; i++) {
			scanf("%d", &t);
			int s = 0;
			for(int j=0; j<t; j++) {
				scanf("%d", &b);
				s+= (1<<b);
			}
			scanf("%d", &v);
			co.push_back(make_pair(s, v));
		}
		int cus = 0, ans = 0;
		for(int i=0; i<(1<<(n+1)); i+=2) {
			if(get_ones(i) != a) continue;
			int tcus = cacul(i);
			if(tcus > cus) {
				cus = tcus;
				ans = i;
			}
		}
		printf("Case Number  %d\n", ++kase);
		printf("Number of Customers: %d\n", cus);
		printf("Locations recommended:");
		int cc = 0;
		while(ans) {
			if(ans&1) printf(" %d", cc);
			cc++;
			ans = ans >> 1;
		}
		printf("\n\n");
	} 
	return 0;
}