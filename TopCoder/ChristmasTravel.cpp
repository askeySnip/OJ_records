// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChristmasTravel.cpp"
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

class ChristmasTravel {
 public:
  vector<string> plan(int N, int A) {
    vector<string> R, none;
    // int i, x, y;
    REP(i, 0, N) R.push_back(string(N, '-'));

    vii cand[26];
    REP(i, 0, A) {
      REP(y, 0, N) {
        REP(x, 0, y) {
          if (R[y][x] == '-' && (x & (1 << i)) != (y & (1 << i))) {
            R[y][x] = R[x][y] = 'A' + i;
            cand[i].push_back({y, x});
          }
        }
      }
    }

    REP(i, 0, A) {
      REP(x, 0, A) {
        if (cand[i].empty() && cand[x].size() > 1) {
          cand[i].push_back(cand[x].back());
          cand[x].pop_back();
          R[cand[i][0].first][cand[i][0].second] = 'A' + i;
          R[cand[i][0].second][cand[i][0].first] = 'A' + i;
        }
      }
      if (cand[i].empty()) return none;
    }
    REP(y, 0, N) REP(x, 0, N) if (x != y && R[y][x] == '-') return none;
    return R;
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
    int Arg0 = 3;
    int Arg1 = 1;
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, plan(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 3;
    int Arg1 = 3;
    string Arr2[] = {"-AC", "A-B", "CB-"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, plan(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arg1 = 3;
    string Arr2[] = {"-ABAB", "A-ACC", "BA-AC", "ACA-B", "BCCB-"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, plan(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 1;
    int Arg1 = 1;
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(3, Arg2, plan(Arg0, Arg1));
  }
  void test_case_4() {
    int Arg0 = 6;
    int Arg1 = 5;
    string Arr2[] = {"-ACEDB", "A-BDCE", "CB-AED",
                     "EDA-BC", "DCEB-A", "BEDCA-"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(4, Arg2, plan(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ChristmasTravel ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
