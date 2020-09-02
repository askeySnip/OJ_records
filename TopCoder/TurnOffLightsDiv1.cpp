// BEGIN CUT HERE

// END CUT HERE
#line 5 "TurnOffLightsDiv1.cpp"
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class TurnOffLightsDiv1
{
public:
int getMinimumTime(vector <string> building)
{
//$CARETPOSITION$
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".##."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMinimumTime(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",".#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, getMinimumTime(Arg0)); }
	void test_case_2() { string Arr0[] = {".###.",".....",".#...","...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, getMinimumTime(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE
int main()
{
TurnOffLightsDiv1 ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
