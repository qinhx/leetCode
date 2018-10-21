#include <iostream>
using namespace std;
#include <stack>
class Solution{
	public:
		string getResult(string s){
			stack<char> st;
			int len = s.size();
			for(int i=0;i<len;i++){
				st.push(s[i]);
			}
			string result="";
			while(!st.empty()){
				if(st.top()=='o'||st.top()=='i'){
					st.pop();
					if(!st.empty())
						st.pop();
				}else{
					result = st.top()+result;
					st.pop();
				}
			}
			return result;
		}
};
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		Solution solu;
		cout<<solu.getResult(s)<<endl; 
	}
}
