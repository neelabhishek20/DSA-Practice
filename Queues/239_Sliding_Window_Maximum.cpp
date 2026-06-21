class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {

            // Remove indices outside the current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window is complete
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

  RESULT:


Xnums = [1,3,-1,-3,5,3,6,7]
k = 3

  
  Windows:

[1,3,-1]      -> 3
[3,-1,-3]     -> 3
[-1,-3,5]     -> 5
[-3,5,3]      -> 5
[5,3,6]       -> 6
[3,6,7]       -> 7


  OUTPUT:[3,3,5,5,6,7]
