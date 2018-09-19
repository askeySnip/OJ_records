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

int t, n;
int x[20];
int c = 0;
int ans[20];
void dfs(int cur, int p, int s) {
	if(s > t || p > n) return;
	if(s == t) {
		for(int i=0; i<cur; i++) {
			if(i) printf("+");
			printf("%d", ans[i]);
		}
		printf("\n");
		c++;
		return;
	}
	ans[cur] = x[p];
	dfs(cur+1, p+1, s+x[p]);
	for(int i=p+1; i<n; i++) {
		if(ans[cur] == x[i]) continue;
		ans[cur] = x[i];
		dfs(cur+1, i+1, s+x[i]);
	}
}
int main() {
	while(scanf("%d %d", &t, &n), t || n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		c = 0;
		printf("Sums of %d:\n", t);
		dfs(0, 0, 0);
		if(c == 0) printf("NONE\n");
	}
	return 0;
}