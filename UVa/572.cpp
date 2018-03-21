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
int m, n;
char pic[130][130];
int idx[130][130];
void dfs(int i, int j, int id){
	if(i<0 || j < 0 || i>=m || j >=n) return;
	if(pic[i][j] != '@' || idx[i][j] != 0) return;
	idx[i][j] = id;
	for(int dr=-1; dr<=1; dr++){
		for(int dc=-1; dc<=1; dc++){
			if(dr != 0 || dc != 0) dfs(i+dr, j+dc, id);
		}
	}
	
}
int main() {
	while(scanf("%d%d", &m, &n) == 2 && m && n){
		for(int i=0; i<m; i++){
			scanf("%s", pic[i]);
		}
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(idx[i][j] == 0 && pic[i][j] == '@')
					dfs(i, j, ++cnt);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}