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
int a[300024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  REP(i, 0, n) cin >> a[i];
  vector<ll> s;
  ll cur = 0;
  for(int i=n-1; i>=0; i--) {
    cur += a[i];
    if(i>0) s.push_back(cur);
  }
  ll ans = cur;
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  for(int i=0; i<k-1; i++) {
    ans += s[i];
  }
  cout << ans << endl;
  return 0;
}
