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
struct Node{
	int r, c, dir;
	Node(int a=0, int b=0, int d=0):r(a), c(b), dir(d){}
};
const char* dirs = "NESW";
const char* turns = "FLR";
inline int dir_id(char c) { return strchr(dirs, c) - dirs; }
inline int turn_id(char c) { return strchr(turns, c) - turns; }
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int d[13][13][5];
Node p[13][13][5];
Node Start, end_point;
int can_move[13][13][5][5];
Node walk(const Node& u, int turn){
	int dir = u.dir;
	if(turn == 1) dir = (dir+3)%4;
	if(turn == 2) dir = (dir+1)%4;
	return Node(u.r+dr[dir], u.c+dc[dir], dir);
}
void print_ans(Node u){
	vector<Node> nodes;
	for(;;){
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Start);
	
	int cnt = 0;
	for(int i=nodes.size()-1; i>=0; i--){
		if(cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if(++cnt % 10 == 0) printf("\n");
	}
	if(nodes.size()%10 != 0) printf("\n");
}
inline bool inside(int r, int c){
	return (r>0 && c>0);
}
void solve(){
	queue<Node> q;
	Node st = walk(Start, 0);
	q.push(st);
	memset(d, -1, sizeof(d));
	d[st.r][st.c][st.dir] = 0;
	while(!q.empty()){
		Node u = q.front(); q.pop();
		if(u.r == end_point.r && u.c == end_point.c) { print_ans(u); return; }
		for(int i=0; i<4; i++){
			Node v = walk(u, i);
			if(can_move[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}
int main() {
	string kase;
	while(cin >> kase && kase != "END"){
		cout << kase << endl;
		cin >> Start.r >> Start.c;
		char ch;
		cin >> ch >> end_point.r >> end_point.c;
		Start.dir = dir_id(ch);
		memset(can_move, 0, sizeof(can_move));
		int r, c;
		while(scanf("%d", &r)==1 && r){
			scanf("%d", &c);
			char s[10];
			while(scanf("%s", s) == 1 && s[0]!='*'){
				int t = strlen(s);
				int did = dir_id(s[0]);
				for(int i=1; i<t; i++){
					int tid = turn_id(s[i]);
					can_move[r][c][did][tid] = 1;
				}
			}
		}
		solve();
	}
	return 0;
}