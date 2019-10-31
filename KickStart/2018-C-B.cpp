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
int l[16][16];
int vist[16];
vi choosed;
int ans;

bool check() {
    int mv = 0, sum = 0;
    REP(i, 0, choosed.size()) {
        mv = max(mv, choosed[i]);
        sum += choosed[i];
    }
    return mv < sum - mv;
}

void dfs(int u, int b) {
    if(u >= 3) {
        if(check()) ans++;

    }
    if(b == n) return;
    for(int i=b; i<n; i++) {
        if(vist[i]) continue;
        for(int j=i+1; j<n; j++) {
            if(vist[j] || l[i][j] == 0) continue;
            //cout << i << " " << j << " " << l[i][j] << endl;
            vist[i] = vist[j] = 1;
            choosed.push_back(l[i][j]);
            dfs(u+1, i+1);
            vist[i] = vist[j] = 0;
            choosed.pop_back();
        }
    }
}

int solve() {
    ans = 0;
    dfs(0, 0);
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) {
            REP(j, 0, n) {
                scanf("%d", &l[i][j]);
            }
        }
        printf("Case #%d: %d\n", ++kase, solve());
    }
	return 0;
}

