// BEGIN CUT HERE

// END CUT HERE
#line 5 "BagsOfMarbles.cpp"
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

class BagsOfMarbles {
 public:
  int removeFewest(int desired, int bagSize, int noWhiteBags, int noBlackBags,
                   int someWhiteBags, int someBlackBags) {
    if (desired <= bagSize * noBlackBags) {
      return min(desired, bagSize * noBlackBags);
    }
    desired -= bagSize * noBlackBags;

    if (desired <= someWhiteBags) {
      return bagSize * noBlackBags + desired * bagSize;
    } else {
      return -1;
    }

    return -1;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
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
    int Arg0 = 5;
    int Arg1 = 10;
    int Arg2 = 0;
    int Arg3 = 1;
    int Arg4 = 0;
    int Arg5 = 0;
    int Arg6 = 5;
    verify_case(0, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arg1 = 10;
    int Arg2 = 2;
    int Arg3 = 0;
    int Arg4 = 1;
    int Arg5 = 0;
    int Arg6 = -1;
    verify_case(1, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_2() {
    int Arg0 = 51;
    int Arg1 = 7;
    int Arg2 = 7;
    int Arg3 = 7;
    int Arg4 = 7;
    int Arg5 = 7;
    int Arg6 = 63;
    verify_case(2, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  BagsOfMarbles ___test;
  ___test.run_test(-1);
}
// END CUT HERE
