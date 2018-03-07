#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
string s1, s2;
bool check(){
	int j=0;
	for(int i=0; i<s2.length(); i++){
		if(s2[i] == s1[j]) j++;
	}
	return j == s1.length();
}
int main() {
	
	while(cin >> s1 >> s2){
		if(check()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}