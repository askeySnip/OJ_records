/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    map<int, Employee*> mp;
    
    int getImportance(vector<Employee*>& employees, int id) {
        int n = employees.size();
        for(int i=0; i<n; i++){
            mp[employees[i]->id] = employees[i];
        }
        vector<int>& vi = mp[id]->subordinates;
        n = vi.size();
        int ans = mp[id]->importance;
        for(int i=0; i<n; i++){
            ans +=  getImportance(employees, vi[i]);
        }
        return ans;
    }
};