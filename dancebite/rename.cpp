#include <iostream>
using namespace std;
#include <string>
#include<stack> 
#include <cctype>
#include <algorithm>
class Solution{
	public:
		string changeTheName(string s){
			stack<string> st;
			stack<int> intSt;
			string tmp="";
			intSt.push(0);
			for(int i=0;i<s.size();i++){
				if(judge(s[i]) != judge(s[i+1]))
					intSt.push(i+1);
			}
			int stS = intSt.size();
			int a[stS];
			int i=0;
			while(!intSt.empty()){
				a[i]=intSt.top();
				cout<<a[i]<<endl;
				intSt.pop();
				i++;
			}
			tmp = s.substr(a[stS-1],a[stS-2]+1);
			for(int j=stS-2;j>0;j--){
				string t =s.substr(a[j],a[j-1]-a[j]) ;
				t = tolwr(t);
				tmp = tmp+"_"+t;
			}
			return tmp;
		}
		bool judge(char ch){
			if(ch>='a'&&ch<='z')
				return true;
			else
				return false;
		}
		string tolwr(string s){
			for(int i=0;i<s.size();i++){
				if(s[i]>='A'&&s[i]<='Z'){
					s[i]=s[i]-('A'-'a');
				}
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
		cout<<solu.changeTheName(s)<<endl;
	}
}
