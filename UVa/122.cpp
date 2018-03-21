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
char s[1000];
struct Node{
	bool have_value;
	int v;
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL){}
};
Node* newnode(){ return new Node(); }

Node* root;
bool failed;
vector<int> ans;
void addnode(int v, char* s){
	int n = strlen(s);
	Node* u = root;
	for(int i=0; i<n; i++){
		if(s[i] == 'L'){
			if(u->left == NULL) u->left = newnode();
			u = u->left;
		}else if(s[i] == 'R'){
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}
	}
	if(u->have_value) failed = true;
	u->v = v;
	u->have_value = true;
}
bool read_input(){
	failed = false;
	root = newnode();
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',')+1);
	}
	return true;
}
bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node* u = q.front(); q.pop();
		if(!u->have_value) return false;
		ans.push_back(u->v);
		if(u->left != NULL) q.push(u->left);
		if(u->right != NULL) q.push(u->right);
	}
	return true;
}
int main() {
	while(read_input()){
		if(failed || !bfs(ans)){
			cout << "not complete" << endl;
			continue;
		}
		for(int i=0; i<ans.size()-1; i++){
			cout << ans[i] << " ";
		}
		cout << ans[ans.size()-1] << endl;
	}
	return 0;
}