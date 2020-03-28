// BEGIN CUT HERE

// END CUT HERE
#line 5 "Hyperbox.cpp"
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

class Hyperbox {
 public:
  int count(int volume) {
    if (volume % 2 == 1) return 0;
    volume /= 2;
    int ans = 0;
    for (ll a = 1; 4 * a * a * a <= volume; ++a) {
      for (ll b = a; (3 * a + b) * b * b <= volume; ++b) {
        for (ll c = b; (2 * a * b + a * c + b * c) * c <= volume; ++c) {
          ll d = (volume - a * b * c) / (a * b + b * c + a * c);
          ans +=
              d >= c && a * b * c + a * b * d + a * c * d + b * c * d == volume;
        }
      }
    }
    return ans;
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
    int Arg0 = 8;
    int Arg1 = 1;
    verify_case(0, Arg1, count(Arg0));
  }
  void test_case_1() {
    int Arg0 = 1234567;
    int Arg1 = 0;
    verify_case(1, Arg1, count(Arg0));
  }
  void test_case_2() {
    int Arg0 = 120;
    int Arg1 = 3;
    verify_case(2, Arg1, count(Arg0));
  }
  void test_case_3() {
    int Arg0 = 123456;
    int Arg1 = 52;
    verify_case(3, Arg1, count(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Hyperbox ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
