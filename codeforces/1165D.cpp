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
int d[330];

bool solve(ll x) {
  vector<ll> td;
  for(ll i=2; i*i<=x; i++) {
    if(x%i == 0) {
      td.push_back(i);
      if(i*i != x) td.push_back(x/i);
    }
  }
  sort(td.begin(), td.end());
  if((int)td.size() != n) return false;
  REP(i, 0, n) {
    if(td[i] != d[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    REP(i, 0, n) cin >> d[i];
    sort(d, d+n);
    ll x = (ll)d[0] * d[n-1];
    if(solve(x)) cout << x << endl;
    else cout << -1 << endl;
  }
  return 0;
}
