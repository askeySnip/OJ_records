// BEGIN CUT HERE

// END CUT HERE
#line 5 "Newgenerations.cpp"
#include <algorithm>
#include <bitset>
#include <cassert>
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
const int MOD = 1e9 + 7;
struct mod_int {
  int val;

  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;

    if (v >= MOD) v %= MOD;

    val = v;
  }

  static int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }

    return x < 0 ? x + m : x;
  }

  explicit operator int() const { return val; }

  mod_int& operator+=(const mod_int& other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  mod_int& operator-=(const mod_int& other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a
    // 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }

  mod_int& operator*=(const mod_int& other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }

  mod_int& operator/=(const mod_int& other) { return *this *= other.inv(); }

  friend mod_int operator+(const mod_int& a, const mod_int& b) {
    return mod_int(a) += b;
  }

  friend mod_int operator-(const mod_int& a, const mod_int& b) {
    return mod_int(a) -= b;
  }

  friend mod_int operator*(const mod_int& a, const mod_int& b) {
    return mod_int(a) *= b;
  }

  friend mod_int operator/(const mod_int& a, const mod_int& b) {
    return mod_int(a) /= b;
  }

  mod_int& operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }

  mod_int operator++(int) {
    mod_int before = *this;
    ++*this;
    return before;
  }

  mod_int& operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }

  mod_int operator--(int) {
    mod_int before = *this;
    --*this;
    return before;
  }

  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }

  bool operator==(const mod_int& other) const { return val == other.val; }

  bool operator!=(const mod_int& other) const { return val != other.val; }

  mod_int inv() const { return mod_inv(val); }

  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;

    while (p > 0) {
      if (p & 1) result *= a;

      a *= a;
      p >>= 1;
    }

    return result;
  }
};

class Newgenerations {
 public:
  int count(vector<string> field) {
    int n = field.size(), m = field[0].length();
    vi posx(0), posy(0);
    vector<vector<bool>> select(55, vector<bool>(55, false));
    vector<mod_int> b(2550);
    b[0] = 1;
    REP(i, 1, 2550) b[i] = b[i - 1] * 2;
    int num_free = 0;
    REP(i, 0, n) {
      REP(j, 0, m) {
        if (field[i][j] == 'x') {
          posx.push_back(i);
          posy.push_back(j);
        } else if (field[i][j] == '*')
          num_free++;
      }
    }
    mod_int ans = 0;
    vi dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    vii changexy;
    REP(mask, 0, (1 << posx.size())) {
      mod_int flag = 1;
      bool bad = false;
      int free = num_free;
      changexy.clear();
      int cha = 0;
      REP(i, 0, posx.size()) {
        if (mask & (1 << i)) {
          flag *= -1;
          REP(j, 0, 4) {
            int nx = posx[i] + dx[j], ny = posy[i] + dy[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                field[nx][ny] != '.') {
              if (field[nx][ny] == '*') {
                if (select[nx][ny] == false) {
                  cha++;
                  free--;
                  select[nx][ny] = true;
                  changexy.push_back(ii(nx, ny));
                }
              }
            } else {
              bad = true;
              break;
            }
          }
        }
      }
      if (!bad) {
        ans += b[free] * flag;
      }
      REP(i, 0, changexy.size()) {
        ii v = changexy[i];
        select[v.first][v.second] = false;
      }
    }
    REP(i, 0, n) { REP(j, 0, m) assert(select[i][j] == false); }
    return ans.val;
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
  string print_array(const vector<T>& V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int& Expected, const int& Received) {
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
    string Arr0[] = {"x*", "*#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    verify_case(0, Arg1, count(Arg0));
  }
  void test_case_1() {
    string Arr0[] = {"##.", ".#.", ".##"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    verify_case(1, Arg1, count(Arg0));
  }
  void test_case_2() {
    string Arr0[] = {"#.......#.......#", "##.....###.....##",
                     "###...#####...###", "####.x#####x.####",
                     "####xxx###xxx####", "###xx*******xx###",
                     "##x***********x##", "#***************#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 134217728;
    verify_case(2, Arg1, count(Arg0));
  }
  void test_case_3() {
    string Arr0[] = {
        "#****#*#*****#******", "#****#..*.#*#*.*x.#*", "****#**#**##*****#**",
        "*##***#*##x*x***#x*x", "****#*#*****#*****#*", ".**###*#**x*.*###**x",
        "*#**##*.**#****x**.*", "#************.***#**", "*******#*#****#***.*",
        "*#.***##**.**##.#*##", "*.##****.****#.****x", "*.*#****#*##*#***.#*",
        "###x#*.***#x***#***#", "#*.**#**#*******#.**", "****#x***##x*.##.*#*",
        "*###*###****.**#****", "*.*#*****###****##**", "*#*#**.*#*x*##**#***",
        "*##*******#x#**#****", "***##*******#*******"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 961436185;
    verify_case(3, Arg1, count(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Newgenerations ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
