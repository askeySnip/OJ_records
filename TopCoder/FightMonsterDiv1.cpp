// BEGIN CUT HERE

// END CUT HERE
#line 5 "FightMonsterDiv1.cpp"
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

class FightMonsterDiv1 {
 public:
  int lev;
  long double no(ll m) { return 100 * m + (long double)m * (m - 1) / 2 * lev; }
  long double dam(ll m, ll attack, ll duration) {
    long double a = no(m);
    ll w = max(1LL, m - duration);
    a = max(a, no(w - 1) + 5 * (no(m - 1) - no(w - 1)));
		return a * (attack / 100);
  }
  long long fightTime(long long hp, long long attack, int level,
                      long long duration) {
    lev = level;
    ll l = 1, h = 1e12;
    while (l < h) {
      ll mid = (l + h) / 2;
      if (dam(mid, attack, duration) >= hp)
        h = mid;
      else
        l = mid + 1;
    }
    return l;
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
    long long Arg0 = 201LL;
    long long Arg1 = 100LL;
    int Arg2 = 10;
    long long Arg3 = 10LL;
    long long Arg4 = 2LL;
    verify_case(0, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    long long Arg0 = 74900LL;
    long long Arg1 = 100LL;
    int Arg2 = 0;
    long long Arg3 = 2LL;
    long long Arg4 = 742LL;
    verify_case(1, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    long long Arg0 = 1000000000000LL;
    long long Arg1 = 1000000000000LL;
    int Arg2 = 100;
    long long Arg3 = 1000000000000LL;
    long long Arg4 = 1LL;
    verify_case(2, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    long long Arg0 = 1338LL;
    long long Arg1 = 100LL;
    int Arg2 = 1;
    long long Arg3 = 2LL;
    long long Arg4 = 6LL;
    verify_case(3, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  FightMonsterDiv1 ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
