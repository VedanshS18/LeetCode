class Solution {
public:
    bool checkValidString(string s) {
        int MinOpen = 0;
        int MaxOpen = 0;
        int n = s.size();

        for(char c : s){
            if(c == '('){
                MinOpen++;
                MaxOpen++;
            }else if(c == ')'){
                MaxOpen--;
                MinOpen--;
            }else{
                MinOpen--;
                MaxOpen++;
            }
            MinOpen = max(0, MinOpen);

            if(MaxOpen < 0){
            return false;
        }
        }
        
        return MinOpen == 0;
    }
};