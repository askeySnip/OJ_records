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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  vi t(n), count(101, 0);
  REP(i, 0, n) {
    cin >> t[i];
  }
  REP(i, 0, n) {
    int d = sum + t[i] - m, k = 0;
    if(d > 0) {
      for(int j=100; j>0; j--) {
        int x = j * count[j];
        if(d <= x) {
          k += (d + j - 1) / j;
          break;
        }
        k += count[j];
        d -= x;
      }
    }
    sum += t[i];
    count[t[i]]++;
    cout << k << " ";
  }
  return 0;
}
