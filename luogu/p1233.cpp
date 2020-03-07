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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n;
ii lw[5010];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d%d", &lw[i].first, &lw[i].second);
  sort(lw, lw + n, [](ii a, ii b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  });
  set<int> s;
  REP(i, 0, n) {
    if (s.empty())
      s.insert(lw[i].second);
    else {
      auto it = s.lower_bound(lw[i].second);
      if (it == s.end()) {
        s.insert(lw[i].second);
      } else {
        s.erase(it);
        s.insert(lw[i].second);
      }
    }
  }
  printf("%d\n", (int)s.size());
  return 0;
}
