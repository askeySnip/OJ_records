/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n, mad;
vi e[100010];
vii ans;

void dfs(int v, int& t, int backT=-1, int p=-1) {
  ans.emplace_back(v, t);
  int cntTo = 0;
  for(auto u : e[v]) {
    if(u != p) ++cntTo;
  }
  for(auto to : e[v]) {
    if(to == p) continue;
    if(t == mad) {
      t = backT - 1 - cntTo;
      ans.emplace_back(v, t);
    }
    t++;
    dfs(to, t, t, v);
    ans.emplace_back(v, t);
    --cntTo;
  }
  if(p == -1) return;
  if(t >= backT) {
    t = backT - 1;
    ans.emplace_back(v, t);
  }
  t++;
}

void solve() {
  int t = 0;
  dfs(0, t);
  cout << ans.size() << "\n";
  for(auto s : ans) {
    cout << s.first+1 << " " << s.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int u, v;
  REP(i, 0, n-1) {
    cin >> u >> v;
    --u, --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  mad = 0;
  REP(i, 0, n) mad = max(mad, (int)e[i].size());
  solve();
  return 0;
}
