class Solution {
public:
    void sum(vector<int>& candidates, int target, vector<int> &curr, vector<vector<int>> &ans, int totalsum, int i){

        if(totalsum == target){
            ans.push_back(curr);
            return;
        }
        if(totalsum > target || i == candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        sum(candidates, target, curr, ans, totalsum + candidates[i], i);

        curr.pop_back();
        sum(candidates, target, curr, ans, totalsum, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sum(candidates, target, curr, ans, 0, 0);
        return ans;
    }
};