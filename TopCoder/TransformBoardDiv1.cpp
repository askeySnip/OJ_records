// BEGIN CUT HERE

// END CUT HERE
#line 5 "TransformBoardDiv1.cpp"
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

class TransformBoardDiv1 {
 public:
  vector<int> getOperations(vector<string> start, vector<string> target) {
    int n = start.size(), m = start[0].size();
    vector<vi> a(n, vi(m, 0)), b(n, vi(m, 0));
    REP(i, 0, n) REP(j, 0, m) a[i][j] = start[i][j] == '#';
    REP(i, 0, n) REP(j, 0, m) b[i][j] = target[i][j] == '#';
    vi ans;
    vector<vi> d(m, vi(n, 0));
    vi dh(m, 0), dt(m, 0);
    REP(i, 0, n) {
      REP(j, 0, m) {
        if (a[i][j]) d[j][dt[j]++] = i;
        if (b[i][j]) {
          int jj = j;
          while (jj >= 0 && dh[jj] == dt[jj]) jj--;
          if (jj < 0) return {-1};
          int ii = d[jj][dh[jj]++];
          if (jj < j) ans.push_back(i * 1000000 + jj * 10000 + i * 100 + j);
          if (ii < i) ans.push_back(ii * 1000000 + jj * 10000 + i * 100 + jj);
        }
      }
    }
    int i = n - 1, j = m - 1, s = 0;
    for (int jj = m - 1; jj >= 0; jj--) {
      while (dt[jj] > dh[jj]) {
        s++;
        int ii = d[jj][dh[jj]++];
        if (jj < j) ans.push_back(i * 1000000 + jj * 10000 + i * 100 + j);
        if (ii < i) ans.push_back(ii * 1000000 + jj * 10000 + i * 100 + jj);
      }
    }
		if(s%2) return {-1};
		reverse(ans.begin(), ans.end());
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
  void verify_case(int Case, const vector<int> &Expected,
                   const vector<int> &Received) {
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
    string Arr0[] = {"#.", ".."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"..", ".#"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 10101};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, getOperations(Arg0, Arg1));
  }
  void test_case_1() {
    string Arr0[] = {"..", ".#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"#.", ".."};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {-1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, getOperations(Arg0, Arg1));
  }
  void test_case_2() {
    string Arr0[] = {"#..#", "#..."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"....", "...#"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {3, 1000103};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, getOperations(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  TransformBoardDiv1 ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
