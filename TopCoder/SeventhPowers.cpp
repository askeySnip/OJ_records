// BEGIN CUT HERE

// END CUT HERE
#line 5 "SeventhPowers.cpp"
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

class SeventhPowers {
 public:
  string reconstructA(int B) {
    vi p(10);
    REP(i, 0, 10) p[i] = pow(i, 7);

    string ans;
    for (int i = 9; i >= 0; i--) {
      int r = B / p[i];
      if (r) {
        REP(j, 0, r) ans += to_string(i);
      }
      B -= r * p[i];
      if (!B) break;
    }
    return ans;
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
  void verify_case(int Case, const string &Expected, const string &Received) {
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
    int Arg0 = 839927;
    string Arg1 = "407";
    verify_case(0, Arg1, reconstructA(Arg0));
  }
  void test_case_1() {
    int Arg0 = 130;
    string Arg1 = "121";
    verify_case(1, Arg1, reconstructA(Arg0));
  }
  void test_case_2() {
    int Arg0 = 43740;
    string Arg1 = "33333333333333333333";
    verify_case(2, Arg1, reconstructA(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SeventhPowers ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
