// BEGIN CUT HERE

// END CUT HERE
#line 5 "PokerRound.cpp"
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

class PokerRound {
 public:
  int amount(int T) {
    if (10000 < T) return -1;
    if ((10000 - T) % 8) return -1;
    return 10000 - ((10000 - T) / 8);
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
    int Arg0 = 2000;
    int Arg1 = 9000;
    verify_case(0, Arg1, amount(Arg0));
  }
  void test_case_1() {
    int Arg0 = 10000;
    int Arg1 = 10000;
    verify_case(1, Arg1, amount(Arg0));
  }
  void test_case_2() {
    int Arg0 = 1722;
    int Arg1 = -1;
    verify_case(2, Arg1, amount(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  PokerRound ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
