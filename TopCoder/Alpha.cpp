// BEGIN CUT HERE

// END CUT HERE
#line 5 "Alpha.cpp"
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

class Alpha {
 public:
  int maxPref(string s) {
    int cnt = 0;
    REP(i, 0, s.length()) {
      if (s[i] != 'a' + i) break;
      cnt++;
    }
    return cnt;
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
    if ((Case == -1) || (Case == 6)) test_case_6();
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
    string Arg0 = "abctyf";
    int Arg1 = 3;
    verify_case(0, Arg1, maxPref(Arg0));
  }
  void test_case_1() {
    string Arg0 = "abcdefghijklmnopqrstuvwxyz";
    int Arg1 = 26;
    verify_case(1, Arg1, maxPref(Arg0));
  }
  void test_case_2() {
    string Arg0 = "zyx";
    int Arg1 = 0;
    verify_case(2, Arg1, maxPref(Arg0));
  }
  void test_case_3() {
    string Arg0 = "abcdegfhijk";
    int Arg1 = 5;
    verify_case(3, Arg1, maxPref(Arg0));
  }
  void test_case_4() {
    string Arg0 = "ba";
    int Arg1 = 0;
    verify_case(4, Arg1, maxPref(Arg0));
  }
  void test_case_5() {
    string Arg0 = "aabc";
    int Arg1 = 1;
    verify_case(5, Arg1, maxPref(Arg0));
  }
  void test_case_6() {
    string Arg0 = "abcdefghijklmno";
    int Arg1 = 15;
    verify_case(6, Arg1, maxPref(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Alpha ___test;
  ___test.run_test(-1);
}
// END CUT HERE
