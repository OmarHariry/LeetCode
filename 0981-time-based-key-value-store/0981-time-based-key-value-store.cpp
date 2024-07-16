class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (this->mp.find(key) == this->mp.end())
            return "";
        
        auto& vec = this->mp[key];
        int left = 0, right = vec.size()-1;
        string ans = "";
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(timestamp >= vec[mid].first) {
                ans = vec[mid].second;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */