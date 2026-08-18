class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int> &curr, vector<vector<int>> &ans, int totalsum, int i){
        if(totalsum == target){
            ans.push_back(curr);
            return;
        }

        if(totalsum > target || i == candidates.size()){
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            if(totalsum + candidates[j] > target){
                break;
            }
            curr.push_back(candidates[j]);

            helper(candidates, target, curr, ans, totalsum + candidates[j], j+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(candidates, target, curr, ans, 0, 0);
        return ans;
    }
};