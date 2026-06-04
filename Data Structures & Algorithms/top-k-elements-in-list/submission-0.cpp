class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

         vector<int> res;
        map<int, int> seen;
        
        // Step 1: Count frequencies
        for (auto& num : nums) {
            seen[num]++;
        }
        
        // Step 2: Push into max-heap sorted by frequency
        // We use {count, element} so the queue sorts by count automatically
        priority_queue<pair<int, int>> pq;
        for (auto const& [element, count] : seen) {
            pq.push({count, element});
        }
        
        // Step 3: Extract the top k elements
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};