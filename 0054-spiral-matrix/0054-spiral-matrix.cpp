class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int Srow = 0;
        int Erow = m-1;
        int Scol = 0;
        int Ecol = n-1;

        vector <int> ans;

        while(Srow <= Erow && Scol <= Ecol){
            for(int i = Scol; i <= Ecol; i++){
                ans.push_back(matrix[Srow][i]);
            }

            for(int i = Srow + 1; i <= Erow; i++){
                ans.push_back(matrix[i][Ecol]);
            }

            for(int i = Ecol-1; i >= Scol; i--){
                if(Srow == Erow){
                    break;
                }
                ans.push_back(matrix[Erow][i]);
            }

            for(int i = Erow-1; i >= Srow+1; i--){
                if(Scol == Ecol){
                    break;
                }
                ans.push_back(matrix[i][Scol]);
            }

            Srow++;
            Scol++;
            Erow--;
            Ecol--;
        }
        return ans;
    }
};