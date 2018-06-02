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
int n, cn;
int g[20][20], vist[20];
bool two(int s){
	for(int i=0; i<n; i++){
		if(s&(1<<i)) continue;
		int num = 0;
		for(int j=0; j<n; j++){
			if(s & (1<<j)) continue;
			if(g[i][j]) num++;
		}
		if(num > 2) return true;
	}
	return false;
}
bool dfs(int s, int now, int fa){
	vist[now] = 1;
	for(int i=0; i<n; i++){
		if(!g[now][i] || s&(1<<i) || i == fa) continue;
		if(vist[i]) return true;
		if(dfs(s, i, now)) return true;
	}
	return false;
}
bool circle(int s){
	for(int i=0; i<n; i++){
		if(s&(1<<i) || vist[i]) continue;
		cn++;
		if(dfs(s, i, -1)) return true;
	}
	return false;
}
int cal(int s){
	return s == 0? 0:cal(s/2)+(s&1);
}
int solve(){
	int ans = (1 << 28);
	int s = (1 << n);
	for(int i=0; i<s; i++){
		cn = 0;
		memset(vist, 0, sizeof vist);
		if(two(i) || circle(i)) continue;
		int t = cal(i);
		if(t >= cn-1){
			ans = min(t, ans);
		}
	}
	return ans;
}
int main() {
	int kase = 0;
	while(scanf("%d", &n) == 1 && n){
		int a, b;
		memset(g, 0, sizeof g);
		while(scanf("%d%d", &a, &b) == 2 && a>0 && b>0){
			g[a-1][b-1] = g[b-1][a-1] = 1;
		}
		printf("Set %d: Minimum links to open is %d\n", ++kase, solve());
	}
	return 0;
}