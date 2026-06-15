// LeetCode 58: Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;

        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        while(i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};
