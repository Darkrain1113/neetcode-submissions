class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
        vector<int> res(n, 1); 

        // Pass 1: Left to right (Prefixes)
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // Pass 2: Right to left (Suffixes using the single variable)
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * suffix; // Or res[i] *= suffix;
            suffix = suffix * nums[i]; // Or suffix *= nums[i];
        }

        return res;
    }
};
