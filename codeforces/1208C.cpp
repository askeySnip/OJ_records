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
int ans[1024][1024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  int cur = 0;
  REP(i, 0, n/2) {
    REP(j, 0, n/2) {
      ans[i][j] = 4 * cur + 1;
      ans[i][j + n/2] = 4 * cur + 2;
      ans[i + n/2][j] = 4 * cur + 3;
      ans[i + n/2][j + n/2] = 4 * cur;
      cur++;
    }
  }
  REP(i, 0, n) {
    REP(j, 0, n) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
