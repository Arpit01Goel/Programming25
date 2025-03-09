/**
 * @file Binary_sumarray_with_sum.cpp
 * @author Arpit Goel
 * @date 2025/03/07 16:45:36
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

class Solution1 {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            //given a binary array and we need to find how many subarrays have goal as a sum
            //use prefix sum .
            int n = nums.size();
            vector<int> prefix(n,0);
            prefix[0]=nums[0];
            for (int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
            unordered_map<int,int> mp;
            // mp[0]=1;
            int ans = 0;
            for (int i=0;i<n;i++) {
                if (prefix[i]==goal)ans++;
                ans+= mp[prefix[i]-goal];
                mp[prefix[i]]++;
            }
            return ans;
        }
    };

class Solution2 {
    private:
        int solve(vector<int> & nums,int goal) {
            if (goal<0) return 0;
            int l=0,r=0,sum=0,ans=0;
            while (r<nums.size()) {
                sum+= nums[r];
                while (l<=r && sum>goal) sum-=nums[l++];
                ans+= (++r-l);
                
            }
            return ans;
        }
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            //using sliding window in two pass
            //we need a helper function that calclate no of subarrays having sum less than or equal to goal
            return solve(nums,goal) - solve(nums,goal-1);
        }
    };

d
    
int main() {
    fast_io
    
    return 0;
}

// GitHub: https://github.com/Arpit01Goel