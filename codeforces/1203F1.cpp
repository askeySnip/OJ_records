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
int n, r;
ii ab[120];

bool cmp(ii a, ii b) {
  //if(a.first == b.first) return a.second > b.second;
  //return a.first > b.first;
  return a.first + a.second > b.first + b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> r;
  vii inc_r, dec_r;
  REP(i, 0, n) {
    cin >> ab[i].first >> ab[i].second;
    if(ab[i].second > 0) inc_r.push_back(ab[i]);
    else dec_r.push_back(ab[i]);
  }
  sort(inc_r.begin(), inc_r.end());
  bool f = true;
  REP(i, 0, inc_r.size()) {
    if(r >= inc_r[i].first) {
      r+=inc_r[i].second;
    } else {
      f = false;
      break;
    }
  }
  if(r < 0) f = false;
  if(!f) {
    cout << "NO" << endl;
    return 0;
  }
  sort(dec_r.begin(), dec_r.end(), cmp);
  REP(i, 0, dec_r.size()) {
    if(r >= dec_r[i].first) {
      r += dec_r[i].second;
    } else {
      f = false;
      break;
    }
  }
  if(r < 0) f = false;
  if(!f) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
