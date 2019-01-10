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
const int mod = 1e9+7;

int n;
int a[10024];
int s[10024];
int yb, mb, db, yc, mc, dc;

inline int decode(int m, int d) {
	return s[m-1] + d;
}

void solve() {
	int bd = decode(mb, db);
	int cd = decode(mc, dc);
	ll ans = 0;
	if(bd > cd) {
		ans += s[n] - bd + cd +1;
		if(yb%4==0) ans++;
		yb++;
	}else ans += cd - bd + 1;
	//cout << ans << endl;
	int deta_y = yc - yb;
	ans += (s[n]*4+1) * (deta_y / 4);

	REP(i, 0, deta_y%4) {
		if((yb+i)%4 == 0) ans += s[n]+1;
		else ans += s[n];
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(s, 0, sizeof s);
		REP(i, 1, n+1) scanf("%d", &a[i]), s[i]=s[i-1] + a[i];
		scanf("%d %d %d", &yb, &mb, &db);
		scanf("%d %d %d", &yc, &mc, &dc);
		solve();
	}
	return 0;
}