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
int a[200024], b[200024], p[200024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, 1, n+1) {
    cin >> a[i];
    p[a[i]] = 0;
  }

  REP(i, 1, n+1) {
    cin >> b[i];
    p[b[i]] = i;
  }

  if(p[1]) {
    int i;
    for(i=2; p[i] == p[1] + i - 1; i++);
    if (p[i-1] == n) {
      int j;
      for(j = i; j<=n && p[j] <=j - i; j++);
      if(j > n) {
        cout << n - i + 1 << endl;
        return 0;
      }
    }
  }

  int ans = 0;
  REP(i, 1, n+1) ans = max(ans, p[i] - i + 1 + n);
  cout << ans << endl;
  return 0;
}
