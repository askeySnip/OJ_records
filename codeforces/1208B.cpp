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
int a[2048];
int ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i, 0, n) cin >> a[i];
  ans = n-1;
  map<int, int> mp;
  REP(i, 0, n) {
    bool f = true;
    REP(j, 0, i) {
      mp[a[j]]++;
      if(mp[a[j]] > 1) {
        f = false;
        break;
      }
    }
    if(!f) break;
    int t = n;
    for(int j=n-1; j>=i; j--) {
      mp[a[j]]++;
      if(mp[a[j]] == 1) t = j;
      else break;
    }
    ans = min(ans, t - i);
    mp.clear();
  }
  cout << ans << endl;
  return 0;
}
