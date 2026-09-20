class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 1; i <= n; i++){
            char c = s[i-1];

            int value = 'z' - c + 1;
            ans += value*i;
        }
        return ans;
    }
};