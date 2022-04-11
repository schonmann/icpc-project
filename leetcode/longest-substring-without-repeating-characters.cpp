class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> indexByChar;
        
        int subStringLength = 0;
        int bestSubStringLength = 0;
        int startingSubStringIndex = 0;

        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];

            map<char,int>::iterator duplicateCharIterator = indexByChar.find(currentChar);
            bool substringHasDuplicateChar = duplicateCharIterator != indexByChar.end() &&
                duplicateCharIterator->second >= startingSubStringIndex;

            if (substringHasDuplicateChar) {
                bestSubStringLength = max(bestSubStringLength, subStringLength);
                startingSubStringIndex = duplicateCharIterator->second + 1;
                subStringLength = i - startingSubStringIndex;
                indexByChar.erase(currentChar);
            }
            
            subStringLength++;
            indexByChar[currentChar] = i;
        }

        return max(subStringLength, bestSubStringLength);
    }
};
