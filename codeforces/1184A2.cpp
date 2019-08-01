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
char s[200048];

int getAns(int k) {
  for(int i=0; i<k; i++) {
    int cnt = 0;
    for(int j=i; j<n; j+=k) {
      if(s[j] == '1') cnt++;
    }
    if(cnt%2) return 0;
  }
  return 1;
}

int gcd(int a, int b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  map<int, int> mp;
  bool f = true;
  for(int i=0; i<n; i++) {
    if(s[i] == '1') {
      f = false;
      break;
    }
  }
  for(int i=1; i<n; i++) {
    if(n%i == 0) {
      mp[i] = getAns(i);
    }
  }
  int ans = (f ? 1 : 0);
  for(int i=1; i<n; i++) {
    if(n%i == 0) {
      ans += mp[i];
    } else {
      ans += mp[gcd(n, i)];
    }
  }
  cout << ans << endl;
  return 0;
}
