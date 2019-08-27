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
#define EPS 1e-9

struct line{
  double a, b, c;
};
// data
int n;
vii points;
vector<line> lines;

line points2line(ii a, ii b) {
  line l;
  if(a.first == b.first) {
    l.a = 1.0, l.b = 0, l.c = -a.first;
  } else {
    l.a = -(double)(a.second - b.second) / (a.first - b.first);
    l.b = 1.0;
    l.c = -(double)(l.a * a.first) - a.second;
  }
  return l;
}

bool cmp(line a, line b) {
  if(a.b == b.b) {
    if(a.a == b.a) return a.c < b.c;
    return a.a < b.a;
  }
  return a.b < b.b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  points.resize(n);
  REP(i, 0, n) cin >> points[i].first >> points[i].second;
  REP(i, 0, n) {
    REP(j, i+1, n) {
      lines.push_back(points2line(points[i], points[j]));
    }
  }
  sort(lines.begin(), lines.end(), cmp);
  vi ans;
  int cnt = 1;
  int tot = lines.size();
  REP(i, 1, lines.size()) {
    if(fabs(lines[i].a - lines[i-1].a) < EPS && lines[i].b == lines[i-1].b) {
      if(fabs(lines[i].c - lines[i-1].c) < EPS) {
        tot--;
        continue;
      }
      else cnt++;
    } else {
      ans.push_back(cnt);
      cnt = 1;
    }
  }
  ans.push_back(cnt);
  ll res = 0;
  REP(i, 0, ans.size()) {
    res += ans[i] * (tot - ans[i]);
  }
  cout << res / 2 << endl;
  return 0;
}
