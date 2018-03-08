#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
bool cmp(pair<string, int>& p1, pair<string, int>& p2){
	if(p1.first[0] == '-' && p2.first[0] != '-') return true;
	if(p1.first[0] != '-' && p2.first[0] == '-') return false;
//	int t1 = stoi(p1.first.substr(0, p1.second));
//	int t2 = stoi(p2.first.substr(0, p2.second));
//	if(t1 != t2) return t1<t2;else
	if(p1.first[0] == '-') {
		if(p1.second > p2.second) return true;
		else if(p1.second < p2.second) return false;
		else if(p1.first.substr(0,p1.second) != p2.first.substr(0,p2.second)) 
			return p1.first.substr(0,p1.second) > p2.first.substr(0,p2.second);
		else
			return p1.first.substr(p1.second+1) > p2.first.substr(p2.second+1);
	}
	else {
		if(p1.second < p2.second) return true;
		else if(p1.second > p2.second) return false;
		else if(p1.first.substr(0,p1.second) != p2.first.substr(0,p2.second)) 
			return p1.first.substr(0,p1.second) < p2.first.substr(0,p2.second);
		else
			return p1.first.substr(p1.second+1) < p2.first.substr(p2.second+1);
//		return p1.first.substr(p1.second+1) < p2.first.substr(p2.second+1);
	}
}
int mx=0;
void print(pair<string, int>& p){
	for(int i=0; i< mx - p.second; i++) cout << " ";
	cout << p.first << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<string, int> > l;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<s.length(); j++){
			if(s[j] == '.') {
				if(mx<j) mx = j;
				l.push_back(make_pair(s, j));
				break;
			}
		}
	}
//	sort(l.begin(), l.end(), cmp);
	for(int i=0; i<n; i++){
//		cout << l[i].first << endl;
		print(l[i]);
	}
	return 0;
}