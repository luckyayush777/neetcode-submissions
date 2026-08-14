class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> pairs;
        for(int i = 0; i < speed.size(); i++){
            pair<int, float> new_pair;
            new_pair.first = position[i];
            new_pair.second = speed[i];
            pairs.push_back(new_pair);
        }
        sort(pairs.rbegin(), pairs.rend());
        for(auto& element : pairs){
            element.second = (target - element.first) / element.second;
        }
        stack<float> st;
        for(auto& element : pairs){
            if(st.empty() || element.second > st.top()){
                st.push(element.second);
            }
            
        }
        return st.size();
    }
};
