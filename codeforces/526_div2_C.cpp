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
const int mod = 1e9+7;

// data
char s[100005];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  vi blocks;
  int start = 0, b = -1, c = 0;
  REP(i, 0, len) {
    if(s[i] == 'a') {
      if(start > b) c++;
      else {
        start = i; c++;
      }
    } else if(s[i] == 'b') {
      if(c != 0) blocks.push_back(c);
      c = 0;
      b = i;
    }
  }
  if(c != 0) blocks.push_back(c);
  ll ans = 1L;
  REP(i, 0, blocks.size()) {
    ans = ans * (blocks[i] + 1);
    ans %= mod;
  }
  printf("%lld\n", ans-1L);
  return 0;
}
