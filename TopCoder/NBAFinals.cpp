// BEGIN CUT HERE

// END CUT HERE
#line 5 "NBAFinals.cpp"
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

class NBAFinals {
 public:
  int dubsAgain(vector<int> scores, string team) {
    int n = scores.size();
    int w = 0, r = 0;
    REP(i, 0, n) {
      if (scores[i] == 0) {
        if (team[i] == 'W')
          w += 4;
        else if (team[i] == 'R')
          r += 1;
        else
          w += 4;
      } else {
        if (team[i] != 'R')
          w += scores[i];
        else
          r += scores[i];
      }
    }
    return (w > r);
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
    if ((Case == -1) || (Case == 6)) test_case_6();
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
    int Arr0[] = {2, 2, 3, 3, 2, 4, 2};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "RRWWRWR";
    int Arg2 = 1;
    verify_case(0, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {2, 2, 3, 3, 2, 3, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "RRWWRWR";
    int Arg2 = 0;
    verify_case(1, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {0, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "WR";
    int Arg2 = 1;
    verify_case(2, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_3() {
    int Arr0[] = {3, 0, 0};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "RWR";
    int Arg2 = 0;
    verify_case(3, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_4() {
    int Arr0[] = {0, 0, 0, 0};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "????";
    int Arg2 = 1;
    verify_case(4, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_5() {
    int Arr0[] = {3, 2, 3, 2};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "?WR?";
    int Arg2 = 1;
    verify_case(5, Arg2, dubsAgain(Arg0, Arg1));
  }
  void test_case_6() {
    int Arr0[] = {0, 1, 2, 3, 4};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "R?W?R";
    int Arg2 = 1;
    verify_case(6, Arg2, dubsAgain(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  NBAFinals ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
