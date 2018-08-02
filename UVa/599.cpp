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
int graph[30][30];
int points[30];
int vist[30];
bool flag = true;
bool dfs(int v, int u) {
	vist[v] = -1;
	for(int i=0; i<26; i++) {
		if(!points[i] || i == u || vist[i] > 0) continue;
		if(graph[v][i]) {
			if(vist[i] == -1) {
				flag = false;
				cout << v << " " << i << endl;
				continue;
			}
			dfs(i, v);
		}
	}
	vist[v] = 1;
	return flag;
}
void solve() {
	memset(vist, 0, sizeof vist);
	int trees = 0, acorns = 0;
	for(int i=0; i<26; i++) {
		if(!points[i]) continue;
		int c = 0;
		for(int j=0; j<26; j++) {
			if(!points[j]) continue;
			if(graph[i][j]) c++;
		}
		if(!c) {
			acorns++;
			vist[i] = 1;
		}
	}
	for(int i=0; i<26; i++) {
		if(!points[i] || vist[i]) continue;
		flag = true;
		if(dfs(i, -1)) trees++;
	}
	printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
}
int main() {
	int k;
	scanf("%d", &k);
	char s[100];
	while(k--) {
		memset(graph, 0, sizeof graph);
		memset(points, 0, sizeof points);
		while(scanf("%s", s), s[0] != '*') {
			graph[s[1]-'A'][s[3]-'A'] = 1;
			graph[s[3]-'A'][s[1]-'A'] = 1;
		}
		scanf("%s", s);
		int len = strlen(s);
		for(int i=0; i<len; i+=2) {
			points[s[i]-'A'] = 1;
		}
		solve();
	}
	return 0;
}