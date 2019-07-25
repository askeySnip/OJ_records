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
ll n, m, k;
ll v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  ll cur = k, cnt = 0L, ans = 0L;
  for(ll i=0; i<m; i++) {
    cin >> v;
    if(cur < v) {
      cur += cnt;
      if(cur < v) {
        cur += (v - cur + k - 1) / k * k; // 应该为 v - cur / k 向上取整向上取整则可以加上除数k-1
      }
      if(cnt) ans++;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
