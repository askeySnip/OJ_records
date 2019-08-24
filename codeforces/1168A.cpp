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
int a[300024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >>  n >> m;
  REP(i, 0, n) cin >> a[i];
  int l = -1, h = m;
  while(l < h - 1) {
    int mid = (l + h) / 2;
    int prev = 0;
    bool bad = false;
    for(int i=0; i<n; i++) {
      int lf = a[i], rf = a[i] + mid;
      if((lf <= prev && prev <= rf) || (lf <= prev + m && prev+m <= rf)) continue;
      if(lf < prev) {
        bad = true;
        break;
      } else {
        prev = lf;
      }
    }
    if(bad) l = mid;
    else h = mid;
  }
  cout << h << endl;
  return 0;
}
