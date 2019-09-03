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
string s, t;
int c[3][3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s >> t;
  REP(i, 0, 3) {
    REP(j, 0, 3) {
      c[i][j] = 1;
    }
  }
  c[s[0]-'a'][s[1]-'a'] = 0;
  c[t[0]-'a'][t[1]-'a'] = 0;
  bool f = false;
  REP(i, 0, 3) {
    if(c[i][i]==0) f = true;
  }
  REP(i, 0, 3) {
    REP(j, 0, 3) {
      if(j == i) continue;
      REP(k, 0, 3) {
        if(k == i || k == j) continue;
        if(c[i][j] && c[j][k] && !f) {
          cout << "YES" << endl;
          REP(l, 0, n) {
            cout << (char)(i+'a');
          }
          REP(l, 0, n) {
            cout << (char)(j+'a');
          }
          REP(l, 0, n) {
            cout << (char)(k+'a');
          }
          cout << endl;
          return 0;
        }
        if(c[i][j] && c[j][k] && f && c[k][i]) {
          cout << "YES" << endl;
          REP(l, 0, n) {
            cout << (char)(i+'a') << (char)(j+'a') << (char)(k+'a');
          }
          cout << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
