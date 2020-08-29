// BEGIN CUT HERE

// END CUT HERE
#line 5 "NextOlympics.cpp"
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

class NextOlympics {
 public:
  const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int countDays(string today) {
    int y = stoi(today.substr(0, 4)), m = stoi(today.substr(5, 2)),
        d = stoi(today.substr(8));
    int ans = 0;
    while (!(y == 2021 && m == 7 && d == 24)) {
      ans++;
      d++;
      if (d == months[m - 1] + 1) {
        d = 1;
        m++;
      }
      if (m == 13) {
        m = 1;
        y++;
      }
    }
    return ans - 1;
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
    string Arg0 = "2020.07.24";
    int Arg1 = 364;
    verify_case(0, Arg1, countDays(Arg0));
  }
  void test_case_1() {
    string Arg0 = "2020.11.09";
    int Arg1 = 256;
    verify_case(1, Arg1, countDays(Arg0));
  }
  void test_case_2() {
    string Arg0 = "2021.02.25";
    int Arg1 = 148;
    verify_case(2, Arg1, countDays(Arg0));
  }
  void test_case_3() {
    string Arg0 = "2021.07.23";
    int Arg1 = 0;
    verify_case(3, Arg1, countDays(Arg0));
  }
  void test_case_4() {
    string Arg0 = "2020.12.31";
    int Arg1 = 204;
    verify_case(4, Arg1, countDays(Arg0));
  }
  void test_case_5() {
    string Arg0 = "2021.01.01";
    int Arg1 = 203;
    verify_case(5, Arg1, countDays(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  NextOlympics ___test;
  ___test.run_test(-1);
}
// END CUT HERE
