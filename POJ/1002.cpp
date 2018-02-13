#include <iostream>
#include <string>
#include <map>

using namespace std;
string do_format(string s){
	string ret="";
	for(int i=0; i<s.length(); i++){
		ret += s[i];
		if(i == 2){
			ret += "-";
		}
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	map<string, int> mp;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		string ss = "";
		for(int i=0; i<s.length(); i++){
			if(s[i] < '0' || s[i] > '9'){
				char l = toupper(s[i]);
				if(l == 'A' || l =='B' || l == 'C'){
					ss += '2';
				}else if(l == 'D' || l =='E' || l == 'F'){
					ss += "3";
				}else if(l == 'G' || l == 'H' || l == 'I'){
					ss += "4";
				}else if(l == 'J' || l =='K' || l == 'L'){
					ss += "5";
				}else if(l == 'M' || l =='N' || l == 'O'){
					ss += "6";
				}else if(l == 'P' || l =='S' || l == 'R'){
					ss += "7";
				}else if(l == 'U' || l =='T' || l == 'V'){
					ss += "8";
				}else if(l == 'W' || l =='X' || l == 'Y'){
					ss += "9";
				}
			}else{
				ss += s[i];
			}
		}
//		cout << ss << endl;
		auto p = mp.find(ss);
		if(p != mp.end()){
			mp[ss] += 1;
		}else{
			mp[ss] = 1;
		}
	}
	int d = 0;
	for(auto i=mp.begin(); i!=mp.end(); i++){
		if(i->second > 1){
			cout << do_format(i->first) << " " << i->second << endl;
			d++;
		}
	}
//	cout << d;
	if(!d){
		cout << "No duplicates." << endl;
	}
	return 0;
}