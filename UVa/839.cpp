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
bool flag = true;
int check(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(!a && !c) {
		int ta = check();
		int tc = check();
		if(ta*b != tc*d){
			flag = false;
		}
		return ta+tc;
	}
	else if(!a && c){
		int ta = check();
		if(ta*b != c*d){
			flag = false;
		}
		return ta+c;
	}
	else if(a && !c){
		int tc = check();
		if(a*b != tc*d) flag = false;
		return tc+a;
	}else{
		if(a*b != c*d) flag = false;
		return a+c;
	}
	
}
int main() {
	int n;
	cin >> n;
	while(n--){
		flag = true;
		check();
		if(flag){
			cout << "YES" << endl;
		}else cout << "NO" << endl;
		if(n) cout << endl;
	}
	return 0;
}