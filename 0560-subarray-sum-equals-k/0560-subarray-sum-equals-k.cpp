class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector <int> sum(n,0);
        sum[0] = nums[0];

        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        unordered_map<int,int> mp;
        for(int j = 0; j < n; j++){
            if(sum[j] == k){
                count++;
            }

            int val = sum[j] - k;

            if(mp.find(val) != mp.end()){
                count += mp[val];
            }

            if(mp.find(sum[j]) == mp.end()){
                mp[sum[j]] = 0;
            }
            mp[sum[j]]++;
        }

        return count;
    }
};