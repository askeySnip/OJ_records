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
int letters[26];
ll fac[21];
void generate_fac() {
  fac[0] = fac[1] = 1;
  REP(i, 2, 21) {
    fac[i] = fac[i-1] * ll(i);
  }
}

int main() {
  char word[30];
  int n;
  generate_fac();
  scanf("%d", &n);
  REP(i, 1, n+1) {
    scanf("%s", word);
    memset(letters, 0, sizeof(letters));
    int len = strlen(word);
    REP(j, 0, len) {
      letters[word[j]-'A']++;
    }
    ll ans = fac[len];
    REP(j, 0, 26) {
      ans /= fac[letters[j]];
    }
    printf("Data set %d: %lld\n", i, ans);
  }
  return 0;
}
