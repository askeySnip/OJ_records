// BEGIN CUT HERE

// END CUT HERE
#line 5 "MahdiJumping.cpp"
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

class MahdiJumping {
 public:
  long long minDis(int n, int A, int B, int a, int b) {
    vector<ll> dp(n, 1e14);
    dp[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto v = pq.top();
      pq.pop();
      if (v.second + 1 < n && dp[v.second + 1] > dp[v.second] + a) {
        dp[v.second + 1] = dp[v.second] + a;
        pq.push({dp[v.second + 1], v.second + 1});
      }
      int j = (1LL * A * v.second + B) % n;
      if (dp[j] > dp[v.second] + b) {
        dp[j] = dp[v.second] + b;
        pq.push({dp[j], j});
      }
    }
    return dp[n - 1];
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
    int Arg0 = 7;
    int Arg1 = 1;
    int Arg2 = 1;
    int Arg3 = 1;
    int Arg4 = 5;
    long long Arg5 = 6LL;
    verify_case(0, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arg1 = 2;
    int Arg2 = 2;
    int Arg3 = 1;
    int Arg4 = 2;
    long long Arg5 = 3LL;
    verify_case(1, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arg1 = 5;
    int Arg2 = 5;
    int Arg3 = 5;
    int Arg4 = 5;
    long long Arg5 = 20LL;
    verify_case(2, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MahdiJumping ___test;
  ___test.run_test(-1);
}
// END CUT HERE
