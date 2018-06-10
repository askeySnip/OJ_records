class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        unordered_map<int, int> mp;
        int n = heights.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int& t = heights[i];
            if(mp.find(t) != mp.end()){
                if(mp[t]>= i) continue;
            }
            int f=i, tail = i;
            while(f>=0 && heights[f]>=t) f--;
            while(tail<n && heights[tail]>=t) tail++;
            mp[t] = tail-1;
            ans = max(ans, t*(tail-f-1));
        }
        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> index;
        for (int i = 0; i <= heights.size(); i++) {
            while (!index.empty() && (heights[index.top()] > heights[i] || i == heights.size())) {
                int h = heights[index.top()];
                index.pop();
                if (index.empty()) {
                    ans = max(ans, h * i);
                } else {
                    ans = max(ans, h * (i - index.top() - 1));
                }
            }
            index.push(i);
        }
        return ans;
    }
};