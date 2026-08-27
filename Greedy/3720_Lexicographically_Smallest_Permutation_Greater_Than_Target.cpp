class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char ch : s)
            cnt[ch - 'a']++;

        int n = target.size();
        int matched = 0;

        while (matched < n && cnt[target[matched] - 'a'] > 0) {
            cnt[target[matched] - 'a']--;
            matched++;
        }

        for (int pos = min(matched, n - 1); pos >= 0; pos--) {

            if (pos < matched)
                cnt[target[pos] - 'a']++;

            int cur = target[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    cnt[c]--;

                    string ans = target.substr(0, pos);
                    ans.push_back('a' + c);

                    for (int x = 0; x < 26; x++) {
                        ans.append(cnt[x], 'a' + x);
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};
