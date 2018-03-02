#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
string s;
int len;
bool jud(int l, int r){
	while(l < r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			return false;
		}
	}
	return true;
}
int main() {
	cin >> s;
	len = s.length();
	for(int i=1; i<len; i++){
		for(int j=0; j+i<len; j++){
			if(jud(j, j+i)){
				cout << s.substr(j, i+1) << endl;
			}
		}
	}
	return 0;
}