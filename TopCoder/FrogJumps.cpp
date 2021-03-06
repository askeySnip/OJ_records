// BEGIN CUT HERE

// END CUT HERE
#line 5 "FrogJumps.cpp"
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

class FrogJumps {
 public:
  int canMeet(long long x1, long long y1, long long x2, long long y2,
              long long k1, long long k2) {
    ll dx = abs(x1 - x2);
    ll dy = abs(y1 - y2);
    ll d = __gcd(k1, k2);
    if (dx % d == 0 && dy % d == 0) return 1;
    return 0;
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
    long long Arg0 = 10LL;
    long long Arg1 = 10LL;
    long long Arg2 = 18LL;
    long long Arg3 = 13LL;
    long long Arg4 = 3LL;
    long long Arg5 = 4LL;
    int Arg6 = 1;
    verify_case(0, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_1() {
    long long Arg0 = 10LL;
    long long Arg1 = 10LL;
    long long Arg2 = 21LL;
    long long Arg3 = 17LL;
    long long Arg4 = 3LL;
    long long Arg5 = 4LL;
    int Arg6 = 1;
    verify_case(1, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_2() {
    long long Arg0 = 10LL;
    long long Arg1 = 10LL;
    long long Arg2 = 21LL;
    long long Arg3 = 13LL;
    long long Arg4 = 10LL;
    long long Arg5 = 10LL;
    int Arg6 = 0;
    verify_case(2, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_3() {
    long long Arg0 = 987654321987654321LL;
    long long Arg1 = 987654321987654321LL;
    long long Arg2 = -123456789123456789LL;
    long long Arg3 = -987654321987654321LL;
    long long Arg4 = 1LL;
    long long Arg5 = 2LL;
    int Arg6 = 1;
    verify_case(3, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_4() {
    long long Arg0 = 4LL;
    long long Arg1 = 7LL;
    long long Arg2 = 4LL;
    long long Arg3 = 7LL;
    long long Arg4 = 4LL;
    long long Arg5 = 7LL;
    int Arg6 = 1;
    verify_case(4, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_5() {
    long long Arg0 = 10000000000000LL;
    long long Arg1 = 100000000000000LL;
    long long Arg2 = 1000000000000000LL;
    long long Arg3 = 10000000000000000LL;
    long long Arg4 = 100000000000000000LL;
    long long Arg5 = 1000000000000000000LL;
    int Arg6 = 0;
    verify_case(5, Arg6, canMeet(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  FrogJumps ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
