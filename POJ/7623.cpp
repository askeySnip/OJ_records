/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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
#include <cmath>

using namespace std;
int k, ans;
int n[5];
int t[5];
void check(int a, int b){
	int x = a*n[0] + b;
	int c = x - n[1] * b;
	if(c == a || c == b) return;
	int d = x - n[2] * c;
	if(d == a || d == b || d == c) return;
	int e = x - n[3] * d;
	if(e == a || e == b || e == c || e == d) return;
	int f = x - n[4] * e;
	if(f == a && ans > x){
		t[0] = a;
		t[1] = b;
		t[2] = c;
		t[3] = d;
		t[4] = e;
		ans = x;
	}
}
int main() {
	cin >> k;
	for(int i=0; i<5; i++) cin >> n[i];
	k*=100;
	ans = k+1;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			if(i==j) continue;
			int x = i*n[0]+j;
			check(i, j);
		}
	}
	if(ans != k+1){
		cout << ans;
		for(int i=0; i<5; i++){
			cout << " " << t[i];
		}
		cout << endl;
	}else{
		cout << "not found" << endl;
	}
	return 0;
}