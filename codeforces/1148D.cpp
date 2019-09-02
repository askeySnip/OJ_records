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
vector<pair<int ,ii> > f, s;
int n;

bool cmp(pair<int, ii> a, pair<int, ii> b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  int a, b;
  REP(i, 0, n) {
    cin >> a >> b;
    if(a < b) f.push_back(make_pair(i, ii(a, b)));
    else s.push_back(make_pair(i, ii(a, b)));
  }
  if(f.size() > s.size()) {
    sort(f.begin(), f.end(), cmp);
    cout << f.size() << endl;
    for(int i=f.size()-1; i>=0; i--) {
      cout << f[i].first + 1 << " ";
    }
    cout << endl;
  }
  else {
    sort(s.begin(), s.end(), cmp);
    cout << s.size() << endl;
    REP(i, 0, s.size()) {
      cout << s[i].first + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
