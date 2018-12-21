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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const ll mod = 998244353;

int n, m;
ll l, r;
vi edges[300024];
int vist[300024];
ll mem[300024];
void bfs(int u) {
	vist[u] = 1;
	queue<ii> q;
	int c[3] = {};
	q.push(ii(u, 1));
	c[1]++;
	while(!q.empty()) {
		ii p = q.front(); q.pop();
		REP(i, 0, edges[p.first].size()) {
			int v = edges[p.first][i];
			if(!vist[v]) {
				q.push(ii(v, 3-p.second));
				c[3-p.second]++;
				vist[v] = 3-p.second;
			}else {
				if(vist[v] == p.second) {
					l = 0; r = 0;
					return;
				}
			}
		}
	}
	l = c[1]; r = c[2];
}


int main() {
	int t;
	scanf("%d", &t);
	mem[0] = 1; mem[1] = 2;
	REP(i, 2, 300024) {
		mem[i] = (2L * mem[i-1])%mod;
		//cout << mem[i] << endl;
	}
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i=0; i<=n+1; i++) edges[i].clear();
		memset(vist, 0, sizeof vist);
		int a, b;
		REP(i, 0, m) {
			scanf("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		ll ans = 1L;
		REP(i, 1, n+1) {
			if(!vist[i]) {
				bfs(i);
				if(l == 0 && r == 0) {
					ans = 0L;
				}
				ans = (((mem[r]%mod + mem[l]%mod)%mod) * (ans%mod))%mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}