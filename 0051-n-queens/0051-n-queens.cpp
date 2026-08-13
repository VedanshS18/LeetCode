class Solution {
public:
    bool issafe(vector<string> board, int row, int n, int col){
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i = row, j = col; i >= 0 && j < n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;

    }

    void arrange(vector<string> board, vector<vector<string>> &ans, int row, int n){
        if(row == n){
            ans.push_back({board});
            return;
        }
        for(int j = 0; j < n; j++){
            if(issafe(board, row, n, j)){
                board[row][j] = 'Q';
                arrange(board, ans, row+1, n);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n , string(n,'.'));
        vector<vector<string>> ans;

        arrange(board, ans, 0, n);
        return ans;


    }
};