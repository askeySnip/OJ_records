/*
ID: leezhen1
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int n, ans = 0;
int graph[23][23];
int p[23];
int vist[23];
vi path;
int find(int t){
	if(p[t] == t){
		return t;
	}
	return p[t] = find(p[t]);
}
void link(int a, int b){
	p[a] = b;
}
bool check(){
	for(int i=1; i<23; i++){
		p[i] = i;
	}
	for(int i=1; i<23; i++){
		for(int j=1; j<23; j++){
			if(graph[i][j]){
				if(find(i) != find(j)){
					link(i, j);
				}
			}
		}
	}
	return find(1) == find(n);
}
void dfs(int st){
	if(st == n){
		for(int i=0; i<path.size(); i++){
			printf("%d ", path[i]);
		}
		printf("%d\n", st);
		ans++;
		return;
	}
	path.push_back(st);
	vist[st] = 1;
	for(int i=1; i<23; i++){
		if(graph[st][i] && !vist[i]){
			dfs(i);
		}
	}
	path.pop_back();
	vist[st] = 0;
}
void solve(){
	if(!check()){
		return;
	}
	dfs(1);
}
int main() {
	int kase = 0;
	while(scanf("%d", &n) == 1){
		memset(graph, 0, sizeof graph);
		memset(vist, 0, sizeof vist);
		ans = 0;
		int a, b;
		while(scanf("%d%d", &a, &b) == 2 && a && b){
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		printf("CASE %d:\n", ++kase);
		solve();
		printf("There are %d routes from the firestation to streetcorner %d.\n", ans, n);
	}
	return 0;
}