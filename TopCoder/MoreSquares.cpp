// BEGIN CUT HERE

// END CUT HERE
#line 5 "MoreSquares.cpp"
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
typedef pair<double, double> dd;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;
// for i = L .. N-1:
//     X[i] = ( X[i-1] * 47 + 42 ) modulo SX
//     Y[i] = ( Y[i-1] * 47 + 42 ) modulo SY

// for i = 0 .. N-1:
//     if (X[i], Y[i]) is not in S:
//         add (X[i], Y[i]) to S
class MoreSquares {
 public:
  int countLocations(int N, int SX, int SY, vector<int> Xprefix,
                     vector<int> Yprefix) {
    vi X(N), Y(N);
    REP(i, 0, Xprefix.size()) X[i] = Xprefix[i], Y[i] = Yprefix[i];
    REP(i, Xprefix.size(), N) {
      X[i] = (X[i - 1] * 47 + 42) % SX;
      Y[i] = (Y[i - 1] * 47 + 42) % SY;
    }
    set<dd> S;
    REP(i, 0, N) { S.insert({X[i], Y[i]}); }
    set<dd> T;
    for (auto i : S) {
      for (auto j : S) {
        if (i == j) continue;
        double x1 = (i.first + j.first + i.second - j.second) / 2.0;
        double x2 = (i.first + j.first - i.second + j.second) / 2.0;
        double y1 = (i.second + j.second + j.first - i.first) / 2.0;
        double y2 = (i.second + j.second - j.first + i.first) / 2.0;
        if (S.count({x1, y1}) && !S.count({x2, y2})) T.insert({x2, y2});
        if (S.count({x2, y2}) && !S.count({x1, y1})) T.insert({x1, y1});
      }
    }
    return T.size();
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
    int Arg1 = 100;
    int Arg2 = 100;
    int Arr3[] = {3, 0, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {0, 1, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 1;
    verify_case(0, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arg1 = 100;
    int Arg2 = 100;
    int Arr3[] = {47, 47, 47, 47, 47};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {47, 47, 47, 47, 47};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 0;
    verify_case(1, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 23;
    int Arg1 = 11;
    int Arg2 = 13;
    int Arr3[] = {7};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 5;
    verify_case(2, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MoreSquares ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
