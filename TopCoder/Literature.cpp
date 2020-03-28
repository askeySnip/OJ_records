// BEGIN CUT HERE

// END CUT HERE
#line 5 "Literature.cpp"
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

double dp[3][1024][1024];
int vist[3][1024][1024];
class Literature {
 public:
  int n;
  double getprob(int a, int b) {
    double x = 1.0;
    x *= a;
    x /= b;
    return x;
  }
  double dfs(int person, int call1, int call2) {
    if (call1 == n || call2 == n) return 0.0;
    if (vist[person][call1][call2]) return dp[person][call1][call2];
    vist[person][call1][call2] = 1;
    double &prob = dp[person][call1][call2];
    if (person == 0) {
      prob = dfs(1, call1, call2) + 1;
    } else if (person == 1) {
      prob = getprob(n - call1, 2 * n) * (dfs(2, call1 + 1, call2) + 1);
      prob += getprob(n + call1, 2 * n) * (dfs(2, call1, call2) + 1);
    } else {
      prob = getprob(n - call2, 2 * n) * (dfs(0, call1, call2 + 1) + 1);
      prob += getprob(n + call2, 2 * n) * getprob(n - call1, 2 * n) *
              (dfs(2, call1 + 1, call2) + 3);
      prob += getprob(n + call2, 2 * n) * getprob(n + call1, 2 * n) * 3;
      prob /= 1 - getprob(n + call2, 2 * n) * getprob(n + call1, 2 * n);
    }
    return prob;
  }
  double expectation(int _n, vector<int> Teja, vector<int> history) {
    set<int> s1, s2;
    n = _n;
    int a[3024]{0};
    REP(i, 0, Teja.size()) a[Teja[i]] = 1;
    REP(i, 0, history.size()) {
      if (i % 3 == 1 && a[history[i]] == 0) {
        s1.insert(history[i]);
        if (s1.size() == n) return i + 1;
      } else if (i % 3 == 2 && a[history[i]] == 0) {
        s2.insert(history[i]);
        if (s2.size() == n) return i + 1;
      }
    }
    memset(vist, 0, sizeof vist);
    int t = history.size();
    double ans = dfs(t % 3, s1.size(), s2.size());
    ans += t;
    return ans;
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
    int Arg0 = 1;
    int Arr1[] = {3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 3.333333333333333;
    verify_case(0, Arg3, expectation(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {1, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {3, 1, 6, 6, 2, 5, 2, 4, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 6.0;
    verify_case(1, Arg3, expectation(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 10;
    int Arr1[] = {5, 29, 12, 16, 25, 17, 18, 30, 27, 10};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {4, 6, 5, 23, 22, 29, 20, 8, 12, 3, 13, 16, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    double Arg3 = 133.0880654696573;
    verify_case(2, Arg3, expectation(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Literature ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
