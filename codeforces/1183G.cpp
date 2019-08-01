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
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    cin >> n;
    int a, f;
    vi cnt(n);
    vi cnt_good(n);
    REP(i, 0, n) {
      cin >> a >> f;
      a--;
      cnt[a]++;
      if(f) cnt_good[a]++;
    }
    vector<vi> types(n+1);
    for(int i=0; i<n; i++) {
      types[cnt[i]].push_back(cnt_good[i]);
    }
    int ans1 = 0, ans2 = 0;
    multiset<int> cur;
    for(int i=n; i>0; i--) {
      for(int j=0; j<(int)types[i].size(); j++) cur.insert(types[i][j]);
      if(!cur.empty()) {
        int z = *cur.rbegin();
        ans1 += i;
        ans2 += min(i, z);
        cur.erase(cur.find(z));
      }
    }
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
