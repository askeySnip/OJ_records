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
int n, x;
int a[1000024];
vi pos[1000024];
int prefMax[1000024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> x;
  REP(i, 0, n) {
    cin >> a[i];
    pos[a[i]].push_back(i);
    prefMax[i] = max(a[i], (i > 0 ? prefMax[i-1] : a[i]));
  }

  int p = 1;
  int lst = n + 5;
  for(int i=x; i>=1; i--) {
    if(pos[i].empty()) {
      p = i;
      continue;
    }
    if(pos[i].back() > lst) break;
    p = i;
    lst = pos[i][0];
  }

  long long res = 0;
  lst = -1;
  REP(l, 1, x+1) {
    int r = max(l, p - 1);
    if(lst != -1) r = max(r, prefMax[lst]);
    res += x - r + 1;
    if(!pos[l].empty()) {
      if(pos[l][0] < lst) break;
      lst = pos[l].back();
    }
  }
  cout << res << endl;
  return 0;
}
