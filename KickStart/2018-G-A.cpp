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
int a[7100];
map<int, int> cnt;

ll solve() {
    ll ans = 0;
    // sort(a, a+n);
    cnt.clear();
    REP(i, 0, n) {
        cnt[a[i]]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++) {
        if(it->first <= 1) continue;
        int up = sqrt(it->first);
        for(int i=2; i<=up; i++) {
            if(it->first%i == 0) {
                int b = it->first/i;
                if(i != b) ans += (ll)it->second * cnt[i] * cnt[b];
                else ans += (ll)it->second * cnt[i] * (cnt[i] - 1) /2;
            }
        }
        ans += (ll)cnt[1] * it->second * (it->second - 1)/2;
    }
    int zeros = cnt[0], ones = cnt[1];
    ans += (ll)zeros * (zeros - 1) * (zeros - 2) / 6 + (ll)zeros * (zeros - 1) / 2 * (n - zeros);
    ans += (ll)ones * (ones - 1) * (ones - 2) / 6;
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", &a[i]);
        printf("Case #%d: %lld\n", ++kase, solve());
        //solve();
    }
	return 0;
}

