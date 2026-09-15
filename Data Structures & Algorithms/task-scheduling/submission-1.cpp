#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<random>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char c : tasks){
            count[c - 'A']++;
        }
        priority_queue<int> mh;
        for(auto elem : count){
            if(elem > 0 )
                mh.push(elem);
        }
        queue<pair<int, int>> q;
        int t = 0;
        while(!q.empty() || !mh.empty()){
            t++;
            if(!mh.empty()){
                int remaining = mh.top();
                mh.pop();
                remaining--;
                if(remaining > 0){
                    q.push({remaining, t+n});
                }
            }
            if(!q.empty() && q.front().second == t){
                mh.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};
