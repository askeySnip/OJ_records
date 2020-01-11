// BEGIN CUT HERE

// END CUT HERE
#line 5 "AllEven.cpp"
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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class AllEven {
 public:
  long long countInRange(long long lo, long long hi) {
    string sh = to_string(hi);
    vector<vector<ll>> dp(sh.length() + 1, vector<ll>(1 << 10, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= sh.length(); i++) {
      for (int j = 0; j < (1 << 10); j++) {
        for (int d = 0; d < 10; d++) {
          dp[i][j] += dp[i - 1][j ^ (1 << d)];
        }
      }
    }
    ll h = getAns(hi + 1, dp);
    ll l = getAns(lo, dp);
    return h - l;
  }
  ll getAns(ll n, vector<vector<ll>> &dp) {
    string s = to_string(n);
    ll ans = 0;
    for (int i = 1; i < s.length(); i++) {
      for (int d = 1; d < 10; d++) {
        ans += dp[i - 1][1 << d];
      }
    }
    int mask = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int d = (i == 0 ? 1 : 0); d < s[i] - '0'; d++) {
        ans += dp[s.length() - i - 1][mask ^ (1 << d)];
      }
      mask ^= (1 << (s[i] - '0'));
    }
    return ans;
  }
  ll C(int m, int n) {
    if (n == 0 || m == n) return 1;
    ll ans = 1;
    for (int i = 1; i <= m; i++) ans *= i;
    for (int i = 1; i <= n; i++) ans /= i;
    for (int i = 1; i <= (m - n); i++) ans /= i;
    return ans;
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
    long long Arg0 = 47LL;
    long long Arg1 = 999LL;
    long long Arg2 = 5LL;
    verify_case(0, Arg2, countInRange(Arg0, Arg1));
  }
  void test_case_1() {
    long long Arg0 = 47LL;
    long long Arg1 = 1010LL;
    long long Arg2 = 7LL;
    verify_case(1, Arg2, countInRange(Arg0, Arg1));
  }
  void test_case_2() {
    long long Arg0 = 12345678901LL;
    long long Arg1 = 98765432109LL;
    long long Arg2 = 0LL;
    verify_case(2, Arg2, countInRange(Arg0, Arg1));
  }
  void test_case_3() {
    long long Arg0 = 1234LL;
    long long Arg1 = 654321LL;
    long long Arg2 = 6862LL;
    verify_case(3, Arg2, countInRange(Arg0, Arg1));
  }
  void test_case_4() {
    long long Arg0 = 0LL;
    long long Arg1 = 10LL;
    long long Arg2 = 0LL;
    verify_case(4, Arg2, countInRange(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  AllEven ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
