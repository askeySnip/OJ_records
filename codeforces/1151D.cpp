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
vii stu;

bool cmp(ii a, ii b) {
  return a.second - a.first < b.second - b.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  stu.resize(n);
  REP(i, 0, n) cin >> stu[i].first >> stu[i].second;
  sort(stu.begin(), stu.end(), cmp);
  ll ans = 0;
  REP(i, 0, n) {
    ans += (ll)stu[i].first * i + (ll)stu[i].second * (n-i-1);
  }
  cout << ans << endl;
  return 0;
}
