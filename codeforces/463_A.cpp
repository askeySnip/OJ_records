#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	string s;
	cin >> s;
	int i=s.length()-1;
	for(; i>=0; i--){
		s = s + s[i];
	}
	cout << s << endl;
	return 0;
}