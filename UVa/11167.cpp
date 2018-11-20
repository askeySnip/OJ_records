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

// struct
#define inf 1e6

// notice: the source node is s(0), the end node is t(ti+1), the monkey node is 1~n, n+1 to ti is time intervals.

// data
int n, m;
int res[512][512];
vi edges[512];
int mf, f, s, t;
vii intervals;
vector<pair<int, ii> > viii;
vii ans[103];
vi p;

void augment(int v, int minEdge) {
  if(v == s) {f = minEdge; return;}
  else if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f;
  }
}

void solve() {
  mf = 0;
  while(1) {
    f = 0;
    p.assign(512, -1);
    bitset<512> vist; vist[s] = true;
    queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i=0; i<(int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(res[u][v] > 0 && !vist[v]) {
          vist[v] = true; p[v] = u; q.push(v);
        }
      }
    }
    augment(t, inf);
    if(f == 0) break;
    mf += f;
  }
}

void generate_ans() {
  vi ic(intervals.size(), 0);
  for(int i=1; i<=n; i++) {
    for(int j=0; j<(int)intervals.size(); j++) {
      int nd = n + 1 + j;
      if(res[nd][i] > 0) {
        if(ic[j] + res[nd][i] <= intervals[j].second - intervals[j].first) {
          ans[i].push_back(ii(intervals[j].first + ic[j], intervals[j].first + ic[j] + res[nd][i]));
          ic[j] += res[nd][i];
        }else {
          ans[i].push_back(ii(intervals[j].first + ic[j], intervals[j].second));
          int ta = res[nd][i] - (intervals[j].second - intervals[j].first - ic[j]);
          ic[j] = 0;
          ans[i].push_back(ii(intervals[j].first + ic[j], intervals[j].first + ic[j] + ta));
          ic[j] += ta;
        }
      }
    }
  }
  for(int i=1; i<=n; i++) {
    vii ans_tmp;
    sort(ans[i].begin(), ans[i].end());
    for(int j=0; j<(int)ans[i].size(); j++) {
      ii& ttt = ans[i][j];
      if(ttt.first == ttt.second) continue;
      if(ans_tmp.empty()) ans_tmp.push_back(ttt);
      else if(ttt.first == ans_tmp.back().second) {
        ans_tmp.back().second = ttt.second;
      }else {
        ans_tmp.push_back(ttt);
      }
    }
    ans[i] = ans_tmp;
  }
}
int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    scanf("%d", &m);
    memset(res, 0, sizeof res);
    intervals.clear(); viii.clear();
    for(int i=0; i<103; i++) ans[i].clear();
    for(int i=0; i<512; i++) edges[i].clear();
    int tot = 0;
    int v, a, b;
    for(int i=1; i<=n; i++) {
      scanf("%d %d %d", &v, &a, &b);
      viii.push_back(make_pair(i, ii(a, b)));
      res[0][i] = v;
      tot+=v;
      edges[0].push_back(i);
      edges[i].push_back(0);
      vii::iterator it;
      for(it = intervals.begin(); it!= intervals.end(); it++) {
        ii p = *it;
        if(a >= p.second) continue; // after with no overlap
        else if(b <= p.first) {     // before the first;
          it = intervals.insert(it, ii(a, b)) + 1;
          a = b;
          break;
        }else if(a <= p.first) {
          if(a != p.first) it = intervals.insert(it, ii(a, p.first)) + 1; // the part of before first
          if(b > p.second) a = p.second; // check the rest for next loop;
          else if(b == p.second) {a = b; break;}
          else {                // a < p.first && b < p.second && b > p.first
            it = intervals.insert(it, ii(p.first, b)) + 1;
            // p.first = b;
            it = intervals.insert(it, ii(b, p.second)) + 1;
            it = intervals.erase(it);
            a = b;
            break;
          }
        }else if(a >= p.first && b <= p.second) { // [p.first, p.second] contains [a, b]
          if(a != p.first) it = intervals.insert(it, ii(p.first, a)) + 1;
          if(b != p.second) {
            it = intervals.insert(it, ii(a, b)) + 1;
            // p.first = b;
            it = intervals.insert(it, ii(b, p.second)) + 1;
            it = intervals.erase(it);
          }
          a = b;
          break;
        }
        else if(a >= p.first && b > p.second) {
          if(a != p.first) it = intervals.insert(it, ii(p.first, a)) + 1;
          // p.first = a;
          it = intervals.insert(it, ii(a, p.second)) + 1;
          it = intervals.erase(it)-1;
          a = p.second;
          if(it == intervals.end()) {a = b; break;}
        }
      }
      if(a != b) intervals.push_back(ii(a, b));
    }
    int interval_num = intervals.size();
    for(int i=0; i<n; i++) {
      ii p = viii[i].second;
      int u = viii[i].first;
      for(int j=0; j<interval_num; j++) {
        if(intervals[j].first >= p.first && intervals[j].second <= p.second) {
          res[u][n+1+j] = intervals[j].second - intervals[j].first;
          edges[u].push_back(n+1+j);
          edges[n+1+j].push_back(u);
        }
        if(intervals[j].first >= p.second) break;
      }
    }
    s = 0; t = n + interval_num + 1;
    for(int i=0; i<interval_num; i++) {
      res[n+1+i][t] = m * (intervals[i].second - intervals[i].first);
      edges[n+1+i].push_back(t);
      edges[t].push_back(n+1+i);
    }

    solve();

    if(mf != tot) printf("Case %d: No\n", ++kase);
    else {
      generate_ans();
      printf("Case %d: Yes\n", ++kase);
      for(int i=1; i<=n; i++) {
        printf("%d", (int)ans[i].size());
        for(int j=0; j<(int)ans[i].size(); j++) {
          printf(" (%d,%d)", ans[i][j].first, ans[i][j].second);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
