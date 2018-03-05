#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int w, h;
char mp[23][23];
int vist[23][23];
int dc[4] = {0, 1, 0, -1};
int dr[4] = {-1, 0, 1, 0};
int dfs(int x, int y){
	if(vist[x][y] || mp[x][y]!='.') return 0;
	int ret = 1;
	vist[x][y] = 1;
	for(int i=0; i<4; i++){
		if(x+dc[i]>=0 && x+dc[i]<h && y+dr[i]>=0 && y+dr[i]<w){
			ret += dfs(x+dc[i], y+dr[i]);
		}
	}
	return ret;
}
int main() {
	while(cin >> w >> h){
		if(!w && !h) break;
		int x, y;
		memset(vist, 0, sizeof(vist));
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> mp[i][j];
				if(mp[i][j] == '@'){
					x = i;
					y = j;
					mp[i][j] = '.';
				}
			}
		}
		cout << dfs(x, y) << endl;
	}
	return 0;
}