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
char wall[5000010];

int solve() {
    int ans = 0;
    int s = 0;
    for(int i=0; i<(n+1)/2; i++) {
        s += (wall[i] - '0');
    }
    ans = max(ans, s);
    int j = 0;
    for(int i=(n+1)/2; i<n; i++) {
        s += (wall[i] - '0');
        s -= (wall[j] - '0');
        j++;
        ans = max(ans, s);
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%s", wall);
        printf("Case #%d: %d\n", ++kase, solve());
        //solve();
    }
	return 0;
}

