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
int h, w;
const int maxh = 230;
const int maxw = 230;
char line[maxw];
int pic[maxh][maxw], color[maxh][maxw];
map<char, string> m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
vector<set<int> > neighbors;
const char* code = "WAKJSD";

void decode(char ch, int r, int c){
	string s = m[ch];
	for(int i=0; i<4; i++){
		pic[r][c+i] = s[i] - '0';
	}
}
void dfs(int r, int c, int id){
	color[r][c] = id;
	for(int i=0; i<4; i++){
		int tr = r+dr[i], tc = c+dc[i];
		if(tr>=0 && tr<h && tc>=0 && tc<w && !color[tr][tc] && pic[tr][tc] == pic[r][c]) dfs(tr, tc, id);
	}
}

void checkNeighbors(int r, int c){
	for(int i=0; i<4; i++){
		int tr = r+dr[i], tc = c+dc[i];
		if(tr>=0 && tr < h && tc>=0 && tc<w && pic[tr][tc] == 0 && color[tr][tc] != 1) neighbors[color[r][c]].insert(color[tr][tc]);
	}
}
char recognize(int id){
	int t = neighbors[id].size();
	return code[t];
}
int main() {
	m['0'] = "0000";
	m['1'] = "0001";
	m['2'] = "0010";
	m['3'] = "0011";
	m['4'] = "0100";
	m['5'] = "0101";
	m['6'] = "0110";
	m['7'] = "0111";
	m['8'] = "1000";
	m['9'] = "1001";
	m['a'] = "1010";
	m['b'] = "1011";
	m['c'] = "1100";
	m['d'] = "1101";
	m['e'] = "1110";
	m['f'] = "1111";
	int kase = 0;
	while(scanf("%d%d", &h, &w)==2 && h){
		memset(pic, 0, sizeof(pic));
		for(int i=0; i<h; i++){
			scanf("%s", line);
			for(int j=0; j<w; j++){
				decode(line[j], i+1, j*4+1);
			}
		}
		h += 2;
		w = w*4+2;
		int cnt = 0;
		vector<int> bc;
		memset(color, 0, sizeof(color));
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!color[i][j]){
					dfs(i, j, ++cnt);
					if(pic[i][j] == 1){
						bc.push_back(cnt);
					}
				}
			}
		}
		neighbors.clear();
		neighbors.resize(cnt+1);
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(pic[i][j] == 1){
					checkNeighbors(i, j);
				}
			}
		}
		vector<char> ans;
		for(int i=0; i<bc.size(); i++){
			ans.push_back(recognize(bc[i]));
		}
		sort(ans.begin(), ans.end());
		printf("Case %d: ", ++kase);
		for(int i=0; i<ans.size(); i++){
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}