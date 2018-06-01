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
int n, ans;
vii blocks;
char dir[4] = {'e', 'n', 's', 'w'};
int turn[4][2] = {
	{1, 2},
	{0, 3},
	{0, 3},
	{1, 2},
};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
vector<char> path;
map<pair<int, int>, int> mp;
bool check(int x, int y, int tx, int ty){
	int bx, by;
	for(int i=0; i<blocks.size(); i++){
		bx = blocks[i].first;
		by = blocks[i].second;
//		cout << bx << " " << by << endl;
		if(x == tx && x == bx){
			if(by>=min(y, ty) && by<=max(y, ty)) return false;
		}
		if(y == ty && y == by){
			if(bx>=min(x, tx) && bx<=max(x, tx)) return false;
		}
	}
	return true;
}
void dfs(int x, int y, int len, int d){
	int tx = x+dx[d]*len, ty = y+dy[d]*len;
	if(len == n){
		if(tx == 0 && ty == 0 && check(x, y, tx, ty)){
			ans++;
			for(int i=0; i<path.size(); i++){
				printf("%c", path[i]);
			}
			printf("%c\n", dir[d]);
		}
		return;
	}
	path.push_back(dir[d]);
	mp[make_pair(x, y)] = 1;
	if(check(x, y, tx, ty) && mp.find(make_pair(tx, ty)) == mp.end()){
		dfs(tx, ty, len+1, turn[d][0]);
		dfs(tx, ty, len+1, turn[d][1]);
	}
	mp.erase(mp.find(make_pair(x, y)));
	path.pop_back();
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		blocks.clear();
		mp.clear();
		ans = 0;
		int a;
		scanf("%d%d", &n, &a);
		int x, y;
		for(int i=0; i<a; i++){
			scanf("%d%d", &x, &y);
			blocks.push_back(make_pair(x, y));
		}
		for(int i=0; i<4; i++)
			dfs(0, 0, 1, i);
		printf("Found %d golygon(s).\n", ans);
		printf("\n");
	}
	return 0;
}