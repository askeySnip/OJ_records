// BEGIN CUT HERE

// END CUT HERE
#line 5 "Conquest.cpp"
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

class Conquest {
 public:
  double ans[51][21][21][21];
  int used[51][21][21][21];
  vector<tuple<int, int, double>> outcomes(int a, int b) {
    if (a > 3) {
      if (b > 1) {
        return {tuple<int, int, double>{2, 0, 2275. / 7776},
                tuple<int, int, double>{1, 1, 2611. / 7776},
                tuple<int, int, double>{0, 2, 2890. / 7776}};
      } else {
        return {tuple<int, int, double>{1, 0, 441. / 1296},
                tuple<int, int, double>{0, 1, 855. / 1296}};
      }
    } else if (a == 3) {
      if (b > 1) {
        return {tuple<int, int, double>{2, 0, 581. / 1296},
                tuple<int, int, double>{1, 1, 420. / 1296},
                tuple<int, int, double>{0, 2, 295. / 1296}};
      } else {
        return {tuple<int, int, double>{1, 0, 91. / 216},
                tuple<int, int, double>{0, 1, 125. / 216}};
      }
    } else {
      if (b > 1) {
        return {tuple<int, int, double>{1, 0, 161. / 216},
                tuple<int, int, double>{0, 1, 55. / 216}};
      } else {
        return {tuple<int, int, double>{1, 0, 21. / 36},
                tuple<int, int, double>{0, 1, 15. / 36}};
      }
    }
  }
  double bestChance(int x, vector<int> a) {
    sort(begin(a), end(a));
    if (a == vector<int>{0, 0, 0}) {
      return 1;
    } else if (x < 2) {
      return 0;
    } else if (used[x][a[0]][a[1]][a[2]]) {
      return ans[x][a[0]][a[1]][a[2]];
    } else {
      for (int z = 0; z < 3; z++) {
        if (a[z] == 0) {
          continue;
        }
        double res = 0;
        for (auto it : outcomes(x, a[z])) {
          x -= get<0>(it);
          a[z] -= get<1>(it);
          if (x != 0) {
            x -= a[z] == 0;
            res += get<2>(it) * bestChance(x, a);
            x += a[z] == 0;
          }
          x += get<0>(it);
          a[z] += get<1>(it);
        }
        ans[x][a[0]][a[1]][a[2]] = max(ans[x][a[0]][a[1]][a[2]], res);
      }
      used[x][a[0]][a[1]][a[2]] = 1;
      return ans[x][a[0]][a[1]][a[2]];
    }
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
    int Arg0 = 4;
    int Arr1[] = {1, 1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 0.15907653892318244;
    verify_case(0, Arg2, bestChance(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 10;
    int Arr1[] = {2, 2, 10};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 0.13552235780217273;
    verify_case(1, Arg2, bestChance(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 30;
    int Arr1[] = {5, 5, 5};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 0.9857787020110442;
    verify_case(2, Arg2, bestChance(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Conquest ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
