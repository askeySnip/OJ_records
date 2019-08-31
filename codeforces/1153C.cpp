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

bool check() {
  int cnt = 0;
  REP(i, 0, n) {
    if(s[i] == '(') cnt++;
    else cnt--;
    if(cnt < 0) return false;
    if(i < n-1 && cnt == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s;
  if(n%2) cout << ":(" << endl;
  else {
    int cnt1 = 0, cnt2 = 0;
    REP(i, 0, n) {
      if(s[i] == '(') cnt1++;
      else if(s[i] == ')') cnt2++;
    }
    if(cnt1 > n / 2 || cnt2 > n / 2) {
      cout << ":(" << endl;
      return 0;
    }
    cnt1 = n / 2 - cnt1;
    REP(i, 0, n) {
      if(s[i] == '?') {
        if(cnt1) {
          s[i] = '(';
          cnt1--;
        } else {
          s[i] = ')';
        }
      }
    }
    if(check()) cout << s << endl;
    else cout << ":(" << endl;
  }
  return 0;
}
