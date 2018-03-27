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
struct Node{
	vector<string> vs;
	Node *next, *pre;
	Node(vector<string> v, Node *next=NULL, Node *pre=NULL, Node * down=NULL):vs(v),next(next), pre(pre){}
};
string s;
vector<string> hv;
Node *head = new Node(hv);
void del_list(){
	Node *p = head->next;
	while(p){
		Node *t = p->next;
		delete p;
		p = t;
	}
}
void rm_node(Node* p){
	Node *n = p->next;
	Node *pr = p->pre;
	pr->next = n;
	if(n) n->pre = pr;
	delete p;
}
inline bool check(string s1, string s2){
	if(s1[0] == s2[0] || s1[1] == s2[1]) return true;
	else return false;
}
void solve(){
	int n = 52;
	while(true){
		bool flag = true;
		Node *p = head->next;
		while(p!=NULL){
			Node *lll = p;
			for(int i=0; i<3; i++){
				if(lll == head) break;
				lll = lll->pre;
			}
			if(lll != head){
				if(check(lll->vs.back(), p->vs.back())){
//					cout << lll->vs.back() << " " << p->vs.back() << endl;
					lll->vs.push_back(p->vs.back());
					p->vs.pop_back();
					if(p->vs.size() == 0) {rm_node(p); n--;}
					flag = false;
					break;
				}
			}
			if(p->pre != head){
				if(check(p->pre->vs.back(), p->vs.back())){
//					cout << p->pre->vs.back() << " " << p->vs.back() << endl;
					p->pre->vs.push_back(p->vs.back());
					p->vs.pop_back();
					if(p->vs.size() == 0){rm_node(p);n--;}
					flag = false;
					break;
				}
			}
			p = p->next;
		}
		if(flag) break;
	}
	if(n != 1) printf("%d piles remaining:", n);
	else printf("1 pile remaining:");
	Node *p = head->next;
	while(p){
		printf(" %lu", p->vs.size());
		p = p->next;
	}
	printf("\n");
}
int main() {
	while(cin >> s && s[0]!='#'){
		del_list();
		vector<string> v;
		v.push_back(s);
		Node *p = new Node(v);
		head->next = p;
		p->pre = head;
		for(int i=1; i<52; i++){
			cin >> s;
			vector<string> vv;
			vv.push_back(s);
			Node *t = new Node(vv);
			p->next = t;
			t->pre = p;
			p = p->next;
		}
		solve();
	}
	return 0;
}