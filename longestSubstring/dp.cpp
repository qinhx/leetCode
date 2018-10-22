#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength =0;
        int book[256];
        for (int i=0;i<256;i++)
        	book[i]=0;
        int i=0,j=0;
        int len = s.size();
        while(j<s.size()){
        	if(book[(int)s[j]]==1){
        		while(s[i]!=s[j])
        			book[(int)s[i++]]=0;
        		i++;
			}
			book[(int)s[j]]=1;
			j++;
			if(j-i>maxLength)
				maxLength = j-i;	
		}
		maxLength = maxLength>j-i ? maxLength:(j-i); 
		return maxLength;
    }
};
int main(){
	string s;
	cin>>s;
	Solution solu;
	cout<<solu.lengthOfLongestSubstring(s)<<endl;
	
}
