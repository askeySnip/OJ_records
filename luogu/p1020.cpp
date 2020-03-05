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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  vi h;
  int x;
  while (scanf("%d", &x) == 1) {
    h.push_back(x);
  }
  if (h.empty()) {
    printf("0\n0\n");
    return 0;
  }
  reverse(h.begin(), h.end());
  vi stk;
  stk.push_back(h[0]);
  multiset<int> ans;
  ans.insert(h[0]);
  REP(i, 1, h.size()) {
    if (h[i] >= stk.back()) {
      stk.push_back(h[i]);
      auto it = ans.upper_bound(h[i]);
      it--;
      ans.erase(it);
      ans.insert(h[i]);
    } else {
      int idx = upper_bound(stk.begin(), stk.end(), h[i]) - stk.begin();
      stk[idx] = h[i];
      if (h[i] < *ans.begin())
        ans.insert(h[i]);
      else {
        auto it = ans.upper_bound(h[i]);
        it--;
        ans.erase(it);
        ans.insert(h[i]);
      }
    }
  }
  printf("%d\n", (int)stk.size());
  printf("%d\n", (int)ans.size());
  return 0;
}