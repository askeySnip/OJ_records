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

int n, p;
int s[100024];
ll sm[100024];


int solve() {
    sort(s, s+n);
    REP(i, 0, n-1) {
        s[i] = s[i+1] - s[i];
    }
    sm[0] = s[0];
    for(int i=1; i<n-1; i++) {
        sm[i] = sm[i-1] + s[i];
    }
    int ans = 0;
    int c = 1;
    for(int i=0; i<p-1; i++) {
        ans += s[i] * c;
        c++;
    }
    int cur = ans - sm[p-2];
    for(int i=p-1; i<n-1; i++) {
        cur += s[i] * (p - 1);
        ans = min(ans, cur);
        cur -= sm[i] - sm[i-p+1];
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &p);
        REP(i, 0, n) scanf("%d", &s[i]);
        printf("Case #%d: %d\n", ++kase, solve());
    }
	return 0;
}

