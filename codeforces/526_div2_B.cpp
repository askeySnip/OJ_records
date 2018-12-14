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
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll n, s, sum = 0L, t, mint = inf;
  cin >> n >> s;
  REP(i, 0, n) {
    cin >> t;
    sum += t;
    mint = min(mint, t);
  }
  if(sum < s) cout << "-1" << endl;
  else {
    if(sum-mint*n >= s) cout << mint << endl;
    else {
      s -= (sum - mint*n);
      mint -= s / n;
      if(s%n) mint--;
      cout << mint << endl;
    }
  }
  return 0;
}
