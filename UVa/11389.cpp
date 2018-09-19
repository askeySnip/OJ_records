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
int main() {
	int n, d, r;
	int m[103], e[103];
	while(scanf("%d %d %d", &n, &d, &r), n||d||r) {
		for(int i=0; i<n; i++) scanf("%d", &m[i]);
		for(int i=0; i<n; i++) scanf("%d", &e[i]);
		sort(m, m+n); sort(e, e+n);
		int ans = 0;
		for(int i=0; i<n; i++) {
			int j = n-1-i;
			int t = m[i]+e[j]>d? m[i]+e[j]-d:0;
			ans += t*r;
		}
		printf("%d\n", ans);
	}
	return 0;
}