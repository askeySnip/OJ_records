#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class ChristmasPudding {
 public:
  long long eat(int, long long, long long, vector<int>, vector<int>,
                vector<int>, int);
};

bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return a.first > b.first;
}

long long ChristmasPudding::eat(int N, long long Vall, long long Vsweet,
                                vector<int> Vprefix, vector<int> Tprefix,
                                vector<int> Sprefix, int seed) {
  long long state = seed;
  for (int i = Vprefix.size(); i < N; i++) {
    state = (state * 1103515245 + 12345) % (1 << 31);
    Vprefix.push_back((int)(1 + (state % 1000000)));
    state = (state * 1103515245 + 12345) % (1 << 31);
    Tprefix.push_back((int)(1 + (state % 1000000)));
    state = (state * 1103515245 + 12345) % (1 << 31);
    Sprefix.push_back((int)((state / 1024) % 2));
    // cout << V[i] << " " << T[i] << " " << S[i] << endl;
  }
  vector<pair<long long, long long>> sweet;
  vector<pair<long long, long long>> savory;
  for (int i = 0; i < N; i++) {
    if (Sprefix[i])
      sweet.push_back({Tprefix[i], Vprefix[i]});
    else
      savory.push_back({Tprefix[i], Vprefix[i]});
  }
  priority_queue<pair<long long, long long>> pq;
  for (int i = 0; i < sweet.size(); i++) {
    pq.push(sweet[i]);
  }
  long long ans = 0;
  Vsweet = min(Vall, Vsweet);
  while (!pq.empty() && Vsweet) {
    auto p = pq.top();
    pq.pop();
    long long t = min(p.second, Vsweet);
    ans += t * p.first;
    Vsweet -= t;
    Vall -= t;
    p.second -= t;
    if (p.second) pq.push(p);
  }
  for (int i = 0; i < savory.size(); i++) {
    pq.push(savory[i]);
  }
  while (!pq.empty() && Vall) {
    auto p = pq.top();
    pq.pop();
    long long t = min(p.second, Vall);
    ans += t * p.first;
    Vall -= t;
  }
  return ans;
}

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
