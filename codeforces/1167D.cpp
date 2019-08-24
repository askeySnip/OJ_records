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
string s;
string ans;
stack<char> stk1, stk2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s;
  ans = "";
  REP(i, 0, s.length()) {
    if(s[i] == '(') {
      if(stk1.size() <= stk2.size()) {
        stk1.push('(');
        ans += '0';
      } else {
        stk2.push('(');
        ans += '1';
      }
    } else {
      if(stk1.size() >= stk2.size()) {
        stk1.pop();
        ans += '0';
      } else {
        stk2.pop();
        ans += '1';
      }
    }
  }
  cout << ans << endl;
  return 0;
}
