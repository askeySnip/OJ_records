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
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
struct Metrix{
	int r, c;
	Metrix(int a=0, int b=0):r(a), c(b){}
}m[30];
int main() {
	int n;
	cin >> n;
	char c;
	for(int i=0; i<n; i++){
		cin >> c;
		cin >> m[c-'A'].r >> m[c-'A'].c;
	}
	string st;
	while(cin >> st){
		int ans = 0;
		bool flag = true;
		stack<Metrix> s;
		for(int i=0; i<st.length(); i++){
			if(isalpha(st[i])){
				s.push(m[st[i]-'A']);
			}else if(st[i] == ')'){
				Metrix m2 = s.top(); s.pop();
				Metrix m1 = s.top(); s.pop();
				if(m1.c != m2.r){
					flag = false;
					break;
				}else{
					s.push(Metrix(m1.r, m2.c));
					ans += m1.r * m1.c * m2.c;
				}
			}
		}
		if(flag) cout << ans << endl;
		else cout << "error" << endl;
	}
	return 0;
}