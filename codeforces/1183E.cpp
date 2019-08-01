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
  int n, k;
  string s;
  cin >> n >> k >> s;
  if(k == 1) {
    cout << "0" << endl;
    return 0;
  }
  queue<string> q;
  set<string> st;
  q.push(s);
  st.insert(s);
  int ans = 0;
  while(!q.empty() && (int)st.size() < k) {
    string u = q.front(); q.pop();
    for(int i=0; i<(int)u.length(); i++) {
      string v = u;
      v.erase(i, 1);
      if(!st.count(v)) {
        q.push(v);
        st.insert(v);
        ans += n - v.length();
        if((int)st.size() == k) break;
      }
    }
  }
  if((int)st.size() == k) cout << ans << endl;
  else cout << "-1" << endl;
  return 0;
}
