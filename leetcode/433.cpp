class Solution {
public:
    int INF = 9999999;
    int get(string& s, string& e){
        int c = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] != e[i]) c++;
        }
        return c<2? c:INF;
    }
    int dijstra(vector<vector<int> >& graph, int s, int e) {
        int n = graph.size();
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        dist[s] = 0;
        pq.push(make_pair(0, s));
        while(!pq.empty()){
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if(dist[v] < d) continue;
            for(int i=0; i<n; i++){
                if(i == v) continue;
                if(dist[i] > dist[v] + graph[v][i]){
                    dist[i] = dist[v] + graph[v][i];
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
        return dist[e] == INF? -1: dist[e];
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size() == 0) return -1;
        bank.push_back(start);
        int n = bank.size();
        vector<vector<int> > graph(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                graph[i][j] = get(bank[i], bank[j]);
                graph[j][i] = graph[i][j];
            }
        }
        int id = -1;
        for(int i=0; i<n; i++){
            if(bank[i] == end) {
                id = i;
                break;
            }
        }
        if(id == -1) return -1;
        return dijstra(graph, n-1, id);
    }
};