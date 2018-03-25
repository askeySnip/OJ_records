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
	int r, c, dist;
	int crossed;
	Node(int a, int b, int d, int c):r(a), c(b), dist(d), crossed(c){}
};
struct Status{
	bool vist;
	int dist, crossed;
};
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int m, n, k;
int mp[30][30];
Status vist[30][30];
int solve(){
	for(int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			vist[i][j].vist = false;
			vist[i][j].dist = (1<<28);
			vist[i][j].crossed = 0;
		}
	}
	Node u = Node(1, 1, 0, 0);
	queue<Node> q;
	q.push(u);
	while(!q.empty()){
		Node u = q.front();
		q.pop();
		Status& st = vist[u.r][u.c];
		st.vist = true;
		st.dist = 0;
		st.crossed = 0;
		for(int i=0; i<4; i++){
			int tr = u.r+dr[i], tc = u.c+dc[i];
			if(tr >0 && tc > 0 && tr <=m && tc<=n){
				if(tr == m && tc == n) return u.dist+1;
				if(mp[tr][tc] == 1 && u.crossed < k){
					if(!vist[tr][tc].vist){
						q.push(Node(tr, tc, u.dist+1, u.crossed+1));
						Status& st = vist[tr][tc];
						st.vist = true;
						st.dist = u.dist+1;
						st.crossed = u.crossed+1;
					}else{
						if(vist[tr][tc].crossed > u.crossed+1){
							q.push(Node(tr, tc, u.dist+1, u.crossed+1));
							Status& st = vist[tr][tc];
							st.vist = true;
							st.dist = u.dist+1;
							st.crossed = u.crossed+1;
						}
					}
				}
				if(mp[tr][tc] == 0){
					if(!vist[tr][tc].vist){
						q.push(Node(tr, tc, u.dist+1, 0));
						Status& st = vist[tr][tc];
						st.vist = true;
						st.dist = u.dist+1;
						st.crossed = 0;
					}else{
						if(vist[tr][tc].crossed > 0){
							q.push(Node(tr, tc, u.dist+1, 0));
							Status& st = vist[tr][tc];
							st.vist = true;
							st.dist = u.dist+1;
							st.crossed = 0;
						}
					}
					
				}
			}
		}
	}
	return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &m, &n, &k);
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				scanf("%d", &mp[i][j]);
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}