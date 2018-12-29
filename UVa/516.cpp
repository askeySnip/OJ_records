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
vi primes;
int a[1024];
bitset<35000> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  REP(i, 2, 35000) {
    if(bs[i]) {
      primes.push_back(i);
      for(int j=i*i; j<35000; j+=i) bs[j] = 0;
    }
  }
}

int main() {
  char ch;
  sieve();
  while(scanf("%d", &a[0])) {
    if(a[0] == 0) break;
    int id = 1;
    while((ch = getchar()) == ' ') scanf("%d", &a[id++]);
    int value = 1;
    for(int i=0; i<id; i+=2) {
      value *= pow(a[i], a[i+1]);
    }
    value--;
    vii ans;
    REP(i, 0, primes.size()) {
      if(primes[i] * primes[i] > value) break;
      if(value%primes[i]) continue;
      int cnt = 0;
      while(value%primes[i] == 0) value/=primes[i], cnt++;
      ans.push_back(ii(primes[i], cnt));
    }
    if(value != 1) ans.push_back(ii(value, 1));
    for(int i=ans.size()-1; i>=0; i--) {
      printf("%d %d", ans[i].first, ans[i].second);
      if(i) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
