// BEGIN CUT HERE

// END CUT HERE
#line 5 "MojiDeletes.cpp"
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

const int maxn = 500010;
ll a[maxn], l[maxn], r[maxn], s[maxn];
struct trie {
  int cnt = 0, rt[maxn], ch[maxn << 6][2], val[maxn << 6];
  void insert(int o, int lst, ll v) {
    for (int i = 32; i >= 0; i--) {
      val[o] = val[lst] + 1;
      if (v & (1LL << i)) {
        if (!ch[o][1]) ch[o][1] = ++cnt;
        ch[o][0] = ch[lst][0];
        o = ch[o][1];
        lst = ch[lst][1];
      } else {
        if (!ch[o][0]) ch[o][0] = ++cnt;
        ch[o][1] = ch[lst][1];
        o = ch[o][0];
        lst = ch[lst][0];
      }
    }
    val[o] = val[lst] + 1;
  }

  ll query(int o1, int o2, ll v) {
    ll ret = 0;
    for (int i = 32; i >= 0; i--) {
      int t = ((v & (1LL << i)) ? 1 : 0);
      if (val[ch[o1][!t]] - val[ch[o2][!t]])
        ret += (1LL << i), o1 = ch[o1][!t], o2 = ch[o2][!t];
      else
        o1 = ch[o1][t], o2 = ch[o2][t];
    }
    return ret;
  }
} pt;
// A[0] = Add.
// For each i from 1 to N-1: A[i] = (A[i-1] * Base + Add) modulo (10^9 + 7).
// L[0] = QAdd modulo N, and R[0] = (L[0] * QBase + QAdd) modulo N.
// For each i from 1 to Q-1: L[i] = (R[i-1] * QBase + QAdd) modulo N, and R[i] =
// (L[i] * QBase + QAdd) modulo N.
class MojiDeletes {
 public:
  long long maximumXor(int N, int Q, int Base, int Add, int QBase, int QAdd) {
    a[1] = Add;
    REP(i, 2, N + 1) { a[i] = (a[i - 1] * Base + Add) % mod; }
    l[0] = QAdd % N, r[0] = (l[0] * QBase + QAdd) % N;
    REP(i, 1, Q) {
      l[i] = (r[i - 1] * QBase + QAdd) % N;
      r[i] = (l[i] * QBase + QAdd) % N;
    }
    REP(i, 0, Q) if (l[i] > r[i]) swap(l[i], r[i]);
    REP(i, 1, N + 1) { s[i] = s[i - 1] ^ a[i]; }
    REP(i, 1, N + 1) {
      pt.rt[i] = ++pt.cnt;
      pt.insert(pt.rt[i], pt.rt[i - 1], a[i]);
    }
    ll ans = 0;
    REP(i, 0, Q) {
      int q = pt.query(pt.rt[l[i]], pt.rt[r[i] + 1], s[r[i] + 1] ^ s[l[i]]);
      ans += q;
    }
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
  void verify_case(int Case, const long long &Expected,
                   const long long &Received) {
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
    int Arg0 = 5;
    int Arg1 = 3;
    int Arg2 = 10;
    int Arg3 = 3;
    int Arg4 = 2;
    int Arg5 = 2;
    long long Arg6 = 37292LL;
    verify_case(0, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_1() {
    int Arg0 = 47;
    int Arg1 = 42;
    int Arg2 = 7654321;
    int Arg3 = 1234567;
    int Arg4 = 23;
    int Arg5 = 10;
    long long Arg6 = 41156782009LL;
    verify_case(1, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_2() {
    int Arg0 = 500000;
    int Arg1 = 500000;
    int Arg2 = 2;
    int Arg3 = 1;
    int Arg4 = 2;
    int Arg5 = 1;
    long long Arg6 = 534618713588573LL;
    verify_case(2, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MojiDeletes ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
