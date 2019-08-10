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

string add(string a, string b) {
  int i = a.length() - 1;
  int j = b.length() - 1;
  bool carry = false;
  string ret = "";
  while(i >= 0 && j >= 0) {
    int t = a[i]-'0' + b[j]-'0';
    if(carry) t++;
    if(t>9) {
      t -= 10;
      carry = true;
    } else {
      carry = false;
    }
    ret = to_string(t) + ret;
    i--; j--;
  }
  while(i >= 0) {
    int t = a[i] - '0';
    if(carry) t++;
    if(t > 9) {
      t -= 10;
      carry = true;
    } else {
      carry = false;
    }
    ret = to_string(t) + ret;
    i--;
  }
  while(j >= 0) {
    int t = b[j] - '0';
    if(carry) t++;
    if(t > 9) {
      t -= 10;
      carry = true;
    } else {
      carry = false;
    }
    ret = to_string(t) + ret;
    j--;
  }
  if(carry) ret = '1' + ret;
  return ret;
}

bool bigger(string& a, string& b) {
  if(a.length() > b.length()) return true;
  else if(a.length() < b.length()) return false;
  else return a > b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int n;
  cin >> n;
  cin >> s;

    int mid = n / 2;
    int l = mid;
    while(s[l] == '0') l--;
    string a = add(s.substr(0, l), s.substr(l));
    l = mid+1;
    while(s[l] == '0') l++;
    string b = add(s.substr(0, l), s.substr(l));
    if(bigger(a, b)){
      cout << b << endl;
    }
    else{
      cout << a << endl;
    }

  return 0;
}
