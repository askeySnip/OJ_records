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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, 0, n) {
    cin >> a[i];
    if(a[i] < 0) a[i] = -a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  REP(i, 0, n) {
    ans += upper_bound(a.begin(), a.end(), 2 * a[i]) - a.begin() - i - 1;
  }
  cout << ans << endl;
  return 0;
}
