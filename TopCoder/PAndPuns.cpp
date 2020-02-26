// BEGIN CUT HERE

// END CUT HERE
#line 5 "PAndPuns.cpp"
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

class PAndPuns {
 public:
  string check(string text) {
    int l = text.length();
    for (int i = 0; i <= l - 4; i++) {
      for (int j = i + 2; j <= l - 2; j++) {
        if (text[i] == text[j] && text[i + 1] == text[j + 1]) {
          return "pun";
        }
      }
    }
    return "not a pun";
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
    string Arg0 = "aaaa";
    string Arg1 = "pun";
    verify_case(0, Arg1, check(Arg0));
  }
  void test_case_1() {
    string Arg0 = "aaab";
    string Arg1 = "not a pun";
    verify_case(1, Arg1, check(Arg0));
  }
  void test_case_2() {
    string Arg0 = "pandpuns";
    string Arg1 = "not a pun";
    verify_case(2, Arg1, check(Arg0));
  }
  void test_case_3() {
    string Arg0 = "producerandproduction";
    string Arg1 = "pun";
    verify_case(3, Arg1, check(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  PAndPuns ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
