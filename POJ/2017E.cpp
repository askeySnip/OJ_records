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
	int n, m;
	cin >> n >> m;
	vector<string> dir;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		dir.push_back(s);
	}
	char s[130];
	getchar();
	for(int i=0; i<m; i++){
		
		gets(s);
//		cout << s << endl;
		string t;
		t = s;
//		cout << t << endl;
		for(int j=0; j<n; j++){
			int len = dir[j].length();
			auto pos = t.find(dir[j]);
//			cout << pos << endl;
			while(pos != string::npos){
				for(int k=0; k<len; k++){
					t[pos+k] = '*';
				}
				pos = t.find(dir[j]);
			}
		}
		cout << t << endl;
	}
	return 0;
}