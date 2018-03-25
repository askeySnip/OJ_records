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
	char ch;
	Node *leftch, *rightch;
	Node(char c, Node* l, Node* r):ch(c), leftch(l), rightch(l){}
};
char preord[30], inord[30];
Node* build(int l, int r, int l2, int r2){
	if(l > r) return NULL;
	Node* p = new Node(preord[l], NULL, NULL);
	if(r-l == 0) return p;
	int i = l2;
	while(i<=r2 && preord[l] != inord[i]) i++;
	int len = i-l2;
	p->leftch = build(l+1, l+len, l2, i-1);
	p->rightch = build(l+len+1, r, i+1, r2);
	return p;
}
void postord(Node* root){
	if(root == NULL) return;
	postord(root->leftch);
	postord(root->rightch);
	printf("%c", root->ch);
}
int main() {
	while (scanf("%s%s", preord, inord) == 2) {
		Node* root;
		int len = strlen(inord);
		root = build(0, len-1, 0, len-1);
		postord(root);
		printf("\n");
	}
	return 0;
}