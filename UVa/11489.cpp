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
  int t;
  scanf("%d", &t);
  char line[1024];
  int mem[3] = {};
  int kase = 0;
  while(t--) {
    mem[0] = mem[1] = mem[2] = 0;
    scanf("%s", line);
    int len = strlen(line);
    REP(i, 0, len) {
      mem[(line[i]-'0')%3]++;
    }
    // REP(i, 0, 3) cout << mem[i] << endl;
    while(mem[1] >= 3 && mem[2] + 1 < mem[1]) mem[1] -= 3;
    while(mem[2] >= 3 && mem[1] + 1 < mem[2]) mem[2] -= 3;
    if(abs(mem[1] - mem[2]) > 1) printf("Case %d: T\n", ++kase);
    else {
      mem[0] += abs(mem[1] - mem[2]);
      if(mem[0]&1) {
        printf("Case %d: S\n", ++kase);
      } else {
        printf("Case %d: T\n", ++kase);
      }
    }
  }
  return 0;
}
