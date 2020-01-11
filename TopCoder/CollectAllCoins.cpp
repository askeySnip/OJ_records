// BEGIN CUT HERE

// END CUT HERE
#line 5 "CollectAllCoins.cpp"
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class CollectAllCoins {
 public:
  vector<vi> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<int> collect(int R, int C) {
    if (R % 2 == 0 && C % 2 == 0) return {};
    vector<vi> grid(R, vi(C, 2));
    grid[0][0] = 1;
    set<ii> s;
    s.insert({0, 0});
    vi ans;
    dfs(grid, s, ans);
    if (ans.size() < R * C) return {};
    return ans;
  }
  void dfs(vector<vi>& grid, set<ii>& s, vi& ans) {
    if (s.empty()) return;
    ii p = *s.begin();
    ans.push_back(p.first * grid[0].size() + p.second);
    grid[p.first][p.second] = 0;
    s.erase(s.begin());
    for (int i = 0; i < 4; i++) {
      int x = p.first + dir[i][0], y = p.second + dir[i][1];
      if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
          grid[x][y]) {
        grid[x][y] = 3 - grid[x][y];
        if (grid[x][y] == 1)
          s.insert({x, y});
        else
          s.erase({x, y});
      }
    }
    dfs(grid, s, ans);
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
  }

 private:
  template <typename T>
  string print_array(const vector<T>& V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const vector<int>& Expected,
                   const vector<int>& Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 3;
    int Arg1 = 3;
    int Arr2[] = {0, 3, 4, 6, 5, 2, 8, 7, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, collect(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 7;
    int Arg1 = 1;
    int Arr2[] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, collect(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 2;
    int Arg1 = 3;
    int Arr2[] = {0, 1, 2, 3, 5, 4};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, collect(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 14;
    int Arg1 = 28;
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(3, Arg2, collect(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CollectAllCoins ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
