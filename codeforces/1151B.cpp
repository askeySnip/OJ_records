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
int a[520][520];

void print_ans(vi& ans) {
  cout << "TAK" << endl;
  REP(i, 0, n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  REP(i, 0, n) {
    REP(j, 0, m) {
      cin >> a[i][j];
    }
  }
  vi ans(n, 1);
  int cur = a[0][0];
  REP(i, 1, n) {
    cur ^= a[i][0];
  }
  if(cur) print_ans(ans);
  else {
    REP(i, 0, n) {
      REP(j, 1, m) {
        if(a[i][j] != a[i][0]) {
          ans[i] = j + 1;
          print_ans(ans);
          return 0;
        }
      }
    }
    cout << "NIE" << endl;
  }
  return 0;
}
