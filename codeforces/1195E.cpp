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

class minQueue {
private:
  deque<ii> q;
  int cnt_add;
  int cnt_remove;
public:
  minQueue() {cnt_add = 0, cnt_remove = 0;}
  int getMin() {
    return q.front().first;
  }
  void addElement(int e) {
    while(!q.empty() && q.back().first > e) q.pop_back();
    q.push_back(ii(e, cnt_add));
    cnt_add++;
  }
  void removeElement() {
    if(!q.empty() && q.front().second == cnt_remove) q.pop_front();
    cnt_remove++;
  }
  int getSize() {
    return cnt_add - cnt_remove;
  }
  void clear() {
    cnt_add = 0;
    cnt_remove = 0;
    while(!q.empty()) q.pop_back();
  }
};

// data
int n, m, a, b;
int h[3003][3003], x, y, z;
int mn[3003][3003];
int main() {
  cin >> n >> m >> a >> b;
  cin >> h[0][0] >> x >> y >> z;
  memset(mn, 0, sizeof mn);
  long long cur = h[0][0];
  for(int i=0; i<n; i++) {
    for(int j= (i ? 0 : 1); j<m; j++) {
      h[i][j] = ((cur * x) % z + y) % z;
      cur = h[i][j];
    }
  }
  minQueue mq;
  ll ans = 0;
  for(int j=0; j<m; j++) {
    for(int i=0; i<n-a+1; i++) {
      if(i) {
        mq.removeElement();
        mq.addElement(h[i+a-1][j]);
        mn[i][j] = mq.getMin();
      } else {
        for(int k=0; k<a; k++) {
          mq.addElement(h[i+k][j]);
        }
        mn[i][j] = mq.getMin();
      }
    }
    mq.clear();
  }
  for(int i=0; i<n-a+1; i++) {
    for(int j=0; j<m;j++) {
      if(j < b) {
        mq.addElement(mn[i][j]);
      } else {
        ans += mq.getMin();
        mq.removeElement();
        mq.addElement(mn[i][j]);
      }
    }
    ans+=mq.getMin();
    mq.clear();
  }
  cout << ans << endl;
  return 0;
}
