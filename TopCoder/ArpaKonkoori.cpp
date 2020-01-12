// BEGIN CUT HERE

// END CUT HERE
#line 5 "ArpaKonkoori.cpp"
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

class ArpaKonkoori {
 public:
  ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  long long getA(long long d, long long s) {
    for (ll i = 1; i * i <= s; i++) {
      if (s % i != 0) continue;
      ll a = max(i, s / i), b = s / a;
      if ((a + b) & 1) continue;
      if (gcd((a + b) / 2, (a - b) / 2) == d) return (a + b) / 2;
    }
    return -1;
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
  void verify_case(int Case, const long long &Expected,
                   const long long &Received) {
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
    long long Arg0 = 5LL;
    long long Arg1 = 2975LL;
    long long Arg2 = 300LL;
    verify_case(0, Arg2, getA(Arg0, Arg1));
  }
  void test_case_1() {
    long long Arg0 = 1LL;
    long long Arg1 = 2975LL;
    long long Arg2 = 1488LL;
    verify_case(1, Arg2, getA(Arg0, Arg1));
  }
  void test_case_2() {
    long long Arg0 = 1LL;
    long long Arg1 = 100LL;
    long long Arg2 = -1LL;
    verify_case(2, Arg2, getA(Arg0, Arg1));
  }
  void test_case_3() {
    long long Arg0 = 12345678901LL;
    long long Arg1 = 345LL;
    long long Arg2 = -1LL;
    verify_case(3, Arg2, getA(Arg0, Arg1));
  }
  void test_case_4() {
    long long Arg0 = 3LL;
    long long Arg1 = 9LL;
    long long Arg2 = 3LL;
    verify_case(4, Arg2, getA(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ArpaKonkoori ___test;
  ___test.run_test(-1);
}
// END CUT HERE
