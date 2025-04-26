class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> list;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove indices that are out of window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Remove elements smaller than current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            // Push current index
            dq.push_back(i);
            
            // If window is formed, record the max
            if (i >= k - 1)
                list.push_back(nums[dq.front()]);
        }
        return list;
    }
};
