/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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
typedef long long ll;
int n;
int kase = 0;
char mp[88][88];
ll path[1000];
vector<ll> ans;
struct Node{
	int color;
	Node *ch1, *ch2, *ch3, *ch4;
	string s;
	Node(int c, Node *c1, Node *c2, Node *c3, Node *c4, string st):color(c), ch1(c1), ch2(c2), ch3(c3), ch4(c4), s(st){}
};
int encode(int n){	//5 -> 10
	int ret = 0;
	int base = 1;
	while(n){
		ret += (n%10) * base;
		n/=10;
		base *= 5;
	}
	return ret;
}
ll encode(string n){	//5 -> 10
	ll ret = 0L;
	ll base = 1L;
	for(int i=n.length()-1; i>=0; i--){
		ret += (n[i]-'0')*base;
		base *= 5L;
	}
	return ret;
}
string decode(ll n){	//10 -> 5
	string s;
	while(n){
		s = (char)((n%5)+'0') + s;
		n/=5;
	}
	return s;
}
void draw(string s){
	int row = 0, col = 0, len = n;
	for(int i=s.length()-1; i>=0; i--){
		len/=2;
		if(s[i] == '2'){
			col += len;
		}else if(s[i] == '3'){
			row += len;
		}else if(s[i] == '4'){
			row += len;
			col += len;
		}
	}
	for(int i=row; i<row+len; i++){
		for(int j=col; j<col+len; j++){
			mp[i][j] = '*';
		}
	}
}
void solve1(){
	n = -n;
	int cnt=0;
	ll t;
	while(scanf("%lld", &t) == 1 && t!=-1) path[cnt++] = t;
	memset(mp, '.', sizeof(mp));
	for(int i=0; i<cnt; i++){
		draw(decode(path[i]));
	}
	printf("Image %d\n", ++kase);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%c", mp[i][j]);
		}
		printf("\n");
	}
}
Node* build(int r, int c, int len, string s){
	if(len == 1){
		Node *p = new Node(mp[r][c]-'0', NULL, NULL, NULL, NULL, s);
		return p;
	}
	else{
		Node *p = new Node(-1, NULL, NULL, NULL, NULL, s);
		len /= 2;
		p->ch1 = build(r, c, len, '1'+s);
		p->ch2 = build(r, c+len, len, '2'+s);
		p->ch3 = build(r+len, c, len, '3'+s);
		p->ch4 = build(r+len, c+len, len, '4'+s);
		if(p->ch4->color == p->ch3->color && p->ch3->color == p->ch2->color && p->ch2->color == p->ch1->color) {
			p->color = p->ch4->color;
			delete p->ch1;
			delete p->ch2;
			delete p->ch3;
			delete p->ch4;
			p->ch1 = NULL;
			p->ch2 = NULL;
			p->ch3 = NULL;
			p->ch4 = NULL;
		}else{
			if(p->ch1->color == 1) ans.push_back(encode(p->ch1->s));
			if(p->ch2->color == 1) ans.push_back(encode(p->ch2->s));
			if(p->ch3->color == 1) ans.push_back(encode(p->ch3->s));
			if(p->ch4->color == 1) ans.push_back(encode(p->ch4->s));
		}
		return p;
	}
}
void dfs(Node *u, string s){
	if(u->color == -1){
		dfs(u->ch1, '1'+s);
		dfs(u->ch2, '2'+s);
		dfs(u->ch3, '3'+s);
		dfs(u->ch4, '4'+s);
	}else if(u->color == 1){
		ans.push_back(encode(s));
	}else return;
}
void solve2(){ 
	ans.clear();
	for(int i=0; i<n; i++){
		scanf("%s", mp[i]);
	}
	Node *root = build(0, 0, n, "");
	if(root->color == 1) ans.push_back(0);
//	dfs(root, "");
	sort(ans.begin(), ans.end());
	printf("Image %d\n", ++kase);
	int len = ans.size();
	for(int i=0; i<len; i++){
		printf("%lld", ans[i]);
		if((i+1)%12 == 0) printf("\n");
		else if(i!=len-1) printf(" ");
	}
	if(len!=0 && len%12!=0) printf("\n");
	printf("Total number of black nodes = %d\n", len);
}
int main() {
	while(scanf("%d", &n) && n){
		if(kase) printf("\n");
		if(n < 0) solve1();
		else solve2();
	}
	return 0;
}