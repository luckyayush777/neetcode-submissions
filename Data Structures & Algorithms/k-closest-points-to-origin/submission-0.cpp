#include<vector>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using Entry = pair<int, vector<int>>;
        priority_queue<Entry> heap;
        for(auto& element : points){
            heap.push({element[0] * element[0] + 
            element[1] * element[1], {element[0], element[1]}});
            if(heap.size() > k)
            {
                heap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
