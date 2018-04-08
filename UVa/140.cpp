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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int graph[30][30];
int vist[30];
int have[30];
char g[100];
int ans[10], tmp[10];
int node_n;
int k;
void build_graph(){
	node_n = 0;
	int len = strlen(g);
	for(int i=0; i<len;i++){
		int id = g[i]-'A';
		i+=2;
		have[id] = 1;
		while(i < len && g[i]!=';'){
			have[g[i]-'A'] = 1;
			graph[id][g[i]-'A'] = 1;
			graph[g[i]-'A'][id] = 1;
			i++;
		}
	}
	for(int i=0; i<30; i++){
		if(have[i]) node_n++;
	}
}
void dfs(int cur, int tk){
	if(cur == node_n && tk<k){
		for(int i=0; i<node_n; i++){
			ans[i] = tmp[i];
		}
		k = tk;
		return;
	}
	for(int i=0; i<27; i++){
		int ttk = tk;
		if(have[i] && !vist[i]){
			bool ok=true;
			for(int j=0; j<cur; j++){
				if(graph[i][tmp[j]]){
					if(cur-j>k) {ok=false; break;}
					if(ttk<cur-j) ttk=cur-j;
//					cout << ttk << endl;
				}
			}
			if(!ok) continue;
			tmp[cur] = i;
			vist[i] = 1;
			dfs(cur+1, ttk);
			vist[i] = 0;
		}
	}
}
int main() {
	while(scanf("%s", g), g[0]!='#'){
		memset(graph, 0, sizeof graph);
		memset(vist, 0, sizeof vist);
		memset(have, 0, sizeof have);
		memset(ans, 0, sizeof ans);
		memset(tmp, 0, sizeof tmp);
		build_graph();
		k = 10;
		for(int i=0; i<27; i++){
			if(have[i]){
				tmp[0] = i;
				vist[i] = 1;
				dfs(1, 0);
				vist[i] = 0;
			}
		}
		for(int i=0; i<node_n; i++){
			printf("%c ", ans[i]+'A');
		}
		printf("-> %d\n", k);
	}
	return 0;
}