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
#include <stack>

using namespace std;
int n;
int target[1000+30];
int main() {
	while(cin >> n && n){
		while(cin >> target[1] && target[1]){
			for(int i=2; i<=n; i++){
				cin >> target[i];
			}
			bool flag = true;
			stack<int> s;
			int a = 1, b = 1;
			while(b <= n){
				if(a == target[b]){a++; b++;}
				else if(!s.empty() && s.top() == target[b]){b++; s.pop();}
				else if(a <= n) {s.push(a); a++;}
				else {flag = false; break;}
			}
			if(flag) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}