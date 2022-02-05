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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data

vector<vector<int>> e;
vector<int> vist;
vector<int> ans;
bool flag;

void dfs(int u) {
  // cout << u << endl;
  vist[u] = 1;
  for (auto v : e[u]) {
    if (vist[v] == 2)
      continue;
    else if (vist[v] == 1) {
      flag = true;
      return;
    } else
      dfs(v);
  }
  ans.push_back(u);
  vist[u] = 2;
}

vector<int> topo(vector<vector<int>>& dep, int n) {
  e.clear();
  e.resize(n);
  vist.assign(n, 0);
  flag = false;
  ans.clear();
  for (auto& d : dep) {
    e[d[0]].push_back(d[1]);
  }
  for (int i = 0; i < n; i++) {
    if (!vist[i]) dfs(i);
    if (flag) return {};
  }
  // cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  vector<vector<int>> dep = {{0, 1}, {1, 2}, {2, 3}};
  vector<int> tmp = topo(dep, 4);
  REP(i, 0, tmp.size()) cout << tmp[i] << " ";
  cout << endl;
  vector<vector<int>> dep1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 3}};
  cout << topo(dep1, 5).size() << endl;
  vector<vector<int>> dep2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {6, 3}};
  tmp = topo(dep2, 7);
  REP(i, 0, tmp.size()) cout << tmp[i] << " ";
  cout << endl;
  return 0;
}
