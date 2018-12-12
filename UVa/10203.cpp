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

// data
char line[100];
inline double xx(int x) {
  return x*x;
}
double dist(int a, int b, int c, int d) {
  return sqrt( xx(a-c) + xx(b-d) );
}

int main() {
  int t;
  gets(line);
  sscanf(line, "%d", &t);
  gets(line);
  gets(line);
  int a, b, c, d;
  double len = 0;
  while(t--) {
    while(gets(line)) {
      if(line[0] == '\0') {
        len /= 1000;
        len *= 2;
        int h = len / 20;
        int m = (len - 20*h)*3.0 + 0.5;
        if(m >= 60) {
          m = m%60;
          h++;
        }
        printf("%d:",h);
        if(m >= 10) printf("%d\n\n", m);
        else printf("0%d\n\n", m);
        len = 0;
        gets(line);
        break;
      }else {
        sscanf(line, "%d %d %d %d", &a, &b, &c, &d);
        len += dist(a, b, c, d);
      }
    }
  }
  len /= 1000;
  len *= 2;
  int h = len / 20;
  int m = (len - 20 * h) * 3.0 + 0.5;
  if(m >= 60) {
    m = m % 60; h++;
  }
  printf("%d:", h);
  if(m >= 10) printf("%d\n", m);
  else printf("0%d\n", m);
  return 0;
}
