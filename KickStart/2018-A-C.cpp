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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

char s[1000024];
ll x[1000024];
int L, N;
ll A, B, C, D;
vector<string> words;
int cnt[26];
unsigned long long dictHash[20020];
int Len[20020];

const int SEED = 13131;
unsigned long long getHash(char s, char e, int num[]) {
  unsigned long long ret = s * SEED + e;
  for (int i = 0; i < 26; i++) {
    ret = ret * SEED + num[i];
  }
  return ret;
}

void gen_s() {
  for (int i = 2; i < N; i++) {
    x[i] = (A % D) * (x[i - 1] % D) + (B % D) * (x[i - 2] % D) + C % D;
    x[i] %= D;
    s[i] = 97 + (x[i] % 26);
  }
}

int solve() {
  for (int i = 0; i < L; i++) {
    string& w = words[i];
    memset(cnt, 0, sizeof cnt);
    int l = w.length();
    for (int i = 0; i < l; i++) {
      cnt[w[i] - 'a']++;
    }
    dictHash[i] = getHash(w[0], w[l - 1], cnt);
    Len[i] = l;
  }
  sort(Len, Len + L);
  int totlen = unique(Len, Len + L) - Len;
  // cout << "totlen: " << totlen << endl;
  map<unsigned long long, int> mp;
  for (int i = 0; i < L; i++) {
    mp[dictHash[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < totlen; i++) {
    int len = Len[i];
    // cout << "len: " << len << endl;
    if (len > N) continue;
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j < len; j++) {
      cnt[s[j] - 'a']++;
    }
    unsigned long long tmp1 = getHash(s[0], s[len - 1], cnt);
    if (mp.count(tmp1)) {
      ans += mp[tmp1];
      mp.erase(tmp1);
    }
    for (int j = len; j < N; j++) {
      cnt[s[j - len] - 'a']--;
      cnt[s[j] - 'a']++;
      tmp1 = getHash(s[j - len + 1], s[j], cnt);
      if (mp.count(tmp1)) {
        ans += mp[tmp1];
        mp.erase(tmp1);
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int kase = 0;
  string tmp;
  while (t--) {
    words.clear();
    cin >> L;
    REP(i, 0, L) {
      cin >> tmp;
      words.push_back(tmp);
    }
    char s1, s2;
    cin >> s1 >> s2 >> N >> A >> B >> C >> D;
    s[0] = s1, s[1] = s2;
    x[0] = s1 - 'a' + 97;
    x[1] = s2 - 'a' + 97;
    gen_s();
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
