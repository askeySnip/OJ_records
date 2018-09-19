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

int n, k;
int graph[103][103];
int color[103], ans[103];
int maxval;

bool isOk(int u) {
	for(int i=1; i<=n; i++) {
		if(graph[u][i] && color[i]) return false;
	}
	return true;
}
void dfs(int u, int num) {
	if(u > n) {
		if(num > maxval) {
			maxval = num;
			memcpy(ans, color, sizeof ans);
		}
		return;
	}
	
	if(n-u+1+num <= maxval) return;
	if(isOk(u)) {
		color[u] = 1;
		dfs(u+1, num+1);
		color[u] = 0;
	}
	dfs(u+1, num);
}

int main() {
	int m;
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &n, &k);
		memset(graph, 0, sizeof graph);
		int a, b;
		for(int i=0; i<k; i++) {
			scanf("%d%d", &a, &b);
			graph[a][b] = graph[b][a] = 1;
		}
		maxval = -1;
		memset(color, 0, sizeof color);
		dfs(1, 0);
		
		printf("%d\n", maxval);
		int c = 0;
		for(int i=1; i<=n; i++) {
			if(ans[i]) {
				if(c) printf(" ");
				printf("%d", i);
				c++;
			}
		}
		printf("\n");
	}
	return 0;
}