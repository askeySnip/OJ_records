// BEGIN CUT HERE

// END CUT HERE
#line 5 "RestoreDrawing.cpp"
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

class RestoreDrawing {
 public:
  vi sum;
  vi sizes4, sizes8;
  vi split(int s, int e, int mask) {
    int ts = 0;
    REP(i, s, e + 1) ts += sizes8[i];
    if (ts != sum[mask])
      return {};
    else if (s == e)
      return {mask};
    int mid = (s + e) / 2;
    for (int i = mask; i; i = mask & (i - 1)) {
      vi t = split(s, mid, i);
      if (!t.empty()) {
        vi tt = split(mid + 1, e, mask ^ i);
        if (!tt.empty()) {
          REP(i, 0, tt.size()) { t.push_back(tt[i]); }
          return t;
        }
      }
    }
    return {};
  }
  vector<string> restore(vector<int> _sizes4, vector<int> _sizes8) {
    sizes4 = _sizes4, sizes8 = _sizes8;
    sort(sizes4.begin(), sizes4.end());
    sort(sizes8.begin(), sizes8.end());
    int n = sizes4.size();
    sum.assign(1 << n, 0);
    REP(i, 0, n) sum[1 << i] = sizes4[i];
    REP(i, 1, 1 << n) {
      int j = i & (i - 1);
      sum[i] = sum[j] + sum[i ^ j];
    }
    vi masks = split(0, sizes8.size() - 1, (1 << n) - 1);
    REP(i, 0, masks.size()) cout << masks[i] << " ";
    cout << endl;
    if (masks.empty()) return {};
    vector<string> ans(100, string(100, '.'));
    int h = 0;
    REP(i, 0, sizes8.size()) {
      int cur = 0;
      REP(j, 0, sizes4.size()) {
        if (masks[i] & (1 << j)) {
          ans[h++][cur] = '#';
          if (sizes4[j] == 1) {
            cur = 1 - cur;
          } else {
            int t = cur;
            REP(k, 2, sizes4[j]) {
              if (t >= 100) {
                h++;
                t = cur;
              }
              ans[h][t++] = '#';
            }
            if (ans[h][cur] == '#') h++;
            ans[h++][cur] = '#';
            cur = 1 - cur;
          }
        }
      }
      h++;
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
    int Arr0[] = {1, 1, 1, 1, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {5};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"#.#", ".#.", "#.#"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, restore(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {1, 1, 1, 1, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1, 1, 1, 1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"#....", "..#.#", ".....", "#..#."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, restore(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {2, 2, 2};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {3, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, restore(Arg0, Arg1));
  }
  void test_case_3() {
    int Arr0[] = {42};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {47};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(3, Arg2, restore(Arg0, Arg1));
  }
  void test_case_4() {
    int Arr0[] = {1, 2, 3, 5};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {7, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"##.##", "..##.", "#..#.", "##...", "..#.."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(4, Arg2, restore(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  RestoreDrawing ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
