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

using namespace std;

class MajoritySubarray {
private:
  vector<int> ft;
  void fenwick_add(int i, int k) {
    while(i < (1<<18)) {
      ft[i] += k;
      i += i&(-i);
    }
  }
  int fenwick_sum(int i) {
    int s = 0;
    while(i > 0) {
      s += ft[i];
      i -= i&(-i);
    }
    return s;
  }
public:
  long long getCount(int n, int seed, int m) {
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      a[i] = (seed >> 16) % m;
      seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    }
    ft.resize(1<<18);
    long long ans = 0LL;
    for(int x=0; x<m; x++) {
      fill(ft.begin(), ft.end(), 0);
      int bal = n;
      for(int i=0; i<n; i++) {
        fenwick_add(bal, 1);
        if(a[i] == x) bal++; else bal--;
        ans += fenwick_sum(bal-1);
      }
    }
    return ans;
  }
};

// CUT begin
ifstream data("MajoritySubarray.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int seed, int m, long long __expected) {
    time_t startClock = clock();
    MajoritySubarray *instance = new MajoritySubarray();
    long long __result = instance->getCount(n, seed, m);
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
        int n;
        from_stream(n);
        int seed;
        from_stream(seed);
        int m;
        from_stream(m);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, seed, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1539336411;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MajoritySubarray (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
