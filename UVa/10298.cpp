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
char s[1000024];
int len = 0;

bool check(int t) {
  REP(i, 0, t) {
    for(int j=i; j<len; j+=t) {
      if(s[j] != s[i]) return false;
    }
  }
  return true;
}
int main() {

  while(scanf("%s", s), s[0] != '.') {
    len = strlen(s);
    REP(i, 1, len+1) {
      if(len%i == 0) {
        if(check(i)) {
          printf("%d\n", len / i);
          break;
        }
      }
    }
  }
  return 0;
}
