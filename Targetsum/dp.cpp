#include <iostream>
using namespace std;
#include <vector>
#include<numeric>
#include <map>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<map<int, int> > dp(n + 1);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto &a : dp[i]) {
                int sum = a.first, cnt = a.second;
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        return dp[n][S];
    }
};
int main(){
	int s=3;
	vector<int> nums(5,1);
	Solution solu;
	cout<<solu.findTargetSumWays(nums,s)<<endl; 
}
