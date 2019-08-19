/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int a[100024];
int n, q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  int maxid = 0;
  REP(i, 0, n) {
    cin >> a[i];
    if(a[maxid] < a[i]) {
      maxid = i;
    }
  }
  deque<int> dq;
  REP(i, 0, n) {
    dq.push_back(a[i]);
  }
  vii ans;
  REP(i, 0, maxid) {
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    ans.push_back(ii(a, b));
    if(a < b) swap(a, b);
    dq.push_back(b);
    dq.push_front(a);
  }
  REP(i, 0, n) {
    a[i] = dq.front();
    dq.pop_front();
  }
  ll m;
  REP(i, 0, q) {
    cin >> m;
    if(m > maxid) {
      m -= maxid;
      m--;
      m %= (n-1);
      printf("%d %d\n", a[0], a[m+1]);
    } else {
      printf("%d %d\n", ans[m-1].first, ans[m-1].second);
    }
  }
  return 0;
}
