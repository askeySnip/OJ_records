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
	int n, m;
	int heads[20024], knights[20024];
	while(scanf("%d %d", &n, &m), n||m) {
		for(int i=0; i<n; i++) scanf("%d", &heads[i]);
		for(int j=0; j<m; j++) scanf("%d", &knights[j]);
		sort(heads, heads+n);
		sort(knights, knights+m);
		int ans = 0, j=0, i=0;
		for(; i<n; i++) {
			while(j<m && knights[j] < heads[i]) j++;
			if(j == m) break;
			ans += knights[j];
			j++;
		}
		if(i < n) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}
	return 0;
}