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
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int n;
vi e[1024];
vi paths;
int color[1024];
bool f;
vi c;


void set_circle(int v) {
    c.clear();
    while(paths.back() != v) {
        c.push_back(paths.back());
        paths.pop_back();
    }
    c.push_back(v);
    paths = c;
}

void dfs(int v, int p) {
    color[v] = 1;
    paths.push_back(v);
    for(int i = 0; i < e[v].size(); i++) {
        if(f) return;
        if(e[v][i] == p) continue;
        if(color[e[v][i]] == 1) {
            f = true;
            set_circle(e[v][i]);
            return;
        }
        dfs(e[v][i], v);
    }
    color[v] = 2;
    paths.pop_back();
}

ll solve() {
    paths.clear();
    memset(color, 0, sizeof color);
    f = false;
    dfs(1, -1);
    queue<ii> q;
    vi dist(n+1, -1);
    for(int i=0; i<c.size(); i++) {
        q.push(ii(c[i], 0));
        dist[c[i]] = 0;
    }
    while(!q.empty()) {
        ii p = q.front(); q.pop();
        REP(i, 0, e[p.first].size()) {
            int v = e[p.first][i];
            if(dist[v] == -1) {
                dist[v] = p.second + 1;
                q.push(ii(v, dist[v]));
            }
        }
    }

    for(int i=1; i<=n; i++) {
        printf(" %d", dist[i]);
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    int x, y;
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, 1024) e[i].clear();
        REP(i, 0, n) {
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        //cout << " a " << endl;
        printf("Case #%d:", ++kase);
        solve();
        printf("\n");
    }
	return 0;
}

