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
  int a, b;
  int cnt[100024] = {};
  for(int i=0; i<n-1; i++) {
    cin >> a >> b;
    cnt[a]++; cnt[b]++;
  }
  bool f = true;
  for(int i=1; i<=n; i++) {
    if(cnt[i] == 2) {
      f = false;
      break;
    }
  }
  if(f) printf("YES\n");
  else printf("NO\n");
  return 0;
}
