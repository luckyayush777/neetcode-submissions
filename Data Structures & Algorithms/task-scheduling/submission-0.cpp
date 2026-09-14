#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<random>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char task : tasks){
            
            count[task - 'A']++;
        }
        priority_queue<int> mh;
        for(int frequency : count){
            if(frequency > 0){
                mh.push(frequency);
            }
        }
        queue<pair<int, int>> q;
        
        int t = 0;
        
        while(!q.empty() || !mh.empty()){
            t++;
            int remaining = 0;
            if(!mh.empty()){
                remaining = mh.top();
                mh.pop();
                remaining--;
                if(remaining > 0){
                    q.push({remaining, t + n});
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
