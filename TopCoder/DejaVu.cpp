// BEGIN CUT HERE

// END CUT HERE
#line 5 "DejaVu.cpp"
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

ii seg[200000 * 4];
vi m;
vi arr;
void build(int v, int l, int r) {
  if (l == r) {
    seg[v] = {arr[l], arr[l]};
    return;
  }
  int mid = (l + r) / 2;
  build(v * 2, l, mid);
  build(v * 2 + 1, mid + 1, r);
  seg[v] = {seg[v * 2].first + seg[v * 2 + 1].first,
            max(seg[v * 2].second, seg[v * 2].first + seg[v * 2 + 1].second)};
}
void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    seg[v] = {val, val};
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(v * 2, l, mid, pos, val);
  else
    update(2 * v + 1, mid + 1, r, pos, val);
  seg[v] = {seg[v * 2].first + seg[v * 2 + 1].first,
            max(seg[v * 2].second, seg[v * 2].first + seg[v * 2 + 1].second)};
}
class DejaVu {
 public:
  int mostDejaVus(int N, int seed, int R) {
    ll a = seed;
    m.resize(N);
    REP(i, 0, N) {
      m[i] = a % R;
      a = (a * 1664525 + 1013904223) % 4294967296;
    }
    map<int, set<int>> pos;
    for (int i = 0; i < N; i++) {
      if (pos.find(m[i]) == pos.end()) pos[m[i]] = {};
      pos[m[i]].insert(i);
    }
    arr.assign(N, 0);
    for (auto s : pos) {
      int i = 0;
      for (auto p : s.second) {
        if (i == 1)
          arr[p] = 1;
        else if (i == 2)
          arr[p] = -1;
        i++;
        if (i > 2) break;
      }
    }
    build(1, 0, N - 1);
    int ans = seg[1].second;
    REP(i, 0, N) {
      int v = m[i];
      pos[v].erase(pos[v].begin());
      update(1, 0, N - 1, i, 0);
      int j = 0;
      for (auto p : pos[v]) {
        if (j == 0) {
          update(1, 0, N - 1, p, 0);
        } else if (j == 1) {
          update(1, 0, N - 1, p, 1);
        } else if (j == 2) {
          update(1, 0, N - 1, p, -1);
        } else {
          break;
        }
        j++;
      }
      ans = max(ans, seg[1].second);
    }
    return ans;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
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
    int Arg0 = 10;
    int Arg1 = 47;
    int Arg2 = 5;
    int Arg3 = 2;
    verify_case(0, Arg3, mostDejaVus(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 14;
    int Arg1 = 474747;
    int Arg2 = 7;
    int Arg3 = 3;
    verify_case(1, Arg3, mostDejaVus(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  DejaVu ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
