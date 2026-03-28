class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // current character ka count badhao
            freq[s[right] - 'A']++;

            // max frequency update karo
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // agar window invalid ho jaye
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // max length update karo
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};