// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysViewPoints.cpp"
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

class EllysViewPoints {
 public:
  int getCount(int N, int M, vector<string> matrix) {
    int a = 0, b = 0;
    REP(i, 0, N) {
      bool flag = true;
      REP(j, 0, M) {
        if (matrix[i][j] == '#') {
          flag = false;
          break;
        }
      }
      if (flag) a++;
    }
    REP(j, 0, M) {
      bool f = true;
      REP(i, 0, N) {
        if (matrix[i][j] == '#') {
          f = false;
          break;
        }
      }
      if (f) b++;
    }
    return a * b;
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
    int Arg0 = 6;
    int Arg1 = 9;
    string Arr2[] = {"..#......", ".........", ".###..#..",
                     ".#.##..#.", "...#..#..", "........."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 6;
    verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 1;
    int Arg1 = 1;
    string Arr2[] = {"."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 7;
    int Arg1 = 4;
    string Arr2[] = {"####", "####", "####", "####", "####", "####", "####"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 0;
    verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 9;
    int Arg1 = 48;
    string Arr2[] = {"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
                     "................................................",
                     ".#####...###...###.......##....###....##..#####.",
                     "...#....#.....#...#.....#..#..#...#..#.#..#...#.",
                     "...#....#.....#...#........#..#...#....#..#####.",
                     "...#....#.....#...#......#....#...#....#......#.",
                     "...#.....###...###......####...###.....#..#####.",
                     "................................................",
                     "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 18;
    verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  EllysViewPoints ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
