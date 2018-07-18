class Solution {
public:
    void deal_(int rm, int in, vector<long long>& window){
        window.insert(lower_bound(window.begin(), window.end(), in), in);
        window.erase(lower_bound(window.begin(), window.end(), rm));
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        if(nums.size() == 0) return ret;
        vector<long long> window;
        for(int i=0; i<k; i++) window.push_back(nums[i]);
        sort(window.begin(), window.end());
        for(int i=k; i<nums.size(); i++){
            if(k%2 == 1){
                ret.push_back(window[k/2]);
            }else{
                ret.push_back((window[k/2] + window[k/2-1])/2.0);
            }
            deal_(nums[i-k], nums[i], window);
        }
        if(k%2 == 1){
            ret.push_back(window[k/2]);
        }else{
            ret.push_back((window[k/2] + window[k/2-1])/2.0);
        }
        return ret;
    }
};