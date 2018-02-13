#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		vector<pair<int, int> > t;
		for(int i=0; i<n; i++){
			int s, e;
			cin >> s >> e;
			t.push_back(make_pair(e, s));
		}
		sort(t.begin(), t.end());
		int ret = 1;
		int f = t[0].first;
		for(int i=1; i<t.size(); i++){
			if(t[i].second >= f){
				ret ++;
				f = t[i].first;
			}
		}
		cout << ret << endl;
	}
	return 0;
}