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
int k, w;
char words[2][130];
int b[130];
int ans = 0;

void kmpPreprocess (char* t) {
  int i = 0, j = -1; b[0] = -1;
  int len = strlen(t);
  while(i < len) {
    while(j >= 0 && t[i] != t[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }
}

void kmpSearch(char* s, char* t) {
  int i = 0, j = 0;
  int len = strlen(s);
  while(i < len) {
    while(j >= 0 && t[j] != s[i]) j = b[j];
    i++; j++;
  }
  ans += (strlen(t) - j);
  //  cout << ans << endl;
}

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    ans = 0;
    scanf("%d %d", &k, &w);
    scanf("%s", words[0]);
    // kmpPreprocess(words[0]);
    ans += strlen(words[0]);
    int last = 0;
    REP(i, 1, w) {
      scanf("%s", words[1 - last]);
      kmpPreprocess(words[1 - last]);
      kmpSearch(words[last], words[1 - last]);
      last = 1 - last;
    }
    printf("%d\n", ans);
  }
  return 0;
}
