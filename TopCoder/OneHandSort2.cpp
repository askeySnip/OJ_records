// BEGIN CUT HERE

// END CUT HERE
#line 5 "OneHandSort2.cpp"
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

class OneHandSort2 {
 public:
  int minMoves(int N, vector<int> targetPrefix, int a, int b) {
    if (N == 1) return 0;
    set<int> s;
    REP(i, 0, N) s.insert(i);
    vi target(N);
    REP(i, 0, targetPrefix.size()) {
      target[i] = targetPrefix[i];
      s.erase(target[i]);
    }
    REP(i, targetPrefix.size(), N) {
      int tmp = (1LL * target[i - 1] * a + b) % N;
      auto it = s.lower_bound(tmp);
      if (it != s.end()) {
        target[i] = *it;
        s.erase(target[i]);
      } else {
        target[i] = *s.begin();
        s.erase(target[i]);
      }
    }
    vi vist(N, 0);
    int ans = 0;
    int n = N;
    REP(i, 0, N) if (target[i] == i) vist[i] = 1, n--;
    REP(i, 0, N) {
      if (!vist[i]) {
        int u = i;
        while (!vist[u]) {
          vist[u] = 1;
          u = target[u];
        }
        ans++;
      }
    }
    ans += n;
    return ans;
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
    int Arg0 = 4;
    int Arr1[] = {1, 2, 3, 0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 0;
    int Arg4 = 5;
    verify_case(0, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 4;
    int Arr1[] = {2, 3, 0, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 0;
    int Arg4 = 6;
    verify_case(1, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 10;
    int Arr1[] = {3, 7};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1664525;
    int Arg3 = 1013904223;
    int Arg4 = 11;
    verify_case(2, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 10;
    int Arr1[] = {5, 9, 8, 7, 6, 0, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 1;
    int Arg4 = 13;
    verify_case(3, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  OneHandSort2 ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
