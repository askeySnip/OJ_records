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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if(n < 4) {
    cout << "1" << endl;
    return 0;
  }
  int b[200048];
  map<int, int> index;
  for(int i=0; i<n; i++) {
    cin >> b[i];
    index[b[i]] = i + 1;
  }
  sort(b, b+n);
  int c = b[1] - b[0];
  vi ans;
  int last = b[0];
  for(int i=1; i<n; i++) {
    if(b[i] - last != c) ans.push_back(index[b[i]]);
    else last = b[i];
    if(ans.size() > 1) break;
  }
  if(ans.size() < 2) {
    if(ans.empty()) cout << index[b[0]] << endl;
    else cout << ans[0] << endl;
    return 0;
  }
  ans.clear();
  c = b[2] - b[0];
  bool flag = true;
  for(int i=3; i<n; i++) {
    if(b[i] - b[i-1] != c) {
      flag = false;
      break;
    }
  }
  if(flag) {
    cout << index[b[1]] << endl;
    return 0;
  }
  c = b[2] - b[1];
  flag = true;
  for(int i=3; i<n; i++) {
    if(b[i] - b[i-1] != c) {
      flag = false;
      break;
    }
  }
  if(flag) cout << index[b[0]] << endl;
  else cout << "-1" << endl;
  return 0;
}
