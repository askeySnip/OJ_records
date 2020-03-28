// BEGIN CUT HERE

// END CUT HERE
#line 5 "HalfGraph.cpp"
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

class HalfGraph {
 public:
  vector<string> a;
  int n;
  int d[60];
  vi path;
  void Euler(int u) {
    for (int i = 0; i < a.size(); i++) {
      if (a[u][i] == '1') {
        a[u][i] = a[i][u] = '0';
        d[u]--;
        d[i]--;
        Euler(i);
      }
    }
    path.push_back(u);
  }
  vector<string> compute(vector<string> _a) {
    a = _a;
    n = a.size();
		memset(d, 0, sizeof d);
    REP(i, 0, n) {
      REP(j, 0, n) {
        if (a[i][j] == '1') d[i]++;
      }
      if (d[i] % 2) return {};
    }
    vector<string> ans = _a;
    REP(i, 0, n) {
      path.clear();
      Euler(i);
      if (path.size() % 2 == 0) return {};
      for (int i = 1; i < (int)path.size(); i += 2) {
        int u = path[i], v = path[i - 1];
        ans[u][v] = ans[v][u] = '0';
      }
    }
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
  void verify_case(int Case, const vector<string> &Expected,
                   const vector<string> &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    string Arr0[] = {"000", "000", "000"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"000", "000", "000"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, compute(Arg0));
  }
  void test_case_1() {
    string Arr0[] = {"01111", "10111", "11011", "11101", "11110"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"00011", "00110", "01001", "11000", "10100"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, compute(Arg0));
  }
  void test_case_2() {
    string Arr0[] = {"010", "101", "010"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, compute(Arg0));
  }
  void test_case_3() {
    string Arr0[] = {"01111", "10100", "11000", "10001", "10010"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"00011", "00100", "01000", "10000", "10000"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, compute(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  HalfGraph ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
