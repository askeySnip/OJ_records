class Solution {
public:
    const int inf = 1e9;
    int dist[103];
    int graph[103][103];
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(int i=0; i<103; i++) for(int j=0; j<103; j++) graph[i][j] = -1;
        for(int i=0; i<times.size(); i++) {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        for(int i=0; i<103; i++) graph[i][i] = 0;
        for(int i=0; i<103; i++) dist[i] = inf;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push(make_pair(0, K));
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if(dist[p.second] < p.first) continue;
            dist[p.second] = p.first;
            for(int i=1; i<=N; i++) {
                if(graph[p.second][i] != -1 && graph[p.second][i] + dist[p.second] < dist[i]) {
                    pq.push(make_pair(graph[p.second][i]+dist[p.second], i));
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=N; i++) {
            if(dist[i] == inf) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};