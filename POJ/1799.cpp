#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1010;
const int maxnode = 20010;
const int sigma = 27;
struct Trie{
	int sz, ch[maxnode][sigma];
	int val[maxnode], cnt[maxnode];
	void init(){
		sz = 0;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(cnt, 0, sizeof(cnt));
	}
	int id(char c) { return c-'a'; }
	void insert(string s, int v){
		int u = 0, n = s.size();
		for(int i=0; i<n; i++){
			int c = id(s[i]);
			if(!ch[u][c]) {
				sz++;
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz;
			}
			u = ch[u][c];
			cnt[u]++;
		}
		val[u] = v;
	}
	string find(string s){
		int u=0, n = s.size();
		for(int i=0; i<n; i++){
			int c=id(s[i]);
			u = ch[u][c];
			if(cnt[u] == 1 || (i == n-1))
				return s.substr(0, i+1);
		}
		return "";
	}
}trie;

string s[maxn];
int n=0;
int main() {
	trie.init();
	while(cin >> s[n]){
		
		trie.insert(s[n], n);
		n++;
	}
	for(int i=0; i<n; i++){
		cout << s[i] << " ";
		cout << trie.find(s[i]) << endl;
	}
	return 0;
}