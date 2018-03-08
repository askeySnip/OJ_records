#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	cin >> n;
	double a[1010];
	int f1[1010], f2[1010];
	vector<double> v;
	v.push_back(3.0);
	for(int i=0; i<n; i++){
		cin >> a[i];
		int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if(pos == v.size()) v.push_back(a[i]);
		else v[pos] = a[i];
		f1[i] = v.size();
//		cout << f1[i] << " ";
	}
//	cout << endl;
	v.clear();
	v.push_back(3.0);
	for(int i=n-1; i>=0; i--){
		int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if(pos == v.size()) v.push_back(a[i]);
		else v[pos] = a[i];
		f2[i] = v.size();
//		cout << f2[i] << " ";
	}
//	cout << endl;
	int ans = 1;
	for(int i=0; i<n-1; i++){
		if(f1[i]+f2[i+1] > ans) ans = f1[i]+f2[i];
	}
	cout << n - ans << endl;
	return 0;
}