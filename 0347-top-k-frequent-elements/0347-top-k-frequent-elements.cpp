class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int, int> freqMap;
        
        // Step 1: Count frequencies
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Create buckets, index = frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1); // freq ranges from 1 to n
        for (auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }
        
        // Step 3: Collect top k frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;   
    }
};