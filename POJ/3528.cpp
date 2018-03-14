#include <iostream>
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
	int t;
	cin >> t;
	while(t--){
		string  s;
		cin >> s;
		int len = s.length();
		int k;
		cin >> k;
		while(k--){
			for(int i=0; i<len;i++){
				if(s[i+1]<s[i]) {
					s.erase(i, 1);
					break;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}