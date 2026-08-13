class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, int num){

        char ch = '0' + num;
        for(int i = 0; i < 9; i++){
            if(board[row][i] == ch){
                return false;
            }
            
        }

        for(int i = 0; i < 9; i++){
            if(board[i][col] == ch){
                return false;
            }
        }

        int startrow = (row/3)*3;
        int startcol = (col/3)*3;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[startrow + i][startcol + j] == ch){
                    return false;
                }
            }
        }
        return true;
    }

    bool arrange(vector<vector<char>>& board, int row, int col){

        if(row == 9){
            return true;
        }
        int nextrow = row;
        int nextcol = col+1;

        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }

        if(board[row][col] != '.'){
            return arrange(board, nextrow, nextcol);
        }

        for(int i = 1; i < 10; i++){
            char ch = '0' + i;
            if(issafe(board, row, col , i)){
                board[row][col] = ch;

                if(arrange(board, nextrow, nextcol)){
                    return true;
                }
                board[row][col] = '.';
            }
            
            
            

        }
        return false;


    }

    void solveSudoku(vector<vector<char>>& board) {
        arrange(board, 0, 0);
       
    }
};