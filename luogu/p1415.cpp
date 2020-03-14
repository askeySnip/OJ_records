/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3fffffff;
const int mod = 1e9 + 7;

// struct

// data
char s[510];
int n;
int f1[510], f2[510];

int check(int a, int b, int c, int d) {
  if (d == 0) return 1;
  string s1, s2;
  while (s[a] == '0') a++;
  while (s[c] == '0') c++;
  for (; a <= b; a++) s1 += s[a];
  for (; c <= d; c++) s2 += s[c];
  if (s1.size() > s2.size())
    return 1;
  else if (s1.size() < s2.size())
    return 0;
  else {
    if (s1 == s2) return -1;
    return s1 > s2;
  }
}

void solve1() {
  for(int i=1; i<=n; i++) {
    f1[i] = 1;
    for (int j = i; j >= 1; j--) {
      if (check(j, i, f1[j - 1], j - 1) == 1) {
        f1[i] = j;
        break;
      }
    }
  }
}

void solve2() {
  f2[f1[n]] = n;
  int l = f1[n] - 1;
  while (l && s[l] == '0') f2[l--] = n;
  for (; l; l--) {
    f2[l] = l;
    for (int j = f1[n] - 1; j >= l; j--) {
      if (check(l, j, j + 1, f2[j + 1]) == 0) {
        f2[l] = j;
        break;
      }
    }
  }
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  solve1();
  solve2();
  int cur = 1;
  while (cur <= n) {
    REP(i, cur, f2[cur] + 1) putchar(s[i]);
    cur = f2[cur] + 1;
    if (cur <= n) putchar(',');
  }
  putchar('\n');
  return 0;
}
