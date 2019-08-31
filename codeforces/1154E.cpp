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
int n, k;
vi a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  a.resize(n);
  REP(i, 0, n) cin >> a[i];
  priority_queue<ii> pq;
  map<int, int> mp;
  REP(i, 0, n) pq.push(ii(a[i], i));
  REP(i, 0, n) mp[i] = a[i];
  vi ans(n);
  int who = 1;
  while(!pq.empty()) {
    int t = pq.top().second; pq.pop();
    map<int, int>::iterator it = mp.find(t);
    if(it != mp.end()) {
      vi add;
      it = mp.lower_bound(t);
      for(int i=0; i<=k; i++) {
        add.push_back(it->first);
        if(it == mp.begin()) break;
        --it;
      }
      it = mp.upper_bound(t);
      for(int i=0; i<k; i++) {
        if(it == mp.end()) break;
        add.push_back(it->first);
        ++it;
      }
      REP(i, 0, add.size()) {
        int id = add[i];
        mp.erase(id);
        ans[id] = who;
      }
      who = 3 - who;
    }
  }
  REP(i, 0, n) cout << ans[i];
  cout << endl;
  return 0;
}
