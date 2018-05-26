/*
ID: leezhen1
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
char s[300];
vector<pair<string, string> > books;
vector<pair<string, string> > borrowed;
vector<pair<string, string> > returned;
map<string, string> b;
void deal(){
	int i=1;
	int len = strlen(s);
	string name, author;
	for(; i<len; i++){
		if(s[i]!='"') name+=s[i];
		else break;
	}
	for(; i<len; i++){
		if(s[i]=='b' && s[i+1] == 'y'){
			i+=2;
			break;
		} 
	}
	for(; i<len; i++){
		author+=s[i];
	}
	books.push_back(make_pair(author, name));
	b[name] = author;
}
void books2borrow(string name){
	pair<string, string> book = make_pair(b[name], name);
	for(auto it = books.begin(); it != books.end(); it++){
		if(*it == book){
			books.erase(it); break;
		}
	}
	borrowed.push_back(book);
}
void borrow2return(string name){
	pair<string, string> book = make_pair(b[name], name);
	for(auto it = borrowed.begin(); it!=borrowed.end(); it++){
		if(*it == book){
			borrowed.erase(it);
			break;
		}
	}
	returned.push_back(book);
}
void shelve(){
	sort(returned.begin(), returned.end());
	for(int i=0; i<returned.size(); i++){
		books.push_back(returned[i]);
	}
	sort(books.begin(), books.end());
	int j=0;
	for(int i=0; i<returned.size(); i++){
		pair<string, string>& book = returned[i];
		for(;j<books.size();j++){
			if(books[j] == book){
				if(j == 0) printf("Put \"%s\" first\n", books[j].second.c_str());
				else printf("Put \"%s\" after \"%s\"\n", books[j].second.c_str(), books[j-1].second.c_str());
				break;
			}
		}
	}
	printf("END\n");
	returned.clear();
}
void br_deal(){
	string name;
	int len = strlen(s);
	for(int i=8; i<len-1; i++) name+=s[i];
	if(s[0] == 'B'){
		books2borrow(name);
	}else if(s[0] == 'R'){
		borrow2return(name);
	}else if(s[0] == 'S'){
		shelve();
	}
}
int main() {
	while(gets(s) && strcmp(s, "END") != 0){
		deal();
	}
	
	while(gets(s) && strcmp(s, "END") != 0){
		br_deal();
	}
	return 0;
}