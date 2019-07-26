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
ll a[100024];

ll up(int a) {
  if(a > 0) {
    return (a + 99999) / 100000 * 100000;
  }
  return a / 100000 * 100000;
}

ll down(int a) {
  if(a > 0) {
    return a / 100000 * 100000;
  }
  return (a - 99999) / 100000 * 100000;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  double t;

  for(int i=0; i<n; i++) {
    cin >> t, a[i] = (ll)(t * 100000);
  }
  ll sum = 0L;
  for(int i=0; i<n; i++) {
    sum += a[i] / 100000;
  }
  if(sum > 0) {
    for(int i=0; i<n; i++) {
      if(sum == 0) cout << a[i] / 100000 << endl;
      else {
        if(down(a[i]) / 100000 - a[i] / 100000 == -1) {
          sum--;
          cout << down(a[i]) / 100000 << endl;
        } else {
          cout << a[i] / 100000 << endl;
        }
      }
    }
  } else {
    for(int i=0; i<n; i++) {
      if(sum == 0) cout << a[i] / 100000 << endl;
      else {
        if(up(a[i]) / 100000 - a[i] / 100000 == 1) {
          sum ++;
          cout << up(a[i]) / 100000 << endl;
        } else {
          cout << a[i] / 100000 << endl;
        }
      }
    }
  }
  return 0;
}
