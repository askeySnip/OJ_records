// BEGIN CUT HERE

// END CUT HERE
#line 5 "IdenticalBags.cpp"
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

class IdenticalBags {
 public:
  long long makeBags(vector<long long> candy, long long bagSize) {
		ll low = 0, hi = 1e18+100;
		while(hi - low > 1) {
			ll mid = (low + hi) / 2;
			ll filled = 0;
			for(auto c : candy) {
				filled += c / mid;
				if(filled >= bagSize) break;
			}
			if(filled >= bagSize) low = mid;
			else hi = mid;
		}
		return low;
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
    long Arr0[] = {10, 11, 12};
    vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 3LL;
    long long Arg2 = 10LL;
    verify_case(0, Arg2, makeBags(Arg0, Arg1));
  }
  void test_case_1() {
    long Arr0[] = {10, 11, 12, 1, 2, 3};
    vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 3LL;
    long long Arg2 = 10LL;
    verify_case(1, Arg2, makeBags(Arg0, Arg1));
  }
  void test_case_2() {
    long Arr0[] = {100};
    vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 7LL;
    long long Arg2 = 14LL;
    verify_case(2, Arg2, makeBags(Arg0, Arg1));
  }
  void test_case_3() {
    long Arr0[] = {10000000000, 20000000000, 30000000000};
    vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 6LL;
    long long Arg2 = 10000000000LL;
    verify_case(3, Arg2, makeBags(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  IdenticalBags ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
