#include <iostream>
using namespace std;
#include <vector>
#include<numeric>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
			int res = 0;
			subsetSum(nums,S,0,res);
			return res;
    }
    void subsetSum(vector<int>& nums,int s,int start,int &res){
		if(start>=nums.size()){
			if(s==0)res++;
			return ;
		}
		subsetSum(nums,s-nums[start],start+1,res);
		subsetSum(nums,s+nums[start],start+1,res);
	}
};
int main(){
	int s=3;
	vector<int> nums(5,1);
	Solution solu;
	cout<<solu.findTargetSumWays(nums,s)<<endl; 
}
