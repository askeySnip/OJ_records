class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if(nums.size() == 0 || k == 0) return ret;
        
        deque<int> dq;
        for(int i=0; i<k; i++){
            if(dq.empty()) dq.push_back(nums[i]);
            else{
                if(dq.back() <= nums[i]){
                    while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        ret.push_back(dq.front());
        for(int i=k; i<nums.size(); i++){
            if(dq.front() == nums[i-k]) dq.pop_front();
            if(dq.empty()) dq.push_back(nums[i]);
            else{
                if(dq.back() < nums[i]){
                    while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            ret.push_back(dq.front());
        }
        return ret;
    }
};