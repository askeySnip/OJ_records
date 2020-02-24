// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysHash.cpp"
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
const ll lmod = 1000000000000037;

class EllysHash {
 public:
  ll p[30];
  string a, b, c;
  void dfs(ll h, int s, int e, vector<ll> &v) {
    if (s == e) {
      v.push_back(h);
      return;
    }
    dfs((h + (static_cast<int>(a[s]) * p[s]) % lmod) % lmod, s + 1, e, v);
    dfs((h + (static_cast<int>(b[s]) * p[s]) % lmod) % lmod, s + 1, e, v);
    dfs((h + (static_cast<int>(c[s]) * p[s]) % lmod) % lmod, s + 1, e, v);
  }
  long long getHash(int N, string A, string B, string C) {
    a = A, b = B, c = C;
    p[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) p[i] = (p[i + 1] * 127) % lmod;
    vector<ll> vl, vr;
    int szl = N / 2 + N % 2;
    dfs(0, 0, szl, vl);
    dfs(0, szl, N, vr);
    sort(vl.begin(), vl.end());
    ll ans = lmod;
    REP(i, 0, vr.size()) {
      ll target = lmod - vr[i];
      int pos = lower_bound(vl.begin(), vl.end(), target) - vl.begin();
      ans = min(ans, (vr[i] + vl[pos % static_cast<int>(vl.size())]) % lmod);
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
    int Arg0 = 4;
    string Arg1 = "ELLY";
    string Arg2 = "KRIS";
    string Arg3 = "STAN";
    long long Arg4 = 142572564LL;
    verify_case(0, Arg4, getHash(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 11;
    string Arg1 = "TOPCODERSRM";
    string Arg2 = "INTHEMIDDLE";
    string Arg3 = "OFTHEDAYNOO";
    long long Arg4 = 2840613885160LL;
    verify_case(1, Arg4, getHash(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 18;
    string Arg1 = "EVERYSTEPTHATITAKE";
    string Arg2 = "ISANOTHERMISTAKETO";
    string Arg3 = "YOOOOOOOOOOOOOOOOO";
    long long Arg4 = 325013178LL;
    verify_case(2, Arg4, getHash(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 28;
    string Arg1 = "ANDNEVERMINDTHENOISEYOUHEARD";
    string Arg2 = "ITSJUSTTHEBEASTSUNDERYOURBED";
    string Arg3 = "INYOURCLOSETINYOURHEAAAAAAAD";
    long long Arg4 = 745LL;
    verify_case(3, Arg4, getHash(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  EllysHash ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
