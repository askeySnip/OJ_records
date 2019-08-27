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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n, u, mx;
int f[100024], cnt[100024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  int ans = 0;
  REP(i, 1, n+1) {
    cin >> u;
    cnt[f[u]]--;
    f[u]++;
    cnt[f[u]]++;
    mx = max(mx, f[u]);
    bool ok = false;
    if(cnt[1] == i) ok = true;
    else if(cnt[i] == 1) ok = true;
    else if(cnt[1] == 1 && cnt[mx] * mx == i - 1) ok = true;
    else if(cnt[mx-1] * (mx-1) == i-mx && cnt[mx] == 1) ok = true;
    if(ok) ans = i;
  }
  cout << ans << endl;
  return 0;
}
