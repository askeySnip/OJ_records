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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data


int main() {
  ll n;
  while(scanf("%lld", &n), n) {
    ll r = (ll)sqrt(n);
    ll t = r * (r-1) + 1;
    if(r * r == n) {
      if(r&1) printf("1 %lld\n", r);
      else printf("%lld 1\n", r);
    }else {
      t = (r+1) * r + 1;
      if(r&1) {
        if(t > n) {
          printf("%lld %lld\n", r+1-(t-n), r+1);
        }else {
          printf("%lld %lld\n", r+1, r+1-(n-t));
        }
      }else {
        if(t > n) {
          printf("%lld %lld\n", r+1, r+1-(t-n));
        }else {
          printf("%lld %lld\n", r+1-(n-t), r+1);
        }
      }
    }
  }
  return 0;
}
