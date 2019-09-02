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
const int mod = 1e9 + 7;
ll l, r;

ll getsum(ll n) {
  if(n == 0) return 0;
  int i;
  for(i=0; i<63; i++) {
    if((ll)1 << i >= n + 1) break;
  }
  ll f = 0, s = 0;
  if((ll)1 << i > n+1) {
    if(i%2 == 0) {
      s += n - ((ll)1 << (i-1)) + 1;
    } else {
      f += n - ((ll)1 << (i-1)) + 1;
    }
    i--;
  }
  for(int j = 0; j<i; j++) {
    if(j%2) s+=((ll)1 << j);
    else f += ((ll)1 << j);
  }
  ll fs = (f%mod) * (f%mod);
  fs%=mod;
  // cout << "fs " << fs << endl;
  ll ss = ((1 + s)%mod) * (s%mod);
  ss%=mod;
  // cout << "ss " << ss << endl;
  return (fs + ss)%mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> l >> r;
  ll ll = getsum(l-1), rr = getsum(r);
  // cout << ll << " " << rr << endl;
  if(rr < ll) rr += mod;
  cout << rr - ll << endl;
  return 0;
}
