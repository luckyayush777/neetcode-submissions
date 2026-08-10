class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for(auto& element : strs){
            int size = element.size();
            string encodedLength = "[" + to_string(size) + "]";
            string newElement = encodedLength + element;
            ans += newElement;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ansArr;
        for(int i = 0; i < s.size(); i++){
            string currentLength = "";
            if(s[i] == '['){
                i++;
                while(s[i] != ']'){
                    currentLength += s[i];
                    i++;
                }
                int currentLengthNumber = stoi(currentLength);
                string ans = s.substr(i+1 , currentLengthNumber);
                ansArr.push_back(ans);
                i += currentLengthNumber;
            }
        }
        return ansArr;
    }
};
