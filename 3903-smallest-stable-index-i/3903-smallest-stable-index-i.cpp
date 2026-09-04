class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int sub = 0;

        for(int i = 0; i < n; i++){
            int maximum = 0;
            int minimum = nums[i];
            for(int j = 0; j <= i; j++){
                maximum = max(maximum, nums[j]);
            }

            for(int j = i; j < n; j++){
                minimum = min(minimum, nums[j]);
            }

            int curr = maximum - minimum;
            

            if(curr <= k){
                return i;
            }
        }
        return -1;
    }
};