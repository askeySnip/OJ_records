#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int lt[30];
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		pair<char, int> p;
		p = make_pair('a', 0);
		memset(lt, 0, sizeof(lt));
		for(int i=0; i<s.length(); i++){
			lt[s[i]-'a']++;
		}
		for(int i=0; i<26; i++){
			if(p.second < lt[i]){
				p = make_pair(i+'a', lt[i]);
			}
		}
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}