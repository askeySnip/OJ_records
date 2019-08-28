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
string s;
int cnt[26];

void print(vi& ans) {
  REP(i, 0, ans.size()) {
    REP(j, 0, cnt[ans[i]]) {
      cout << (char)(ans[i] + 'a');
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    REP(i, 0, s.length()) {
      cnt[s[i]-'a']++;
    }
    vi ex;
    REP(i, 0, 26) {
      if(cnt[i]) ex.push_back(i);
    }
    vi ans1, ans2;
    for(int i=0; i<(int)ex.size(); i+=2) {
      ans1.push_back(ex[i]);
    }
    for(int i=1; i<(int)ex.size(); i+=2) {
      ans2.push_back(ex[i]);
    }
    if(ans2.empty() || abs(ans1.back() - ans2[0]) != 1) {
      print(ans1);
      print(ans2);
      cout << endl;
    } else if(abs(ans1[0] - ans2.back()) != 1) {
      print(ans2);
      print(ans1);
      cout << endl;
    } else {
      cout << "No answer" << endl;
    }
  }
  return 0;
}
