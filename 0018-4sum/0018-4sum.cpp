class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int first = nums[i];

            for(int j = i + 1; j < n; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int sec = nums[j];

                long long find = (long long)target - (first + sec);

                int start = j+1;
                int end = n-1;

                while(start < end){
                    long long sum = (long long)nums[start] + nums[end];
                    if(sum == find){
                        ans.push_back({first, sec, nums[start], nums[end]});
                        start++;
                        end--;

                        while(start < end && nums[start] == nums[start-1]){
                            start++;
                        }

                        while(start < end && nums[end] == nums[end+1]){
                            end--;
                        }

                        
                    }else if(sum < find){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }

        return ans;
    }
};