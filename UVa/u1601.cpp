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
int w, h, n;
char mp[20][20];
vector<int> g[20][20];
int dr[] = {0, 1, 0, -1, 0};
int dc[] = {0, 0, 1, 0, -1};
void build_graph(){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(mp[i][j]!='#'){
				vector<int> v;
				for(int k=0; k<5; k++){
					int r = i+dr[k];
					int c = j+dc[k];
					if(r>=0 && c>=0 && r<h && c<w){
						if(mp[r][c] !='#') v.push_back(k);
					}
				}
				g[i][j] = v;
			}
		}
	}
}
void solve(){
	
}
int main() {
	while(scanf("%d%d%d", &w, &h, &n), (w||h||n)){
		for(int i=0; i<h; i++){
			scanf("%s", mp[i]);
		}
		build_graph();
		solve();
	}
	return 0;
}