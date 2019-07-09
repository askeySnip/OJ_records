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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
string s;
int n;
int d[20];

bool check(int div) {
  int t = 0;
  int len = s.length();
  REP(i, 0, len) {
    t = t*10+(s[i]-'0');
    t %= div;
  }
  return (t == 0);
}
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    cin >> s;
    cin >> n;
    REP(i, 0, n) {
      cin >> d[i];
    }
    bool flag = true;
    REP(i, 0, n) {
      if(!check(d[i])) {
        flag = false;
        break;
      }
    }
    if(flag) cout << s << " - Wonderful." << endl;
    else cout << s << " - Simple." << endl;
  }
  return 0;
}
