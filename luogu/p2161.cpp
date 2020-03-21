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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct
struct plan {
  int l, r;
  bool operator<(const plan& o) const { return r < o.l; }
};

// data
set<plan> s;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  char c;
  int l, r;
  REP(i, 0, t) {
    cin >> c;
    if (c == 'A') {
      cin >> l >> r;
      plan tmp = (plan){l, r};
      int cnt = 0;
      auto it = s.find(tmp);
      while (it != s.end()) {
        s.erase(it);
        ++cnt;
        it = s.find(tmp);
      }
      s.insert(tmp);
      cout << cnt << "\n";
    } else {
      cout << s.size() << "\n";
    }
  }
  return 0;
}
