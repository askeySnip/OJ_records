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
int n, k, m, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> m >> t;
  vi multiverse(260000, 0);
  multiverse[k] = 1;
  int s = 1, e = n;
  int tp, pos;
  REP(i, 0, t) {
    cin >> tp >> pos;
    if(tp) {
      e++;
      if(pos <= k) {
        multiverse[k++] = 0;
        multiverse[k] = 1;
      }
      cout << e - s + 1 << " " << k << endl;
    } else {
      if(pos < k) {
        s = 1;
        e = e - pos;
        k = k - pos;
      } else {
        e = pos;
      }
      cout << e - s + 1 << " " << k << endl;
    }
  }
  return 0;
}
