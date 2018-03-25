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
int n;
char s[1030];
int G[30][30];
int color[30];
void dfs(int u){
	if(color[u]) return;
	color[u] = 1;
	int i;
	for(int i=0; i<26; i++){
		if(G[u][i]) dfs(i);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(G, 0, sizeof(G));
		int indeg[26]={}, outdeg[26]={};
		for(int i=0; i<n; i++){
			scanf("%s", s);
			int l = strlen(s);
			G[s[0]-'a'][s[l-1]-'a']++;
			outdeg[s[0]-'a']++;
			indeg[s[l-1]-'a']++;
		}
		int st, sn=0, ed, en = 0;
		int diff = 0;
		for(int i=0; i<26; i++){
			if(indeg[i]+1 == outdeg[i]){
				st = i; sn++;
			}else if(indeg[i] == outdeg[i]+1){
				ed = i; en++;
			}else if(indeg[i] != outdeg[i]) diff++;
		}
		memset(color, 0, sizeof(color));
		bool flag = true;
		if(sn == 1 && en == 1 && diff == 0){
			dfs(st);
			for(int i=0; i<26; i++){
				if(indeg[i] != 0 || outdeg[i] != 0){
					if(color[i] == 0)
						flag = false;
				}
			}
		}else if(sn == 0 && en == 0 && diff == 0){
			for(int i=0; i<26; i++){
				if(indeg[i])
					st = i;
			}
			dfs(st);
			for(int i=0; i<26; i++){
				if(indeg[i]!=0 || outdeg[i]!=0){
					if(color[i] == 0) flag = false;
				}
			}
		}else{
			flag = false;
		}
		if(flag){
			printf("Ordering is possible.\n");
		}else{
			printf("The door cannot be opened.\n");
		}
	}
	return 0;
}