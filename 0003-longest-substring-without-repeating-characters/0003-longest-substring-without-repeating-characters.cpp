class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> idxMap;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (idxMap.find(s[right]) != idxMap.end() && idxMap[s[right]] >= left) {
                left = idxMap[s[right]] + 1;
            }
            idxMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
