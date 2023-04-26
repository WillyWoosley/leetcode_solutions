class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> time_map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if (time_map.find(key) == time_map.end()) {
            time_map[key] = { make_pair(timestamp, value) };
        } else {
            time_map[key].push_back(make_pair(timestamp, value));
        }
    }
    
    // Find appropriate key using a binary search
    string get(string key, int timestamp) {
        if (time_map.find(key) == time_map.end() || 
            time_map[key][0].first > timestamp) {
            return "";
        } else {
            int l = 0, r = time_map[key].size();

            // Binary search, but rather than returning any value instead drag
            // r pointer to the first time greater than timestamp
            while (l < r) {
                int mid = (l + r) / 2;
                if (time_map[key][mid].first <= timestamp) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            // If first time greater is the start of the vec, then timestamp is too
            // early, else return key from one before the r pointer
            if (r == 0) {
                return "";
            } else {
                return time_map[key][r-1].second;
            }
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
