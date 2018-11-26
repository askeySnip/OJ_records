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

int n;
set<ii> s;
vi edges[100000+3];
int vist[100000+3];
void dfs(int u) {
	vist[u] = 1;
	for(int i=0; i<edges[u].size(); i++) {
		int v = edges[u][i];
		if(u < v && s.find(ii(u, v)) == s.end()) {
			s.insert(ii(u, v));
		}else if(u > v && s.find(ii(v, u)) == s.end()) {
			s.insert(ii(v, u));
		}
		if(!vist[v]) dfs(v);
	}
}
int main() {
	scanf("%d", &n);
	memset(vist, 0, sizeof vist);
	for(int a=2; a<=n; a++) {
		for(int x = 2; x*a <=n; x++) {
			edges[a].push_back(x*a);
			edges[a*x].push_back(a);
		}
	}
	dfs(2);
	long long ans = 0;
	for(set<ii>::iterator it = s.begin(); it!=s.end(); it++) {
		ans += ((it->second / it->first) << 2);
	}
	printf("%lld\n", ans);
	return 0;
}