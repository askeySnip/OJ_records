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
const int maxn = 1030;

int n;
int pos[maxn];
vector<int> g[maxn];

int main() {
	while(scanf("%d", &n) == 1){
		int t;
		for(int i=1; i<=n; i++){
			scanf("%d", &t);
			g[i].clear();
			pos[t] = i;
		}
		
		int root;
		stack<int> stak;
		scanf("%d", &root);
		stak.push(root);
		for(int i=1; i<n; i++){
			scanf("%d", &t);
			while (true) {
				int u = stak.top();
				
				if(u == root || pos[u] + 1 < pos[t]){
					
					g[u].push_back(t);
					stak.push(t);
					break;
				}else{
					stak.pop();
				}
			}
		}
		
		for(int i=1; i<=n; i++){
			printf("%d:", i);
			for(int j=0; j<g[i].size(); j++)
				printf(" %d", g[i][j]);
			printf("\n");
		}
	}
	return 0;
}