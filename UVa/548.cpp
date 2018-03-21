/*
ID: leezhen1
TASK: practice
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <sstream>
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
int inorder[10030], postorder[10030], lch[10030], rch[10030];
int n;
int best, best_sum = (1 << 28);
/* important read data way*/
bool read_list(int* a){
	string line;
	if(!getline(cin, line)) return false;
	stringstream ss(line);
	n = 0;
	int x;
	while(ss >> x) a[n++] = x;
	return n > 0;
}
int build(int l1, int r1, int l2, int r2){
	if(l1 > r1) return 0;
	int root = postorder[r2];
	int p = l1;
	while(inorder[p] != root) p++;
	int cnt = p - l1;
	lch[root] = build(l1, p-1, l2, l2+cnt-1);
	rch[root] = build(p+1, r1, l2+cnt, r2-1);
	return root;
}
void dfs(int u, int sum){
	sum += u;
	if(!rch[u] && !lch[u]){
		if(sum < best_sum || (sum == best_sum && u < best)){
			best = u;
			best_sum = sum;
		}
	}
	if(lch[u]) dfs(lch[u], sum);
	if(rch[u]) dfs(rch[u], sum);
}
int main() {
	while(read_list(inorder)){
		read_list(postorder);
		build(0, n-1, 0, n-1);
		best_sum = (1 << 28);
		dfs(postorder[n-1], 0);
		cout << best << endl;
	}
	return 0;
}