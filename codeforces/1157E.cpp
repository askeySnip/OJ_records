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
int a[200024], b[200024];
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) cin >> b[i], mp[b[i]]++;
  REP(i, 0, n) {
    if(mp.find(n - a[i]) != mp.end()) {
      cout << 0 << " ";
      mp[n-a[i]]--;
      if(mp[n-a[i]] == 0) mp.erase(n-a[i]);
    } else {
      if(a[i] == 0 && mp.find(0) != mp.end()) {
        cout << 0 << " ";
        mp[0]--;
        if(mp[0] == 0) mp.erase(0);
        continue;
      }
      int t;
      if(mp.upper_bound(n-a[i]) == mp.end()) {
        t = mp.begin()->first;
      } else {
        t = mp.upper_bound(n-a[i])->first;
      }
      int tt = mp.begin()->first;
      if((a[i]+t)%n > (a[i]+tt)%n) swap(t, tt);
      cout << (a[i]+t) % n << " ";
      mp[t]--;
      if(mp[t] == 0) mp.erase(t);
    }
  }
  cout << endl;
  return 0;
}
