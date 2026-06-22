// LeetCode 1425: Constrained Subsequence Sum

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> dp(n);

        deque<int> dq;

        dp[0] = nums[0];
        dq.push_back(0);

        int ans = dp[0];

        for(int i = 1; i < n; i++) {

            while(!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            dp[i] = nums[i];

            if(!dq.empty()) {
                dp[i] = max(dp[i], nums[i] + dp[dq.front()]);
            }

            while(!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

INPUT: nums = {10, 2, -10, 5, 20};
k = 2;

DP VALUES:
10
12
2
17
37

OUTPUT: 37
  
