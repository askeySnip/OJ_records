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
const ll inf = 1e9;
const int mod = 1e9+7;

int n;
char g[60][60];

bool check() {
    int vist[60] = {0};
    for(int i=0; i<n; i++) {
        if(vist[i]) continue;
        for(int j=i+1; j<n; j++) {
            if(vist[j]) continue;
            bool f = true;
            for(int k=0; k<n; k++) {
                if(g[i][k] != g[j][k]) {f = false; break;}
            }
            if(f) {
                vist[i] = vist[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(!vist[i]) cnt++;
    }
    return cnt == 1;
}


void solve() {
    map<int, int> mp;
    REP(i, 0, n) {
        int cnt = 0;
        REP(j, 0, n) {
            if(g[i][j] == 'X') cnt++;
        }
        mp[cnt]++;
    }
    if(mp[1] != 1 || mp[2] + mp[1] != n) {
        printf("IMPOSSIBLE\n");
        return;
    }
    mp.clear();
    REP(i, 0, n) {
        int cnt = 0;
        REP(j, 0, n) {
            if(g[j][i] == 'X') cnt++;
        }
        mp[cnt]++;
    }
    if(mp[1] != 1 || mp[2] + mp[1] != n) {
        printf("IMPOSSIBLE\n");
        return;
    }
    bool f1 = check();
    REP(i, 0, n) {
        REP(j, 0, n) {
            swap(g[i][j], g[j][i]);
        }
    }
    bool f2 = check();
    if(!f1 || !f2) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("POSSIBLE\n");
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    // t = 1;
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%s", g[i]);
        printf("Case #%d: ", ++kase);
        solve();
    }
	return 0;
}

