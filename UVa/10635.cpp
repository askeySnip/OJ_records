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

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int a[260 * 260], b[260 * 260];
// int dp[260 * 260];
map<int, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    int n, p, q;
    scanf("%d %d %d\n", &n, &p, &q);
    REP(i, 1, p+2) scanf("%d", &a[i]);
    REP(i, 1, q+2) scanf("%d", &b[i]);
    mp.clear();
    REP(i, 1, p+2) mp[a[i]] = i;
    int c = 1;
    REP(i, 1, q+2) {
      if(mp.find(b[i]) != mp.end()) {
        b[c++] = mp[b[i]];
      }
    }
    vi inc;
    REP(i, 1, c) {
      vector<int>::iterator it = lower_bound(inc.begin(), inc.end(), b[i]);
      if(it == inc.end()) inc.push_back(b[i]);
      else *it = b[i];
    }
    // memset(dp, 0, sizeof dp);
    // REP(i, 1, p+2) {
    //   REP(j, 1, q+2) {
    //     if(a[i] == b[j]) dp[j] = dp[j-1] + 1;
    //     else dp[j] = max(dp[j], dp[j-1]);
    //     // cout << dp[cur][j] << " ";
    //   }
    //   // cout << endl;
    // }
    // printf("Case %d: %d\n", ++kase, dp[q+1]);
    printf("Case %d: %d\n", ++kase, (int)inc.size());
  }
  return 0;
}
