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
int n, m;
const int N = 2048;
int d[N], dx[N];
int l[N], r[N], s[N];
int res[N];
int nxt[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  memset(d, 0, sizeof d);

  for(int i=0; i<m; i++) {
    cin >> s[i] >> l[i] >> r[i];
    l[i]--, r[i]--;
    if(s[i] == 1) d[l[i]]++, d[r[i]]--;
  }
  int sum = 0;
  memset(dx, -1, sizeof dx);
  for(int i=0; i<n-1; i++) {    // to do the interval merge
    sum += d[i];
    if(sum > 0) dx[i] = 0;
  }

  res[0] = n;
  for(int i=1; i<n; i++) {
    res[i] = res[i-1] + dx[i-1];
  }
  nxt[n-1] = n-1;
  for(int i=n-2; i>=0; i--) {
    if(res[i] <= res[i+1]) nxt[i] = nxt[i+1];
    else nxt[i] = i;
  }

  for(int i=0; i<m; i++) {
    if(s[i] != (r[i] <= nxt[l[i]])) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for(int i=0; i<n; i++) {
    if(i) cout << " ";
    cout << res[i];
  }
  cout << endl;

  return 0;
}
