class Solution {
public:
    bool ifpalindrome(string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return s == s2;
    }

    void allparts(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0 , i+1);

            if(ifpalindrome(part)){
                partitions.push_back(part);
                allparts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;

        allparts( s, partitions, ans);
        return ans;
    }
};