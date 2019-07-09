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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int m;
map<string, int> mp;
vi edges[230];
bool flag;
int color[230];

void bi_color(int u) {
  queue<int> q;
  q.push(u);
  color[u] = 1;
  while(!q.empty()) {
    int p = q.front(); q.pop();
    REP(i, 0, edges[p].size()) {
      int& v = edges[p][i];
      if(color[v] == 0) {
        color[v] = 3 - color[p];
        q.push(v);
      } else if(color[v] == color[p]) {
        flag = false;
        return;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int kase = 0;
  while(t--) {
    memset(color, 0, sizeof color);
    REP(i, 0, 230) {
      edges[i].clear();
    }
    mp.clear();
    flag = true;
    cin >> m;
    string s1, s2;
    int c = 0;
    REP(i, 0, m) {
      cin >> s1 >> s2;
      if(mp.find(s1) == mp.end()) {
        mp[s1] = c++;
      }
      if(mp.find(s2) == mp.end()) {
        mp[s2] = c++;
      }
      edges[mp[s1]].push_back(mp[s2]);
      edges[mp[s2]].push_back(mp[s1]);
    }
    REP(i, 0, c) {
      if(!flag) break;
      if(color[i]) continue;
      bi_color(i);
    }
    if(flag) cout << "Case #" << ++kase << ": Yes" << endl;
    else cout << "Case #" << ++kase << ": No" << endl;
  }
  return 0;
}
