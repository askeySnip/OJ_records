// BEGIN CUT HERE

// END CUT HERE
#line 5 "FourSquareSum.cpp"
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

class FourSquareSum {
 public:
  vector<int> DivideByTwo(int a, int b, int c, int d) {
    if (a % 2 != b % 2) {
      if (c % 2 == a % 2) {
        swap(b, c);
      } else {
        swap(b, d);
      }
    }
    return {(a + b) / 2, abs(a - b) / 2, (c + d) / 2, abs(c - d) / 2};
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
  void verify_case(int Case, const vector<int> &Expected,
                   const vector<int> &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 1;
    int Arg1 = 2;
    int Arg2 = 3;
    int Arg3 = 4;
    int Arr4[] = {1, 1, 2, 3};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(0, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arg1 = 7;
    int Arg2 = 1;
    int Arg3 = 3;
    int Arr4[] = {1, 1, 2, 6};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(1, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 0;
    int Arg1 = 0;
    int Arg2 = 0;
    int Arg3 = 0;
    int Arr4[] = {0, 0, 0, 0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(2, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  FourSquareSum ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
