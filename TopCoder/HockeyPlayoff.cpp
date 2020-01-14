// BEGIN CUT HERE

// END CUT HERE
#line 5 "HockeyPlayoff.cpp"
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

ll dp[601][601][21][3];
class HockeyPlayoff {
 public:
  ll n, m, pa, pb;
  ll winProbability(ll winsNeeded, ll AwinHome, ll BwinHome) {
    memset(dp, -1, sizeof dp);
    n = winsNeeded;
    m = 2 * n - 1;
    pa = AwinHome;
    pb = BwinHome;
    return helper(0, 0, 0, 2);
  }
  ll my_pow(ll base, ll e) {
    if (e == 0) return 1;
    if (e & 1) {
      return (base * my_pow(base, e - 1)) % mod;
    } else {
      return my_pow((base * base) % mod, e / 2);
    }
  }
  void mod_add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
  }
  ll helper(ll wa, ll wb, ll streak, ll team) {
    if (wa == n) return my_pow(100, m - wa - wb);
    if (wb == n) return 0;
    ll pA, pB, bonus, &ret = dp[wa][wb][streak][team];
    if (ret != -1) return ret;
    ret = 0;
    bonus = streak * 5;
    pA = (wa + wb) % 4 < 2 ? pa : 100 - pb;
    pA += team ? -bonus : bonus;
    pA = min(100ll, pA);
    pA = max(0ll, pA);
    pB = 100 - pA;
    mod_add(ret, helper(wa + 1, wb, team == 0 ? min(20ll, streak + 1) : 1, 0) *
                     pA % mod);
    mod_add(ret, helper(wa, wb + 1, team == 1 ? min(20ll, streak + 1) : 1, 1) *
                     pB % mod);
    return ret;
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
    int Arg0 = 3;
    int Arg1 = 0;
    int Arg2 = 100;
    int Arg3 = 0;
    verify_case(0, Arg3, winProbability(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 4;
    int Arg1 = 100;
    int Arg2 = 0;
    int Arg3 = 999300007;
    verify_case(1, Arg3, winProbability(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 600;
    int Arg1 = 50;
    int Arg2 = 50;
    int Arg3 = 594375906;
    verify_case(2, Arg3, winProbability(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 4;
    int Arg1 = 53;
    int Arg2 = 57;
    int Arg3 = 942200194;
    verify_case(3, Arg3, winProbability(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 7;
    int Arg1 = 93;
    int Arg2 = 87;
    int Arg3 = 545426737;
    verify_case(4, Arg3, winProbability(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  HockeyPlayoff ___test;
  ___test.run_test(-1);
}
// END CUT HERE
