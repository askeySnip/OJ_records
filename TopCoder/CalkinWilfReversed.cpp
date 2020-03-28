// BEGIN CUT HERE

// END CUT HERE
#line 5 "CalkinWilfReversed.cpp"
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

class CalkinWilfReversed {
 public:
	ll ans;
	int gcd(ll a, ll b) {
		if(b == 0) return a;
		ans += a / b;
		return gcd(b, a%b);
	}
  long long getDepth(long long a, long long b) {
		ans = 0;
		if(a < b) swap(a, b);
		gcd(a, b);
		return ans - 1;
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
    long long Arg0 = 1LL;
    long long Arg1 = 1LL;
    long long Arg2 = 0LL;
    verify_case(0, Arg2, getDepth(Arg0, Arg1));
  }
  void test_case_1() {
    long long Arg0 = 4LL;
    long long Arg1 = 3LL;
    long long Arg2 = 3LL;
    verify_case(1, Arg2, getDepth(Arg0, Arg1));
  }
  void test_case_2() {
    long long Arg0 = 1LL;
    long long Arg1 = 1234567890123LL;
    long long Arg2 = 1234567890122LL;
    verify_case(2, Arg2, getDepth(Arg0, Arg1));
  }
  void test_case_3() {
    long long Arg0 = 1234567LL;
    long long Arg1 = 7654321LL;
    long long Arg2 = 8837LL;
    verify_case(3, Arg2, getDepth(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CalkinWilfReversed ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
