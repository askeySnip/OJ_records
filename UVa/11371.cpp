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


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s, ts;
  while(cin >> s) {
    ts = s;
    sort(ts.begin(), ts.end());
    sort(s.begin(), s.end(), greater<char>());
    if(s[0] == '0') swap(s[0], s.back());
    if(ts[0] == '0')
    REP(i, 0, ts.length()) {
      if(ts[i] != '0') {
        swap(ts[i], ts[0]);
        break;
      }
    }
    ll t = stoll(s);
    ll a = t - stoll(ts);
    cout << t << " - " << ts << " = " << a << " = 9 * " << a/9 << endl;
  }
  return 0;
}
