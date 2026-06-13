class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int coverage = 0;
        int lastJumpIdx = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            coverage = max(coverage, i + nums[i]);

            if(i == lastJumpIdx) {
                jumps++;
                lastJumpIdx = coverage;
            }
        }

        return jumps;
    }
};