// BEGIN CUT HERE

// END CUT HERE
#line 5 "BinaryDistance.cpp"
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

class BinaryDistance {
 public:
  int maxDist(int N, int V) {
    int level = 1;
    while ((1 << level) <= V) level++;
    int t_level = 1;
    while ((1 << t_level) <= N) t_level++;
    int l = t_level, r = t_level;
    if (N - (1 << (t_level - 1)) + 1 <= (1 << (t_level - 2))) r--;
    if (V == 1) return max(l - level, r - level);
    int tv = V;
    while (tv >= 4) tv >>= 1;
    // cout << level << "  " << l << " " << r << " " << tv << endl;
    if (tv == 2) {
      return max(l - level, level - 1 + r - 1);
    } else {
      return max(r - level, level - 1 + l - 1);
    }
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
    int Arg0 = 6;
    int Arg1 = 2;
    int Arg2 = 3;
    verify_case(0, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 6;
    int Arg1 = 6;
    int Arg2 = 4;
    verify_case(1, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arg1 = 4;
    int Arg2 = 3;
    verify_case(2, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 2;
    int Arg1 = 2;
    int Arg2 = 1;
    verify_case(3, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_4() {
    int Arg0 = 1000000000;
    int Arg1 = 1;
    int Arg2 = 29;
    verify_case(4, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_5() {
    int Arg0 = 20;
    int Arg1 = 7;
    int Arg2 = 6;
    verify_case(5, Arg2, maxDist(Arg0, Arg1));
  }
  void test_case_6() {
    int Arg0 = 12;
    int Arg1 = 4;
    int Arg2 = 5;
    verify_case(6, Arg2, maxDist(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  BinaryDistance ___test;
  ___test.run_test(-1);
}
// END CUT HERE
