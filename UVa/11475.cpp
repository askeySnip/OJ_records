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
char s[200024];
char t[200024];
int b[200024];
// bool check(int f, int e) {
//   while(f < e) {
//     if(s[f] != s[e]) return false;
//     f++; e--;
//   }
//   return true;
// }
// int main() {
//   while(scanf("%s", s) != EOF) {
//     int len = strlen(s);
//     int b = 0;
//     REP(i, 0, len) {
//       if(check(i, len-1)) {
//         b = i - 1;
//         break;
//       }
//     }
//     int t = len;
//     while(b >= 0) {
//       s[t++] = s[b--];
//     }
//     s[t] = '\0';
//     printf("%s\n", s);
//   }
//   return 0;
// }

void kmpProcess() {
  int i = 0, j = -1; b[0] = -1;
  int len = strlen(t);
  while(i < len) {
    while(j >= 0 && t[i] != t[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }
}

void kmpSearch() {
  int i = 0, j = 0;
  int len = strlen(s);
  while(i < len) {
    while(j >= 0 && s[i] != t[j]) j = b[j];
    i++; j++;
  }
  printf("%s%s\n", s, t+j);
}
int main() {
  while(scanf("%s", s) != EOF) {
    strcpy(t, s);
    reverse(t, t+strlen(t));
    kmpProcess();
    kmpSearch();
  }
}
