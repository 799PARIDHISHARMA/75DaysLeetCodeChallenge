class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLength = 0;

        for(int right = 0; right < s.length(); right++) {
            
            // agar duplicate mila
            while(st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // add current character
            st.insert(s[right]);

            // update max length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};