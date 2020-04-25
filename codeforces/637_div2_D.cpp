/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n, k;
vector<string> a;
vector<string> b{"1110111", "0010010", "1011101", "1011011", "0111010",
                 "1101011", "1101111", "1010010", "1111111", "1111011"};
bool f[2020][2020];
int get_k(int x, int y) {
  int ret = 0;
  for(int i=0; i<7; i++) {
    if(a[x][i] == b[y][i]) continue;
    if(a[x][i] == '1') return -1;
    else ret++;
  }
  return ret;
}

void solve() {
  memset(f, 0, sizeof f);
  f[n][0] = 1;
  for(int i=n-1; i>=0; i--) {
    for(int j=0; j<=k; j++) {
      for(int nm = 0; nm < 10; nm++) {
        int t = get_k(i, nm);
        if(t != -1 && t <= j) {
          f[i][j] = f[i][j] || f[i+1][j-t];
        }
      }
    }
  }
  string ans;
  if(!f[0][k]) {
    cout << "-1\n";
    return;
  }
  REP(i, 0, n) {
    for(int j=9; j>=0; j--) {
      int t = get_k(i, j);
      if(t != -1 && f[i+1][k-t]) {
        ans += (char)(j + '0');
        k-=t;
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  string s;
  REP(i, 0, n) {
    cin >> s;
    a.push_back(s);
  }
  solve();
  return 0;
}
