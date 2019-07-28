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
int n, m;
char cell[2048][2048];

bool check(vii& a) {
  bool f = true;
  for(int i=1; i<(int)a.size(); i++) {
    if(a[i].first != a[0].first) {
      f = false;
      break;
    }
  }
  if(f) return true;
  f = true;
  for(int i=1; i<(int)a.size(); i++) {
    if(a[i].second != a[0].second) {
      f = false;
      break;
    }
  }
  return f;
}

bool getse(vii pos, int letter, ii& s, ii& e) {
  if(pos.size() == 1) {
    s = pos[0];
    e = pos[0];
    return true;
  }
  bool f = pos[0].first == pos[1].first;
  if(f) {
    int x = pos[0].first;
    for(int i=pos[0].second; i<=pos.back().second; i++) {
      if(cell[x][i] == '.' || cell[x][i] - 'a' < letter) return false;
    }
  } else {
    int y = pos[0].second;
    for(int i=pos[0].first; i<=pos.back().first; i++) {
      if(cell[i][y] == '.' || cell[i][y] - 'a' < letter) return false;
    }
  }
  s = pos[0];
  e = pos.back();
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    vii pos[26];
    for(int i=0; i<n; i++) {
      cin >> cell[i];
      for(int j=0; j<m; j++) {
        if(cell[i][j] != '.') {
          pos[cell[i][j]-'a'].push_back(ii(i, j));
        }
      }
    }
    bool f = true;
    for(int i=0; i<26; i++) {
      if(!check(pos[i])) {
        f = false;
        break;
      }
    }
    vii ans;
    if(f) {
      bool flag = false;
      for(int i=25; i>=0; i--) {
        if(!flag && pos[i].size() == 0) continue;
        ii a, b;
        if(pos[i].size() == 0) {
          ans.push_back(ans[0]);
          ans.push_back(ans[1]);
        }else if(getse(pos[i], i, a, b)) {
          ans.push_back(b);
          ans.push_back(a);
        } else {
          f = false;
          break;
        }
        flag = true;
      }
    }
    if(f) {
      reverse(ans.begin(), ans.end());
      cout << "YES" << endl;
      cout << ans.size() / 2 << endl;
      for(int i=0; i<(int)ans.size(); i+=2) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << " " << ans[i+1].first + 1 << " " << ans[i+1].second + 1 << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
