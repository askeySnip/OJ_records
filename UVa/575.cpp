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
  char s[100];
  while(scanf("%s", s) == 1) {
    if(s[0] == '0') break;
    int len = strlen(s);
    int base = 1;
    int ans = 0;
    for(int i=len-1; i>=0; i--) {
      ans += base * (s[i]-'0');
      base = (base << 1)|1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
