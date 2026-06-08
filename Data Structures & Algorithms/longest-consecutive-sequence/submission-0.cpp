class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> check;
        int max_streak = 0; 

        if(nums.empty()) return 0; 

        for(auto num : nums){
            check[num] = 1; // filling map 
        }

        for(auto num : nums){
           
            if(check.find(num - 1) == check.end()){

                int current_num = num;
                int current_streak = 1;
             
                // FIX 2: The while loop must sit inside this IF block
                while (check.find(current_num + 1) != check.end()) {
                    current_num = current_num + 1;     // Move to next number
                    current_streak = current_streak + 1;  // Grow count
                }

                max_streak = std::max(max_streak, current_streak);
            } // This brace closes the IF statement
        }
        return max_streak; 
    }
};
