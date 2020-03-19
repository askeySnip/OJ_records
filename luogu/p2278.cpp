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
struct proc {
  int pid, arr_time, proc_time, priority;
  proc() { pid = arr_time = proc_time = priority = -1; }
  bool operator<(const proc& other) const {
    if (priority == other.priority) return arr_time > other.arr_time;
    return priority < other.priority;
  }
};

// data

int main() {
  priority_queue<proc> pq;
  proc p;
  int cur_time = 0;
  proc cur_proc = proc();
  // int cnt = 0;
  while (scanf("%d%d%d%d", &p.pid, &p.arr_time, &p.proc_time,
                          &p.priority) == 4) {
    while (cur_proc.pid != -1 && p.arr_time - cur_time >= cur_proc.proc_time) {
      printf("%d %d\n", cur_proc.pid, cur_time + cur_proc.proc_time);
      cur_time += cur_proc.proc_time;
      if (pq.empty()) {
        cur_proc.pid = -1;
        break;
      }
      cur_proc = pq.top();
      pq.pop();
    }
    pq.push(p);
    int runtime = p.arr_time - cur_time;
    if (cur_proc.pid == -1)
      cur_proc = pq.top(), cur_time = p.arr_time;
    else if (pq.top().pid != cur_proc.pid) {
      cur_proc.proc_time -= runtime;
      pq.push(cur_proc);
      cur_proc = pq.top();
      cur_time = p.arr_time;
    }
    pq.pop();
    // cnt++;
  }
  while (!pq.empty()) {
    printf("%d %d\n", cur_proc.pid, cur_proc.proc_time + cur_time);
    cur_time += cur_proc.proc_time;
    cur_proc = pq.top();
    pq.pop();
  }
  printf("%d %d\n", cur_proc.pid, cur_proc.proc_time + cur_time);
  return 0;
}
