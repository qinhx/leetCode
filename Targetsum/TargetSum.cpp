#include <iostream>
using namespace std;
#include <vector>
#include<numeric>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
			int sum = accumulate(nums.begin(),nums.end(),0);
			return sum<S||(S+sum)&1?0:subsetSum(nums,(S+sum)>>1);
    }
    int subsetSum(vector<int>& nums,int s){
    	int dp[s+1]={0};
    	dp[0]=1;
    	for(int n:nums){
    		for(int i=s;i>=n;i--){
    			dp[i] += dp[i-n];
			}
		}
		return dp[s];
	}
};
int main(){
	int s;
	cin>>s;
	vector<int> nums;
	int n=5;
	while(n--){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}
	Solution solu;
	cout<<solu.findTargetSumWays(nums,s)<<endl; 
}
