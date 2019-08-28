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
deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  int a;
  REP(i, 0, n) {
    cin >> a;
    dq.push_back(a);
  }
  int cur = 0;
  string ans;
  while(!dq.empty()) {
    if(dq.front() > dq.back()) {
      if(dq.back() > cur) {
        cur = dq.back();
        dq.pop_back();
        ans.push_back('R');
      } else if(dq.front() > cur) {
        cur = dq.front();
        dq.pop_front();
        ans.push_back('L');
      } else {
        break;
      }
    } else if(dq.front() < dq.back()) {
      if(dq.front() > cur) {
        cur = dq.front();
        dq.pop_front();
        ans.push_back('L');
      } else if(dq.back() > cur) {
        cur = dq.back();
        dq.pop_back();
        ans.push_back('R');
      } else {
        break;
      }
    } else {
      if(dq.front() <= cur) break;
      vi poped;
      int tcur = cur;
      int cnt1 = 0, cnt2 = 0;
      while(!dq.empty()) {
        if(tcur >= dq.back()) break;
        tcur = dq.back();
        dq.pop_back();
        poped.push_back(tcur);
        cnt1++;
      }
      if(dq.empty()) {
        REP(i, 0, cnt1) ans.push_back('R');
        break;
      }
      while(!poped.empty()) {
        dq.push_back(poped.back());
        poped.pop_back();
      }
      tcur = cur;
      while(!dq.empty()) {
        if(tcur >= dq.front()) break;
        tcur = dq.front();
        dq.pop_front();
        poped.push_back(tcur);
        cnt2++;
      }
      if(cnt1 > cnt2) {
        REP(i, 0, cnt1) ans.push_back('R');
      } else {
        REP(i, 0, cnt2) ans.push_back('L');
      }
      break;
    }
  }
  cout << ans.length() << endl;
  cout << ans << endl;
  return 0;
}
