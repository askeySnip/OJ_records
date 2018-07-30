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
int n, s, q, c;
vector<queue<int> > stationQueue;
void solve() {
	stack<int> carrier;
	int currPos = 0, ans = 0;
	while (true) {
		//unload cargo until fail or stack empty @ 1min
		// notice: can't split this, for maybe when unload to B makes top() equals postion.
		while (!carrier.empty()
				&& (carrier.top() == currPos
						|| stationQueue[currPos].size() < q)) {
			if (carrier.top() != currPos) {
				stationQueue[currPos].push(carrier.top());
			}
			carrier.pop();
			ans++;
		}

		//load cargo until stack full or q empty @ 1min
		while ((carrier.size() < s) && !stationQueue[currPos].empty()) {
			carrier.push(stationQueue[currPos].front());
			stationQueue[currPos].pop();
			ans++;
		}

		bool clear = carrier.empty();
		for (int i = 0; i < n; i++) {
			clear &= stationQueue[i].empty();
		}
		if (clear)
			break;

		//move @ 2 min
		currPos = (currPos + 1) % n;
		ans += 2;
	}

	printf("%d\n", ans);
}
int main() {
	int t, qi, d;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &s, &q);
		stationQueue.clear();
		stationQueue.resize(n);
		c = 0;
		for(int i=0; i<n; i++) {
			scanf("%d", &qi);
			for(int j=0; j<qi; j++) {
				scanf("%d", &d);
				stationQueue[i].push(d-1);
				c++;
			}
		}
		solve();
	}
	return 0;
}