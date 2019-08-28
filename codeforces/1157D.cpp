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
int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  if((ll)(k+1) * k / 2 > n) {
    cout << "NO" << endl;
    return 0;
  }
  vi ans;
  int d = n - (int)((ll)(k+1)*k/2);
  int cur = 1;
  if(d >= k) {
    int t = d / k;
    d -= t * k;
    cur+=t;
  }
  ans.push_back(cur);
  REP(i, 1, k) {
    cur++;
    if(d >= k-i) {
      int t = min(ans.back()-1, d / (k - i));
      d -= t * (k - i);
      cur += t;
    }
    ans.push_back(cur);
  }
  if(d > 0) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    REP(i, 0, k) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
