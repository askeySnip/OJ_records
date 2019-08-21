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
int n, m;
vii pairs;

bool check(int x) {
  int c = 0;
  vi cnt(n+1);
  REP(i, 0, m) {
    if(pairs[i].first != x && pairs[i].second != x) {
      c++; cnt[pairs[i].first]++; cnt[pairs[i].second]++;
    }
  }
  if(*max_element(cnt.begin(), cnt.end()) == c) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  int a, b;
  REP(i, 0, m) {
    cin >> a >> b;
    pairs.push_back(ii(a, b));
  }
  if(check(pairs[0].first) || check(pairs[0].second)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
