#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, string> > v;
	for(int i=0; i<m; i++){
		string s;
		cin >> s;
		int t = 0;
		for(int j=0; j<n; j++){
			for(int k=j+1; k<n; k++){
				if(s[j] > s[k]) t ++;
			}
		}
		v.push_back(make_pair(t, s));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		cout << v[i].second << endl;
	}
	return 0;
}