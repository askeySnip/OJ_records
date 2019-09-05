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
int q;
const int N = 500024;
const int K = 750;
int sum[K][K];
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> q;
  int t, x, y;
  REP(i, 0, q) {
    cin >> t >> x >> y;
    if(t == 1) {
      a[x] += y;
      REP(j, 1, K) {
        sum[j][x % j] += y;
      }
    } else {
      if(x >= K) {
        int ans = 0;
        for(int j=y; j<=500000; j+=x) {
          ans += a[j];
        }
        cout << ans << endl;
      } else {
        cout << sum[x][y] << endl;
      }
    }
  }
  return 0;
}
