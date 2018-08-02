/*
ID: leezhen
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
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
vii command;
bool is_stack() {
	stack<int> stk;
	for(int i=0; i<command.size(); i++) {
		if(command[i].first == 1) {
			stk.push(command[i].second);
		}else {
			if(stk.empty() ||stk.top() != command[i].second) return false;
			stk.pop();
		}
	}
	return true;
}
bool is_queue() {
	queue<int> q;
	for(int i=0; i<command.size(); i++) {
		if(command[i].first == 1) {
			q.push(command[i].second);
		}else {
			if(q.empty() || q.front() != command[i].second) return false;
			q.pop();
		}
	}
	return true;
}
bool is_priority() {
	priority_queue<int> pq;
	for(int i=0; i<command.size(); i++) {
		if(command[i].first == 1) {
			pq.push(command[i].second);
		}else {
			if(pq.empty() || pq.top() != command[i].second) return false;
			pq.pop();
		}
	}
	return true;
}
int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		int a, b;
		command.clear();
		for(int i=0; i<n; i++) {
			scanf("%d %d", &a, &b);
			command.push_back(make_pair(a, b));
		}
		int ans = 0;
		if(is_stack()) ans += 1;
		if(is_queue()) ans += 2;
		if(ans != 3 && is_priority()) ans += 4;
		if(ans == 0) printf("impossible\n");
		else if(ans == 1) printf("stack\n");
		else if(ans == 2) printf("queue\n");
		else if(ans == 3 || ans == 5 || ans == 6) printf("not sure\n");
		else if(ans == 4) printf("priority queue\n");
	}
	return 0;
}