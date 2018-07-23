class Solution {
public:
    vector<int> vist;
    bool dfs(int v, vector<vector<int> >& graph) {
        vist[v] = -1;
        for(int i=0; i<graph.size(); i++) {
            if(graph[v][i]) {
                if(vist[i] < 0) return false;
                else if(!vist[i] && !dfs(i, graph)) return false;
            }
        }
        vist[v] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 0));
        vist.assign(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++) {
            graph[prerequisites[i].first][prerequisites[i].second] = 1;
        }
        for(int i=0; i<numCourses; i++){
            if(!vist[i]) {
                if(!dfs(i, graph)) return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int visited = 0;
        
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            indegree[a.first]++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);
        
        while (!q.empty()) {
            int c = q.front(); q.pop(); indegree[c]--; visited++;
            for (auto a: graph[c])
                if (--indegree[a] == 0) q.push(a);
        }
        
        return visited == numCourses;
    }
};