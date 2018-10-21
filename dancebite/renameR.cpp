#include <iostream>
using namespace std;
#include <string>
#include<stack> 
#include <cctype>
#include <algorithm>

class Solution{
	public:
		string getTheRightString(string s){
			int len = s.size();
			string result="";
			result = result + s[0];
			int flag =0;
			for(int i=1;i<len;i++){
				if(s[i-1]>='a'&&s[i-1]<='z'&&s[i]>='A'&&s[i]<='Z'){
					result = result + "_"+tolwr(s[i]);
					continue;
				}
				if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i]>='A'&&s[i]<='Z'&&s[i+1]>='a'&&s[i+1]<='z'){
					result = result + "_"+tolwr(s[i]);
					continue;					
				}
				result = result +tolwr(s[i]);
			}
			return result;
		}

		char tolwr(char s){
			if(s>='A'&&s<='Z'){
				s=s-('A'-'a');
			}
			return s;
		}
};
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		Solution solu;
		cout<<solu.getTheRightString(s)<<endl;
	}	
}
