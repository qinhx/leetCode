#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max(0),mlen(1);
		for(int i(0),j(n-1);i<j;){
			int max_m = min(height[i],height[j])*(j-i);
			if(max_m>max){
				max=max_m;
			}
			if(height[i]<height[j])
				i++;
			else
				j--;
		}
		return max;
    }
};
int main(){
	
}
 

