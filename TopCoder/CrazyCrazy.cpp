// BEGIN CUT HERE

// END CUT HERE
#line 5 "CrazyCrazy.cpp"
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

class CrazyCrazy {
 public:
  set<string> get_set(string &s) {
    int n = s.length();
    set<string> ret;
    REP(i, 0, (1 << n)) {
      if (__builtin_popcount(i) * 2 >= n) {
        string first, second;
        REP(j, 0, n) {
          if (i & (1 << j))
            first += s[j];
          else
            second += s[j];
        }
        if (first.substr(0, second.length()) == second) {
          ret.insert(first.substr(second.length()));
        }
      }
    }
    return ret;
  }
  string possible(string song) {
    int n = song.length() / 2;
    string f = song.substr(0, n), s = song.substr(n);
    set<string> fs = get_set(f);
    reverse(s.begin(), s.end());
    set<string> ss = get_set(s);
    for (auto sss : ss) {
      reverse(sss.begin(), sss.end());
      if (fs.count(sss)) return "possible";
    }
    return "impossible";
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
    string Arg0 = "aabb";
    string Arg1 = "possible";
    verify_case(0, Arg1, possible(Arg0));
  }
  void test_case_1() {
    string Arg0 = "abba";
    string Arg1 = "impossible";
    verify_case(1, Arg1, possible(Arg0));
  }
  void test_case_2() {
    string Arg0 = "verylazyverylazy";
    string Arg1 = "possible";
    verify_case(2, Arg1, possible(Arg0));
  }
  void test_case_3() {
    string Arg0 = "arqmpfvvbtltlhufznkldkurrazmgebfxeamrewn";
    string Arg1 = "impossible";
    verify_case(3, Arg1, possible(Arg0));
  }
  void test_case_4() {
    string Arg0 = "aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll";
    string Arg1 = "possible";
    verify_case(4, Arg1, possible(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CrazyCrazy ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
