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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
string s;
int len;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  len = s.length();
  int i = 0, j = len - 1;
  string a;
  while(j - i >= 3) {
    if(s[i] == s[j]) {
      a.push_back(s[i]);
      i++; j--;
    } else if(s[i] == s[j-1]) {
      a.push_back(s[i]);
      i++; j-=2;
    } else {
      a.push_back(s[i+1]);
      if(s[i+1] == s[j]) j--;
      else j-=2;
      i+=2;
    }
  }
  string b = a;
  if(j >= i) a.push_back(s[i]);
  reverse(b.begin(), b.end());
  cout << a << b << endl;
  return 0;
}
