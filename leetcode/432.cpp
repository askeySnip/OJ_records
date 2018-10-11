class AllOne {
private:
    struct Bucket{
        int val;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // if key doesn't exsist
        if(!bucketOfKey.count(key)) {
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        auto next = bucketOfKey[key], bucket = next++;
        if(next == buckets.end() || next->val > bucket->val + 1) {
            next = buckets.insert(next, {bucket->val+1, {}});
        }
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        bucket->keys.erase(key);
        if(bucket->keys.empty()) buckets.erase(bucket);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!bucketOfKey.count(key)) return;
        auto pre = bucketOfKey[key], bucket = pre--;
        bucketOfKey.erase(key);
        if(bucket->val > 1) {
            if(bucket == buckets.begin() || pre->val < bucket->val - 1) {
                pre = buckets.insert(bucket, {bucket->val-1, {}});
            }
            pre->keys.insert(key);
            bucketOfKey[key] = pre;
        }
        
        bucket->keys.erase(key);
        if(bucket->keys.empty()) buckets.erase(bucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */