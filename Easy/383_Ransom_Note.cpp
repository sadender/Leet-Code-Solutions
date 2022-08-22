class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            letters[magazine[i] - 'a']++;
        }
        
        for (int i = 0; i < ransomNote.size(); i++)  {
            letters[ransomNote[i] - 'a']--;
            if (letters[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};