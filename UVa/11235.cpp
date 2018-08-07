/*
ID: leezhen
TASK: segment tree practice
LANG: C++11                
*/


/*
Notice: this problem is just use st to do the hole range part not these with some part.
It's a real nice problem.
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
int n, q;
int p[100003];
int Left[100003], Right[100003];
int a[100003];
int c[100003][20];
void init() {
	for(int i=0; i<n; i++) {			
		c[i][0] = a[i];
	}
	for(int i=1; (1<<i)<=n; i++) {
		for(int j=0; j+(1<<i)<=n; j++) {
			c[j][i] = max(c[j][i-1], c[j+(1<<(i-1))][i-1]);
		}
	}
}

int rmq(int s, int t) {
	int len = t-s+1;
	int k = 0;
	while(1<<(k+1) <= len) {
		k++;
	}
	return max(c[s][k], c[t-(1<<k)+1][k]);
}

int main() {
	while(scanf("%d", &n), n) {
		scanf("%d", &q);
		for(int i=0; i<n; i++) scanf("%d", &p[i]);
		memset(a, 0, sizeof(a));
		int pos = 0;
		Left[0] = 0;
		a[0] = 1;
		for(int i=1; i<n; i++) {
			if(p[i] == p[i-1]){
				a[i] = a[i-1]+1;
			}
			else {
				pos = i;
				a[i] = 1;
			}
			Left[i] = pos;
		}
		pos = n-1; Right[n-1] = n-1;
		for(int i=n-2; i>=0; i--) {
			if(p[i] == p[i+1]) {
				a[i] = a[i+1];
			}else {
				pos = i;
			}
			Right[i] = pos;
		}
		
		init();
		
		for(int i=0; i<q; i++) {
			int s, t;
			scanf("%d %d", &s, &t);
			s--; t--;
			int res = 0;
			if(p[s] == p[t]) res = t-s+1;
			else {
				if(Right[s]+1<Left[t]-1) res = rmq(Right[s]+1, Left[t]-1);
				res = max(res, Right[s]-s+1);
				res = max(res, t-Left[t]+1);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}