class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         map<string, int> mp;
         for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    string row = "row" + to_string(i) + to_string(board[i][j]);
                    string col = "col" + to_string(j) + to_string(board[i][j]);
                    string box = "box" + to_string((i/3)*3 + j/3) + to_string(board[i][j]);
                    if(mp.count(row)){
                        return false;
                    }
                    else{
                        mp[row] = 1;
                    }
                       
                    if(mp.count(col)){
                        return false;
                    }
                    else{
                        mp[col] = 1;
                    }
                       
                    if(mp.count(box)){
                        return false;
                    }
                    else{
                       mp[box] = 1;    
                    }
                }
            }
         }
         return true;
    }
};