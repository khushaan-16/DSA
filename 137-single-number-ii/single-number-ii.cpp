class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int bI=0; bI<32; bI++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i]&(1<<bI)){
                    cnt++;
                }
            }
            if(cnt % 3 == 1){
                    ans = ans | (1<<bI);
                }
        }
        return ans;
    }
};