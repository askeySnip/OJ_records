// BEGIN CUT HERE

// END CUT HERE
#line 5 "Tunnel.cpp"
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

class Tunnel {
 public:
  int minKeystrokes(vector<string> level, int rate) {
    int r = level.size(), c = level[0].size();
    vector<int> dp(c, inf), tmp(c, inf);
    REP(i, 0, c) if (level[0][i] == 'v') { dp[i] = 0; }
    REP(i, 0, c) {
      if (level[0][i] == '#') continue;
      tmp[i] = dp[i];
      for (int j = i - 1; j >= max(0, i - rate); j--) {
        if (level[0][j] == '#') break;
        tmp[i] = min(tmp[i], dp[j] + i - j);
      }
      for (int j = i + 1; j < min(c, i + rate + 1); j++) {
        if (level[0][j] == '#') break;
        tmp[i] = min(tmp[i], dp[j] + j - i);
      }
    }
    dp = tmp;
    fill(tmp.begin(), tmp.end(), inf);
    REP(k, 1, r) {
      REP(i, 0, c) {
        if (level[k][i] == '#') continue;
        tmp[i] = dp[i];
        for (int j = i - 1; j >= max(0, i - rate); j--) {
          if (level[k][j] == '#') break;
          tmp[i] = min(tmp[i], dp[j] + i - j);
        }
        for (int j = i + 1; j < min(c, i + rate + 1); j++) {
          if (level[k][j] == '#') break;
          tmp[i] = min(tmp[i], dp[j] + j - i);
        }
      }
      dp = tmp;
      fill(tmp.begin(), tmp.end(), inf);
    }
    int ans = inf;
    REP(i, 0, c) { ans = min(ans, dp[i]); }
    if (ans == inf) return -1;
    return ans;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
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
    string Arr0[] = {"##..v..##", "###.....#", "#####...#", "####...##",
                     "###..####", "#.......#", "#...#####"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arg2 = 3;
    verify_case(0, Arg2, minKeystrokes(Arg0, Arg1));
  }
  void test_case_1() {
    string Arr0[] = {"#.v.#", "##..#", "###.#", "#...#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 0;
    int Arg2 = -1;
    verify_case(1, Arg2, minKeystrokes(Arg0, Arg1));
  }
  void test_case_2() {
    string Arr0[] = {"#v....#", "###...#", "#####.#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    int Arg2 = -1;
    verify_case(2, Arg2, minKeystrokes(Arg0, Arg1));
  }
  void test_case_3() {
    string Arr0[] = {"#v....#", "###...#", "#####.#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arg2 = 4;
    verify_case(3, Arg2, minKeystrokes(Arg0, Arg1));
  }
  void test_case_4() {
    string Arr0[] = {"#...v.#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 47;
    int Arg2 = 0;
    verify_case(4, Arg2, minKeystrokes(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Tunnel ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
