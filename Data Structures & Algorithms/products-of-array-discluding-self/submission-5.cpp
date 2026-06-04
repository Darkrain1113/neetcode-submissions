class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1;
        // Left to right (Prefixes)
        for (int i = 0; i < n; i++) {
           // res[i] = res[i - 1] * nums[i - 1];
           res[i] = res[i] * prefix; 
            // Or res[i] *= suffix;
           prefix = prefix * nums[i];
        }

        // Right to left (Suffixes using the single variable)
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * suffix; 
            // Or res[i] *= suffix;
            suffix = suffix * nums[i]; 
            // Or suffix *= nums[i];
        }

        return res;
    }
};
