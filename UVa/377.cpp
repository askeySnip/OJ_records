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
int num1, num2;
char s[10];

int decode() {
  int len = strlen(s);
  int ret = 0;
  REP(i, 0, len) {
    if(s[i] == 'U') {
      ret |= (1 << ((len-1-i)*2));
    } else if(s[i] == 'C') {
      ret |= (2 << ((len-1-i)*2));
    } else if(s[i] == 'D') {
      ret |= (3 << ((len-1-i)*2));
    }
  }
  return ret;
}

int op() {
  char c = s[0];
  if(c == 'A') return num1+num2;
  else if(c == 'R') return (num2 >> 2);
  else if(c == 'L') return (num2 << 2);
  else return num2;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("COWCULATIONS OUTPUT\n");
  while(n--) {
    scanf("%s", s);
    num1 = decode();
    scanf("%s", s);
    num2 = decode();
    REP(i, 0, 3){
    scanf("%s", s);
    num2 = op();
    }
    scanf("%s", s);
    if(num2 == decode()) {
      printf("YES\n");
    }else {
      printf("NO\n");
    }
  }
  printf("END OF OUTPUT\n");
  return 0;
}
