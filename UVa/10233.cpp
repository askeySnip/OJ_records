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


double getx(double n) {
  ll r = ll(sqrt(n));
  ll x = n - r*r;
  return double(x-r)*0.5;
}

double gety(double n) {
  ll r = ll(sqrt(n));
  ll x = n - r*r;
  if(x&1) {
    return (1.0/3.0 + (r-1.0)/2.0)*sqrt(3);
  }else {
    return r*sqrt(3)*0.5;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  double n, m;
  while(cin >> n >> m) {
    double a = getx(n), b = gety(n);
    double aa = getx(m), bb = gety(m);
    printf("%.3f\n", sqrt((a-aa)*(a-aa)+(b-bb)*(b-bb)));
  }
  return 0;
}
