// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysTournament.cpp"
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

class EllysTournament {
 public:
  // dyn[l][r][type] : interval [l, r] winner is l if type = 0 else r;
  // dp[l][r] : the chance l and r meet;
  double dyn[510][510][2];
  double dp[510][510];
  vi ratings;
  double getChance(int N, int K, vector<int> _ratings) {
    ratings = _ratings;
    REP(i, 0, N) REP(j, 0, N) dyn[i][j][0] = dyn[i][j][1] = -1;
    REP(i, 0, N) REP(j, 0, N) dp[i][j] = -1;
    double ans = rec(0, K - 1, 1) * rec(K - 1, N - 1, 0);
    return ans;
  }
  double go(int l, int r) {
    if (l == r - 1) return 1.0;
    if (dp[l][r] != -1) return dp[l][r];
    double ans = 0;
    REP(i, l, r) { ans += rec(l, i, 0) * rec(i + 1, r, 1); }
    return dp[l][r] = ans;
  }
  double rec(int l, int r, int type) {
    if (l == r) return 1.0;
    if (dyn[l][r][type] != -1) return dyn[l][r][type];
    double ans = 0.0;
    int pos = type ? r : l;
    REP(opp, l, r + 1) {
      if (pos != opp) {
        double chance_play = 1.0 / (r - l);
        double chance_win = 1.0 * ratings[pos] / (ratings[pos] + ratings[opp]);
        double opp_win = type ? rec(l, opp, 1) : rec(opp, r, 0);
        double chance_meet = type ? go(opp, pos) : go(pos, opp);
        ans += chance_play * chance_win * opp_win * chance_meet;
      }
    }
    return dyn[l][r][type] = ans;
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
  void verify_case(int Case, const double &Expected, const double &Received) {
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
    int Arg0 = 4;
    int Arg1 = 2;
    int Arr2[] = {2103, 2019, 1911, 2331};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 0.17753927527829697;
    verify_case(0, Arg3, getChance(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 12;
    int Arg1 = 6;
    int Arr2[] = {42, 88, 13, 11, 71, 55, 32, 13, 72, 53, 37, 50};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 0.06697114679670368;
    verify_case(1, Arg3, getChance(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 20;
    int Arg1 = 13;
    int Arr2[] = {1543, 1230, 421,  1415, 1271, 1962, 2677, 2373, 2951, 114,
                  1379, 2015, 2211, 955,  2066, 2573, 2982, 296,  1730, 1591};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 0.05017297846158086;
    verify_case(2, Arg3, getChance(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 100;
    int Arg1 = 42;
    int Arr2[] = {2750, 2877, 2224, 186,  1398, 1084, 1542, 2770, 2288, 1078,
                  373,  2417, 476,  2968, 564,  1565, 1740, 1377, 2633, 287,
                  111,  823,  578,  520,  1708, 174,  144,  1295, 694,  678,
                  227,  2588, 371,  2740, 211,  1798, 82,   2385, 2979, 389,
                  2031, 1667, 2541, 2561, 1471, 2562, 974,  577,  286,  2836,
                  120,  2290, 185,  554,  2549, 1410, 1814, 1508, 2559, 1806,
                  2215, 1606, 2637, 1394, 1583, 1491, 2908, 529,  2556, 1034,
                  2770, 750,  2866, 2590, 1156, 2646, 2536, 958,  2862, 2565,
                  1027, 2744, 1160, 276,  2080, 322,  92,   790,  2452, 1859,
                  602,  2935, 2392, 1076, 2991, 1158, 2721, 868,  112,  29};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 0.003026484586204139;
    verify_case(3, Arg3, getChance(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  EllysTournament ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
