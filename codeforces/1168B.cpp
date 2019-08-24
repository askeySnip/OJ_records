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
  string s;
  cin >> s;
  ll ans = 0;
  int n = s.length();
  int last = n;
  for(int i=n-1; i>=0; i--) {
    int cur = last;
    for(int k=1; i + 2 * k < cur; k++) {
      if(s[i] == s[i+k] && s[i+k] == s[i+2*k]) {
        cur = i + 2 * k;
      }
    }
    ans += n - cur;
    last = cur;
  }
  cout << ans << endl;
  return 0;
}
