#include <iostream>
using namespace std;
#include <stack>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int len = nums1.size()+nums2.size();
        int m1 = (len+1)/2,m2 = (len+2)/2;
        int mData1,mData2;
		mData1 = getMedians(nums1,nums2,m1);
		mData2 = getMedians(nums1,nums2,m2);
		cout<<mData1 <<" "<<mData2<<endl;
		return (mData1+mData2)/2;		
    }

};
int main(){
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(6);
	nums1.push_back(7);
	
	nums2.push_back(3);
	nums2.push_back(4);
	nums2.push_back(6);
	nums2.push_back(9);
//	nums2.push_back(10);
//	nums2.push_back(13);
//	nums2.push_back(19);
	Solution solu;
	cout<<solu.findMedianSortedArrays(nums1,nums2);
}
