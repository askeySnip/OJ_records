/*
ID: leezhen1
TASK: Parentheses Balance
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
char s[200];
bool check(){
	stack<char> stak;
	int len = strlen(s)-1;
	if(len == 0) return true;
	for(int i=0; i<len; i++){
		if(s[i] == '(' || s[i] == '[') stak.push(s[i]);
		else {
			if(stak.empty()) return false;
			char ch = stak.top();
			if((s[i] == ')' && ch == '(') ||(s[i] == ']' && ch == '[')) stak.pop();
			else return false;
		}
	}
	if(stak.empty())return true;
	else return false;
}
int main() {
	int t;
	fgets(s, 180, stdin);
	sscanf(s, "%d", &t);
	while(t--){
		fgets(s, 180, stdin);
		if(check()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}