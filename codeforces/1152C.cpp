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
ll a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  if(a < b) swap(a, b);
  if(a % b == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll dif = a - b;
  vi div;
  for(ll i=1; i*i<=dif; i++) {
    if(dif%i == 0) {
      div.push_back(i);
      if(i * i != dif) div.push_back(dif / i);
    }
  }
  sort(div.begin(), div.end());
  ll ans = (1LL << 62);
  int vl = 0;
  REP(i, 0, div.size()) {
    int nr = div[i];
    if(a % nr != b % nr) continue;
    if(a % nr == 0) {
      ll pans = (a * b) / __gcd(a, b);
      if(pans < ans) ans = pans, vl = 0;
    } else {
      ll pans = ((nr - a % nr + a) * (nr - b % nr + b)) / __gcd((nr - a%nr + a), (nr - b%nr + b));
      if(pans < ans) ans = pans, vl = nr - a % nr;
    }
  }
  cout << vl << endl;
  return 0;
}
