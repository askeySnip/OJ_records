// BEGIN CUT HERE

// END CUT HERE
#line 5 "SoccerStadium.cpp"
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
#define bit(x, i) (x & (1 << i))
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr << #vari << " = " << (vari) << endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size() - 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

class SoccerStadium {
 public:
  int maximumGames(int H, int W, vector<string> placement) {
    while (true) {
      bool terminate = true;
      REP(i, 2, 2 * H - 1) {
        REP(j, 2, 2 * W - 1) {
          int mask = 0;
          if (placement[i - 1][j] == '|') mask |= 1;
          if (placement[i + 1][j] == '|') mask |= 2;
          if (placement[i][j - 1] == '-') mask |= 4;
          if (placement[i][j + 1] == '-') mask |= 8;
          if (mask == 1 || mask == 2 || mask == 4 || mask == 8 || mask == 5 ||
              mask == 6 || mask == 9 || mask == 10) {
            placement[i - 1][j] = ',';
            placement[i + 1][j] = '.';
            placement[i][j - 1] = '.';
            placement[i][j + 1] = '.';
            terminate = false;
          }
        }
      }
      if (terminate) break;
    }
    int ans = 0;
    for (int i = 0; i <= 2 * H; i += 2) {
      for (int j = 0; j <= 2 * W; j += 2) {
        int mask = 0;
        if (i != 0 && placement[i - 1][j] == '|') mask |= 1;
        if (i != 2 * H && placement[i + 1][j] == '|') mask |= 2;
        if (j != 0 && placement[i][j - 1] == '-') mask |= 4;
        if (j != 2 * W && placement[i][j + 1] == '-') mask |= 8;
        if ((mask & 5) == 5) ++ans;
        if ((mask & 9) == 9) ++ans;
        if ((mask & 6) == 6) ++ans;
        if ((mask & 10) == 10) ++ans;
      }
    }
    return ans / 4;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
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
    int Arg1 = 4;
    string Arr2[] = {"+-+-+-+-+", "|.|.....|", "+.+-+-+-+",
                     "|.|.|...|", "+-+-+.+.+", "|.|.|...|",
                     "+-+.+.+-+", "|...|...|", "+-+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 5;
    verify_case(0, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 3;
    int Arg1 = 3;
    string Arr2[] = {"+-+-+-+", "|.....|", "+-+-+.+", "|.|.|.|",
                     "+-+-+-+", "|.|.|.|", "+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(1, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arg1 = 3;
    string Arr2[] = {"+-+-+-+", "|.|...|", "+.+-+.+", "|.|.|.|",
                     "+.+.+-+", "|.|...|", "+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 2;
    verify_case(2, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 3;
    int Arg1 = 3;
    string Arr2[] = {"+-+-+-+", "|.....|", "+.+-+.+", "|.|.|.|",
                     "+.+-+.+", "|.....|", "+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    verify_case(3, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 3;
    int Arg1 = 4;
    string Arr2[] = {"+-+-+-+-+", "|.|.|...|", "+-+-+-+-+", "|.......|",
                     "+.+-+-+.+", "|.......|", "+-+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(4, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    int Arg0 = 7;
    int Arg1 = 9;
    string Arr2[] = {
        "+-+-+-+-+-+-+-+-+-+", "|.|...|...|...|...|", "+.+-+-+-+-+-+-+-+-+",
        "|.|.|...|...|...|.|", "+-+.+-+-+-+-+-+-+.+", "|.|.|.|...|...|.|.|",
        "+.+-+.+-+-+-+-+.+-+", "|.|.|.|.|.|.|.|.|.|", "+-+.+-+.+.+-+.+-+.+",
        "|.|.|...|...|.|.|.|", "+.+-+-+-+-+-+-+.+-+", "|.|...|...|...|.|.|",
        "+-+-+-+-+-+-+-+-+.+", "|...|...|...|...|.|", "+-+-+-+-+-+-+-+-+-+"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 25;
    verify_case(5, Arg3, maximumGames(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SoccerStadium ___test;
  ___test.run_test(-1);
}
// END CUT HERE
