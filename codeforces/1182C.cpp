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
typedef pair<string, string> ss;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
bool isVowel(char c) {
  if(c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u') return true;
  return false;
}
int vowelCount(string& s) {
  int count = 0;
  for(auto& c : s) {
    if(isVowel(c)) count++;
  }
  return count;
}

char lastVowel(string& s) {
  for(int i=s.length()-1; i>=0; i--) {
    if(isVowel(s[i])) return s[i];
  }
  return 'b';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n;
  map<int, map<char, vector<string> > > mp;
  REP(i, 0, n) {
    cin >> s;
    int cnt = vowelCount(s);
    char c = lastVowel(s);
    mp[cnt][c].push_back(s);
  }
  vector<ss> comp, semi;
  for(auto& same_counts: mp) {
    for(auto& same_last: same_counts.second) {
      while(same_last.second.size() >= 2) {
        string f = same_last.second.back();
        same_last.second.pop_back();
        string snd = same_last.second.back();
        same_last.second.pop_back();
        comp.push_back(ss(f, snd));
      }
    }
    vector<string> remaining;
    for(auto& same_last: same_counts.second) {
      for(auto& word : same_last.second) remaining.push_back(word);
      same_last.second.clear();
    }
    while(remaining.size() >= 2) {
      string f = remaining.back(); remaining.pop_back();
      string snd = remaining.back(); remaining.pop_back();
      semi.push_back(ss(f, snd));
    }

  }

  vector<ss> ans;
  while(!comp.empty() && !semi.empty()) {
    ss sm = semi.back(); semi.pop_back();
    ss cm = comp.back(); comp.pop_back();
    ans.push_back(ss(sm.first, cm.first));
    ans.push_back(ss(sm.second, cm.second));
  }
  while(comp.size()>=2) {
    ss f = comp.back(); comp.pop_back();
    ss snd = comp.back(); comp.pop_back();
    ans.push_back(ss(f.first, snd.first));
    ans.push_back(ss(f.second, snd.second));
  }
  cout << ans.size() / 2 << endl;;
  for(ss& w : ans) cout << w.first << " " << w.second << endl;
  return 0;
}
