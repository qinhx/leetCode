#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
		int sl(s.length()),mlen(1),start(0);
		vector<vector<bool> >dpm(sl,vector<bool>(sl,false));
		for(int i(0);i<sl;i++) dpm[i][i] = true;
		for(int i(0);i<sl-1;i++){
			if(s[i]==s[i+1]){
				dpm[i][i+1] =true;
			if(!start)
				start = i,mlen=2;
			}
		}
		for(int kn(3);kn<=sl;++kn){
			for(int k1(0);k1<=sl-kn;++k1){
				if(dpm[k1+1][k1+kn-2]&&s[k1]==s[k1+kn-1]){ 
					dpm[k1][k1+kn-1]=true;
					start = k1;
					mlen = kn;
				} 
			}
		}
		return s.substr(start,mlen);
    }
};
int main(){
	string s;
	Solution solu;
	while(cin>>s){
		cout<<solu.longestPalindrome(s)<<endl;;
	}
} 
