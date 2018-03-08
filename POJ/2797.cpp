#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
struct Trie{
	Trie *next[26];
	int num;
	Trie(){
		for(int i=0; i<26; i++){
			next[i] = NULL;
		}
		num = 0;
	}
};
Trie root;
void Insert(string& s){
	Trie *p = &root;
	for(int i=0; i<s.length(); i++){
		int t = s[i] - 'a';
		if(p->next[t] == NULL)
			p->next[t] = new Trie;
		p = p->next[t];
		p->num++;
	}
}
void Find(string& s){
	Trie *p = &root;
	for(int i=0; i<s.length(); i++){
		int t = s[i] - 'a';
		if(p->next[t] == NULL) return;
		p = p->next[t];
		cout << s[i];
		if(p->num == 1) return ;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	vector<string> strs;
	while(cin >> s){
//		if(s == "stop") break;
		strs.push_back(s);
		Insert(s);
	}
	for(int i=0; i<strs.size(); i++){
		cout << strs[i] << " ";
		Find(strs[i]);
		cout << endl;
	}
	return 0;
}