/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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

using namespace std;
int n, m;
int G[130][130];
int topo[130], color[130];
int cnt;
bool dfs(int u){
	color[u] = -1;
	for(int i=1; i<=n; i++){
		if(G[u][i]){
			if(color[i] < 0) return false;
			else if(!color[i] && !dfs(i)) return false;
		}
	}
	color[u] = 1;
	topo[--cnt] = u;
	return true;
}
bool toposort(){
	cnt = n;
	memset(color, 0, sizeof(color));
	for(int i=1; i<=n; i++){
		if(!color[i]) if(!dfs(i)) return false;
	}
	return true;
}
void print_ans(){
	printf("%d", topo[0]);
	for(int i=1; i<n; i++){
		printf(" %d", topo[i]);
	}
	printf("\n");
}
int main() {
	while(scanf("%d%d", &n, &m) == 2 && !(n==0 && m==0)){
		int a, b;
		memset(G, 0, sizeof(G));
		for(int i=0; i<m; i++){
			scanf("%d%d", &a, &b);
			G[a][b] = 1;
		}
		if(toposort()){
			print_ans();
		}
	}
	return 0;
}