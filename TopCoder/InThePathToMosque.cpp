// BEGIN CUT HERE

// END CUT HERE
#line 5 "InThePathToMosque.cpp"
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

class InThePathToMosque {
 public:
  vi par, weight;
  vector<ll> sumW;
  vector<vi> g, blocks;
  vi startTime, endTime;
  int time_id;

  class Fenwick {
   public:
    Fenwick(int n) { ft.assign(n + 1, 0); }
    void add(int p, ll val) {
      p++;
      for (; p < ft.size(); p += (p & (-p))) ft[p] += val;
    }
    void range_add(int s, int e, ll val) {
      add(s, val);
      add(e, -val);
    }
    ll get(int p) {
      ll ans = 0;
      p++;
      for (; p; p -= (p & (-p))) ans += ft[p];
      return ans;
    }

   private:
    vector<ll> ft;
  };
  void getTime(int u) {
    startTime[u] = time_id++;
    for (auto &v : g[u]) {
      getTime(v);
    }
    endTime[u] = time_id;
  }
  void getBlocks(int u, vi bls) {
    while (bls.size() > 1 && weight[bls.back()] <= 2 * weight[u])
      bls.pop_back();
    bls.push_back(u);
    for (int i = bls.size() - 1; i >= 0; i--) {
      blocks[u].push_back(bls[i]);
    }
    for (auto v : g[u]) {
      getBlocks(v, bls);
    }
  }
  long long solve(int n, int q, int A, int B, int t) {
    par.assign(n, 0), weight.assign(n, 0);
    sumW.assign(n, 0);
    startTime.assign(n, 0), endTime.assign(n, 0);
    g.assign(n, vi(0));
    blocks.assign(n, vi(0));
    int p = 0, w = 0;
    REP(i, 1, n) {
      p = max(0, (int)(i - 1 - ((1LL * p * A + B) % t)));
      w = (int)((1LL * w * A + B) % inf);
      g[p].push_back(i);
      weight[i] = w;
      par[i] = p;
      sumW[i] = sumW[p] + w;
    }
    time_id = 0;
    getTime(0);
    getBlocks(0, {});
    Fenwick fw(n + 10);
    int u = 0, f = 0;
    ll ans = 0;
    REP(i, 0, q) {
      u = (int)((1LL * u * A + B) % n);
      f = (int)((1LL * f * A + B) % inf);
      int v = -1;
      REP(j, 0, blocks[u].size()) {
        v = blocks[u][j];
        if (v == 0 || 1LL * f + sumW[u] - sumW[v] + fw.get(startTime[u]) -
                              fw.get(startTime[par[v]]) <
                          1LL * weight[v])
          break;
      }
      ans += v;
      ll val = 1LL * f + sumW[u] - sumW[v] + fw.get(startTime[u]) -
               fw.get(startTime[par[v]]);
      fw.range_add(startTime[v], endTime[v], val);
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
    int Arg1 = 10;
    int Arg2 = 3;
    int Arg3 = 2;
    int Arg4 = 1;
    long long Arg5 = 5LL;
    verify_case(0, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 10;
    int Arg1 = 20;
    int Arg2 = 1234567;
    int Arg3 = 7654321;
    int Arg4 = 13;
    long long Arg5 = 29LL;
    verify_case(1, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 10;
    int Arg1 = 20;
    int Arg2 = 1234567;
    int Arg3 = 7654321;
    int Arg4 = 3;
    long long Arg5 = 29LL;
    verify_case(2, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  InThePathToMosque ___test;
  ___test.run_test(-1);
}
// END CUT HERE
