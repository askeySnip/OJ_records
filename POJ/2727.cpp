#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int m, n, x, y;
char mp[23][23], vist[23][23];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int bfs(){
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(x, make_pair(y, 0)));
	while(!q.empty()){
		pair<int, pair<int, int> > t = q.front();
		q.pop();
		x = t.first;
		y = t.second.first;
		vist[x][y] = 1;
		int l = t.second.second;
		for(int i=0; i<4; i++){
			if(x+dr[i]>=0 && x+dr[i]<m && y+dc[i]>=0 && y+dc[i]<n){
				int tx = x + dr[i];
				int ty = y + dc[i];
				if(vist[tx][ty]) continue;
				if(mp[tx][ty] == '*') return l+1;
				if(mp[tx][ty] == '.') q.push(make_pair(tx, make_pair(ty, l+1)));
			}
		}
	}
	return -1;
}
int main() {
	while(cin >> m >> n){
		if(!m && !n) break;
		memset(vist, 0, sizeof(vist));
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin >> mp[i][j];
				if(mp[i][j] == '@'){
					x = i;
					y = j;
					mp[i][j] = '.';
				}
			}
		}
		cout << bfs() << endl;
	}
	return 0;
}