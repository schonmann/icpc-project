class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagramsByHash;

        for (int i = 0; i < strs.size(); i++) {
            string anagramCandidate = strs[i];
            
            map<char,int> charCount;
            for (int j = 0; j < anagramCandidate.size(); j++) {
                charCount[anagramCandidate[j]]++;
            }
            
            int idx = 0;
            string orderedAnagram(anagramCandidate);
            for (map<char,int>::iterator it = charCount.begin(); it != charCount.end(); it++) {
                while(it->second--) orderedAnagram[idx++] = it->first;
            }
            anagramsByHash[orderedAnagram].push_back(anagramCandidate);
        }
        
        vector<vector<string>> ans;
        for (unordered_map<string,vector<string>>::iterator it = anagramsByHash.begin(); it != anagramsByHash.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};