// Last updated: 26/11/2025, 22:34:04
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
       
        for(int i = 0; i<row; i++){
            for(int j = 0; j < col; j++){
                if(dfs(board, word, i,j,0))
                return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index){
        if(index == word.size()) 
        return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        return false;

        if(board[i][j] != word[index])
        return false;

        int temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i+1, j, index+1) ||
                     dfs(board, word, i-1, j, index+1) ||
                     dfs(board, word, i, j+1, index+1) ||
                     dfs(board, word, i, j-1, index+1);

        board[i][j] = temp;   
        return found;
    }
};