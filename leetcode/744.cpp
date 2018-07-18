class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> count(52, 0);
        for(int i=0; i<letters.size(); i++){
            count[letters[i]-'a']++;
            count[letters[i]-'a'+26]++;
        }
        for(int i=target-'a'+1; i<52; i++){
            if(count[i]) return (char)(i%26+'a');
        }
    }
};