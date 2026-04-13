class TimeMap {
private: 
    unordered_map<string, vector<pair<string, int>>> mapTime;

public:
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapTime[key].emplace_back(value, timestamp);
        
    }
    
    string get(string key, int timestamp) {

        auto& values = mapTime[key];
        string result = "";

        int left = 0, right = values.size()-1;

        while (left<=right){
            int middle = (left+right)/2;

            if (values[middle].second <= timestamp){
                result =  values[middle].first;
                left = middle + 1;
            }else {
                right = middle - 1;
            }
        }

        return result;
    }
};
