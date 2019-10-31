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

ll f, l;
ll cnt[20];
ll cnt2[20][160];

bool check(ll v) {
    string s = to_string(v);
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '9') return false;
    }
    return true;
}

ll getAns(ll e) {
    ll ret = e;
    if(e == 0) return 0;
    string s = to_string(e);
    int len = s.length();
    int cur = 0;
    REP(i, 0, len-1) {
        ret -= (s[i]-'0') * cnt[len - i - 2];
        for(int j=0; j<(s[i]-'0'); j++) {
            int k = 9;
            while(k - j < cur) k+=9;
            for(; k < 160; k+=9) {
                ret -= cnt2[len-i-2][k-j-cur];
            }
        }
        cur += s[i] - '0';
        if(s[i] == '9') {
            ret -= atoll(s.substr(i+1).c_str()) + 1;
            return ret;
        }
    }
    if(s[len-1] == '9') ret -= 1;
    for(int i=0; i<=min(s[len-1]-'0', 8); i++) {
        if((cur+i)%9 == 0) ret--;
    }
    if(cur == 0) ret++;
    return ret;
}

ll solve() {
    ll rt = getAns(l), lt = getAns(f - 1);
    // cout << rt << " " << lt << endl;
    return rt - lt;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    cnt[0] = 1; cnt[1] = 19;
    ll base = 100;
    for(int i=2; i<18; i++) {
        cnt[i] = cnt[i-1] * 10 + base - cnt[i-1];
        base *= 10;
    }
    memset(cnt2, 0, sizeof cnt2);
    for(int i=0; i<9; i++) cnt2[0][i] = 1;
    for(int i=1; i<18; i++) {
        for(int k=0; k<9; k++) {
            for(int j=0; j<160-k; j++) {
                cnt2[i][j+k] += cnt2[i-1][j];
            }
        }
    }
    while(t--) {
        scanf("%lld%lld", &f, &l);
        printf("Case #%d: %lld\n", ++kase, solve());
    }
	return 0;
}

