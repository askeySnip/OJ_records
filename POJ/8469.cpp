#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
int main() {
	string s1, s2, t;
	cin >> s1 >> s2;
	t = s1;
	int ans = 10000, anst = 0;
	int n = s1.length();
	for(int i=1; i<n; i++){
		if(t[i-1] != s2[i-1]){
			t[i-1] = (1 - t[i-1] + '0') + '0';
			t[i] = (1 - t[i] + '0') + '0';
			t[i+1] = (1 - t[i+1] + '0') + '0';
			anst++;
		}
	}
//	cout << t << " " << anst << endl;
	if(t[n-1] == s2[n-1]) ans = min(ans, anst);
	t = s1;
	anst = 1;
	t[0] = (1 - t[0] + '0') + '0';
	t[1] = (1 - t[1] + '0') + '0';
	for(int i=1; i<n; i++){
		if(t[i-1] != s2[i-1]){
			t[i-1] = (1 - t[i-1] + '0') + '0';
			t[i] = (1 - t[i] + '0') + '0';
			t[i+1] = (1 - t[i+1] + '0') + '0';
			anst++;
		}
	}
	if(t[n-1] == s2[n-1]) ans = min(ans, anst);
	if(ans == 10000) cout << "impossible" << endl;
	else cout << ans << endl;
	return 0;
}