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
int m, n;
int t, s;
bitset<10024> bs[52];

bool check(int i, int j) {
  bitset<10024> tbs = bs[i];
  tbs&=bs[j];
  return tbs.any();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;
  REP(i, 0, m) {
    cin >> t;
    bs[i].reset();
    REP(j, 0, t) {
      cin >> s;
      bs[i][s] = 1;
    }
  }
  REP(i, 0, m) {
    REP(j, i+1, m) {
      if(!check(i, j)) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;

  return 0;
}
