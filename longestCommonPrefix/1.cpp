#include <iostream>
using namespace std;
#include <string>
#include <vector>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //int n =strs[0].size();strs为空的时候就会出现问题 
        int S = strs.size();
        if(S==0)return "";
        int n =strs[0].size();//正确处理这个问题 
        for(int i=1;i<S;i++){
        	int k=0;
        	for(k=0;k<min(n,(int)strs[i].size());k++)
        		if(strs[0][k]!=strs[i][k])
        			break;
        		if(n>k)
        			n=k;
		}
 
		return strs[0].substr(0,n);
    }
};

int main(){
	vector<string> str;
	str.push_back("");
	str.push_back("agc");
	str.push_back("asc");
	str.push_back("abd");
	
	Solution solu;
	cout<<solu.longestCommonPrefix(str)<<endl;
}
