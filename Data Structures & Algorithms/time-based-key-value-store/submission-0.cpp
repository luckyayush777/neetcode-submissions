using namespace std;
class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        
        um[key].push_back({value, timestamp});

    }
    
    string get(string key, int timestamp) {
        if(um.find(key) == um.end()){
            return "";
        }
        vector<pair<string, int>>& a_v = um[key];
        int n = a_v.size();
        int l = 0; 
        int r = n - 1;
        
        if(timestamp > a_v[n-1].second)
            return a_v[n-1].first;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(a_v[mid].second == timestamp){
                return a_v[mid].first;
            }else if(a_v[mid].second > timestamp){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(r < 0)
            return "";
        else   
            return a_v[r].first;
    }
};
