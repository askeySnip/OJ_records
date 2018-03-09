#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
int n, mx, sum, len;
int a[80];
int vist[80];
bool dfs(int stick, int overall, int j){
	int i;
	if(overall == sum) return true;
	if(stick == len) {
		stick = 0;
		j=0;
	}
	for(int i=j+1;i<n; i++){
		if(vist[i] || a[i]+stick > len) continue;
		vist[i] = 1;
		if(dfs(stick+a[i], overall + a[i], i)) return true;
		vist[i] = 0;
		while(i+1<n && a[i+1] == a[i]) i++;
		if(stick == 0 || stick+a[i] == len) break;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		if(!n) break;
		mx = 0;
		sum = 0;
		memset(vist, 0, sizeof(vist));
		for(int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
			if(mx < a[i]) mx = a[i];
		}
		sort(a, a+n, greater<int>());
		for(len=mx; ;len++){
			if(sum%len == 0){
				if(dfs(0, 0, -1)){
					cout << len << endl;
					break;
				}
			}
		}
	}
	return 0;
}