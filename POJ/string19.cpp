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
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	string ss1 = s1 + s1;
	string ss2 = s2 + s2;
	if((s1.length() >= s2.length() && ss1.find(s2) != string::npos) || (s2.length() >= s1.length() && ss2.find(s1) != string::npos)){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	return 0;
}