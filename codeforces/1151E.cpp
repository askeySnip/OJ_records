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
int n;
int a[100024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, 1, n+1) cin >> a[i];
  a[0] = 0;
  ll ans = 0;
  REP(i, 1, n+1) {
    if(a[i] >= a[i-1]) ans += (ll)(a[i] - a[i-1]) * (n - a[i] + 1);
    else ans += (ll)a[i] * (a[i-1] - a[i]);
  }
  cout << ans << endl;
  return 0;
}
