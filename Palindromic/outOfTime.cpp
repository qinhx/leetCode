#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int c=0, max=0;
        int len=s.size();
        string tmp="";
        int begin,end,a,b;
        for(int i=0;i<len;i++){
        	//ÆæÊýÊ± 
        	string t="";
        	t = s[i];
        	for(int j = 0;(i-j)>=0&&(i+j)<=len;j++){
        		if(s[i-j]!=s[i+j])
					break; 
				c = 2*j+1;
				a = i-j;
				b = i+j;
			}
			if(c>max){
				begin = a;
				end = b;
				max =c;

			}
			for(int j = 0;(i-j)>=0&&(i+j+1)<=len;j++){
				if(s[i-j]!=s[i+j+1])
					break;
				c = 2*j+2; 
				a = i-j;
				b = i+j+1;

			}
			if(c>max){
				begin = a;
				end = b;
				max =c;
			}
		}
		
	return s.substr(begin,end+1)<<endl;
    }
};
int main(){
	string s;
	Solution solu;
	while(cin>>s){
		cout<<solu.longestPalindrome(s);
	}
} 
