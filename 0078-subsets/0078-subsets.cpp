class Solution {
public:

    void printsubsets(vector<int> &nums, vector<int> &curr,vector<vector<int>> &ans, int i) {

        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        
        curr.push_back(nums[i]);
        printsubsets(nums, curr, ans, i + 1);

    
        curr.pop_back();

  
        printsubsets(nums, curr, ans, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        printsubsets(nums, curr, ans, 0);

        return ans;
    }
};