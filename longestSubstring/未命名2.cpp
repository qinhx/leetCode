#include <iostream>
#include <cstring>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int max_lengthp=0;
    int book[256];
    for(int i=0;i<256;i++) book[i]=0;
    int i=0;
    int j=0;
    int length=s.size();
    while(j<length)
    {
        if(book[(int)s[j]]==1)
        {
            while(s[i]!=s[j]) book[(int)s[i++]]=0;
            i++;
        }
        book[(int)s[j]]=1;
        j++;
        if(j-i>max_lengthp) max_lengthp=j-i;
    }
    max_lengthp=max_lengthp>(j-i)?max_lengthp:(j-i);
    return max_lengthp;
}

int main(){
	string s;
	cin>>s;
	cout<<lengthOfLongestSubstring(s)<<endl;
	
}
