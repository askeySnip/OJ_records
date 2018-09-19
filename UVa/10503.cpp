/*
ID: leezhen
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
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int n, m;
int a, b, c, d;
bool flag = false;
vii pieces;
int vist[20];

void dfs(int start, int cur) {
	if(cur == n) {
		if(start == c) flag = true;
		return;
	}
	for(int i=0; i<m; i++) {
		if(vist[i]) continue;
		if(pieces[i].first == start) {
			vist[i] = 1;
			dfs(pieces[i].second, cur+1);
			vist[i] = 0;
		}else if(pieces[i].second == start) {
			vist[i] = 1;
			dfs(pieces[i].first, cur+1);
			vist[i] = 0;
		}
	}
}
int main() {
	pieces.resize(20);
	while(scanf("%d", &n), n) {
		scanf("%d", &m);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(int i=0; i<m; i++) {
			scanf("%d %d", &a, &d);
			pieces[i] = make_pair(a, d);
		}
		memset(vist, 0, sizeof vist);
		flag = false;
		dfs(b, 0);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}