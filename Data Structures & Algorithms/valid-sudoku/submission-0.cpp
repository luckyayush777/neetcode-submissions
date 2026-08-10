#include<bits/stdc++.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        vector<unordered_set<int>> box(9);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.')
                {
                    int number = board[i][j] - '0';
                    int row_index = i;
                    int column_index = j;
                    int row_number = i / 3;
                    int column_number = j / 3;
                    int box_number = row_number * 3 + column_number;
                    auto box_result = box[box_number].insert(number);
                    if(!box_result.second)
                        return false;
                    auto row_result = row[row_index].insert(number);
                    if(!row_result.second)
                        return false;
                    auto column_result = col[column_index].insert(number);
                    if(!column_result.second)
                        return false;
                }
                else {
                    continue;
                }
                
                

            }

        }
        return true;
    }
};
