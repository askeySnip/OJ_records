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
vi primes;
bitset<10000010> bs;
int n;
map<int, int> mp;

void sieve() {
  bs.set();
  primes.push_back(-1);
  bs[0] = bs[1] = 0;
  for(ll i=2; i<10000010; i++) {
    if(bs[i]) {
      for(ll j=i*i; j<10000010; j+=i) bs[j] = 0;
      primes.push_back((int)i);
    }
  }
}

int getGD(int t) {
  int ret = 0;
  REP(i, 1, primes.size()) {
    if(t%primes[i] == 0) {
      ret = primes[i];
      break;
    }
  }
  return t/ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  cin >> n;
  int b;
  REP(i, 0, 2*n) {
    cin >> b;
    mp[b]++;
  }
  vector<int> ans;
  for(auto it=mp.rbegin(); it!=mp.rend(); it++) {
    if(it->second == 0) continue;
    if(!bs[it->first]) {
      while(mp[it->first]) {
        int gd = getGD(it->first);
        if(mp.find(gd) != mp.end()) mp[gd]--;
        mp[it->first]--;
        ans.push_back(it->first);
      }
    }
  }
  for(auto it=mp.begin(); it!= mp.end(); it++) {
    if(it->second == 0) continue;
    while(mp[it->first]) {
      ans.push_back(it->first);
      mp[it->first]--;
      mp[primes[it->first]]--;
    }
  }
  REP(i, 0, ans.size()) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
