// BEGIN CUT HERE

// END CUT HERE
#line 5 "Coastlines.cpp"
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

class Coastlines {
 public:
  int r, c;
  int vist[60][60];
  vector<vi> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int longest(vector<string> map) {
    r = map.size(), c = map[0].size();
    memset(vist, 0, sizeof vist);
    int ans = 0;
    REP(i, 0, r) {
      REP(j, 0, c) {
        if (!vist[i][j] && map[i][j] == 'X') {
          ans = max(ans, dfs(i, j, map));
        }
      }
    }
    return ans;
  }
  int dfs(int x, int y, vector<string> &map) {
    vist[x][y] = 1;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
      int tx = x + dir[i][0], ty = y + dir[i][1];
      if (tx >= 0 && tx < r && ty >= 0 && ty < c) {
        if (map[tx][ty] == '.')
          ret++;
        else if (map[tx][ty] == 'X' && !vist[tx][ty]) {
          ret += dfs(tx, ty, map);
        }
      } else
        ret++;
    }
    return ret;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
  }

 private:
  template <typename T>
  string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0() {
    string Arr0[] = {"...", ".X.", "..."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    verify_case(0, Arg1, longest(Arg0));
  }
  void test_case_1() {
    string Arr0[] = {".XX", ".X.", "..."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 8;
    verify_case(1, Arg1, longest(Arg0));
  }
  void test_case_2() {
    string Arr0[] = {"."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 0;
    verify_case(2, Arg1, longest(Arg0));
  }
  void test_case_3() {
    string Arr0[] = {".XX...", "XX...X", "X...XX", "......", ".XXXX."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 12;
    verify_case(3, Arg1, longest(Arg0));
  }
  void test_case_4() {
    string Arr0[] = {"XXX", "X.X", "XXX"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 16;
    verify_case(4, Arg1, longest(Arg0));
  }
  void test_case_5() {
    string Arr0[] = {"XXXXX", "X...X", "X.X.X", "X...X", "XXXXX"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 32;
    verify_case(5, Arg1, longest(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Coastlines ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
