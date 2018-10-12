#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

class TeleportationMaze {
    public:
    int pathLength(vector<string> a, int r1, int c1, int r2, int c2) {
      r = a.size(); c = a[0].size();
      memset(vist, 0, sizeof vist);
      x1 = r1; y1 = c1; x2 = r2; y2 = c2;
      priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
      q.push(make_pair(0, make_pair(x1, y1)));
      while(!q.empty()) {
        int v = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(x == x2 && y == y2) return v;
        if(vist[x][y]) continue;
        vist[x][y] = 1;
        int tx = x-1, ty;
        if(x > 0 && a[x-1][y] == '.') {
          if(!vist[x-1][y]) q.push(make_pair(v+1, make_pair(x-1, y)));
        }
        else
          while(tx>=0){
            if(a[tx][y] == '.') {
              if(!vist[tx][y]) {
                q.push(make_pair(v+2, make_pair(tx, y)));
              }
              break;
            }
            tx--;
          }
        tx = x+1;
        if(x < r-1 && a[x+1][y] == '.') {
          if(!vist[x+1][y]) q.push(make_pair(v+1, make_pair(x+1, y)));
        }else
        while(tx<r) {
          if(a[tx][y] == '.') {
            if(!vist[tx][y]) q.push(make_pair(v+2, make_pair(tx, y)));
            break;
          }
          tx++;
        }
        ty = y-1;
        if(y > 0 && a[x][y-1] == '.') {
          if(!vist[x][y-1]) q.push(make_pair(v+1, make_pair(x, y-1)));
        }else
        while(ty>=0) {
          if(a[x][ty] == '.') {
            if(!vist[x][ty]) q.push(make_pair(v+2, make_pair(x, ty)));
            break;
          }
          ty--;
        }
        ty = y+1;
        if(y < c-1 && a[x][y+1] == '.') {
          if(!vist[x][y+1]) q.push(make_pair(v+1, make_pair(x, y+1)));
        }
        while(ty<c) {
          if(a[x][ty] == '.') {
            if(!vist[x][ty]) q.push(make_pair(v+2, make_pair(x, ty)));
            break;
          }
          ty++;
        }
      }
      return -1;
    }
private:
  int x1, y1, x2, y2;
  int r, c;
  int ans = 0;
  int vist[60][60];

};

// CUT begin
ifstream data("TeleportationMaze.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> a, int r1, int c1, int r2, int c2, int __expected) {
    time_t startClock = clock();
    TeleportationMaze *instance = new TeleportationMaze();
    int __result = instance->pathLength(a, r1, c1, r2, c2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> a;
        from_stream(a);
        int r1;
        from_stream(r1);
        int c1;
        from_stream(c1);
        int r2;
        from_stream(r2);
        int c2;
        from_stream(c2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, r1, c1, r2, c2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1539327939;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TeleportationMaze (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
