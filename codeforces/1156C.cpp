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
int n, z;
vi x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> z;
  x.resize(n);
  REP(i, 0, n) cin >> x[i];
  sort(x.begin(), x.end());
  int l = 0;
  int r = n / 2 + 1;
  while(l < r - 1) {
    int m = (l + r) / 2;
    bool f = true;
    REP(i, 0, m) {
      f &= (x[n-m+i] - x[i] >= z);
    }
    if(f) l = m;
    else r = m;
  }
  cout << l << endl;
  return 0;
}
