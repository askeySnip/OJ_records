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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int c, m, n;
vi path;

int gcd(int a, int b) {
  if (b == 0) return a;
  path.push_back(a / b);
  return gcd(b, a % b);
}

int main() {
  scanf("%d", &c);
  while (c--) {
    scanf("%d%d", &m, &n);
    path.clear();
    if (m < n) swap(m, n);
    gcd(m, n);
    int f = 0;
    REP(i, 0, path.size()) {
      if (path[i] > 1) {
        if (i % 2) {
          f = 2;
        } else {
          f = 1;
        }
        break;
      }
    }
    if (f == 1 || (f == 0 && path.size() % 2 == 1)) {
      printf("Stan wins\n");
    } else {
      printf("Ollie wins\n");
    }
  }
  return 0;
}
