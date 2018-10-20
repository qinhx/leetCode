#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int  f = getTheNum(l1);
        int s = getTheNum(l2);
        int sum = s+f;
        int x =sum%10;
        ListNode  *root = new ListNode(x);
        ListNode *curr =root;
        sum/=10;
        while(sum){
        	int tm =sum%10;
        	ListNode *tmp =new ListNode(tm);
			curr->next = tmp;
			curr = curr->next;	
			sum/=10;      	
		}
		return root;
    }
    int getTheNum(ListNode* node){
    	int i=0;
    	int num = 0;
    	while(node!=NULL){
    		int temp = node->val;
    		for(int j=0;j<i;j++){
    			temp *=10;
			}
			num +=temp;
			i++;
			node=node->next;
		}
		return num;
	}
};
int main(){
	ListNode *l = new ListNode(9);

	ListNode *r = new ListNode(1);
	ListNode *r1 = new ListNode(9);
	r->next=r1;
		ListNode *r2 = new ListNode(9);
	r1->next=r2;
		ListNode *r3 = new ListNode(9);
	r2->next=r3;
		ListNode *r4 = new ListNode(9);
	r3->next=r4;
		ListNode *r5 = new ListNode(9);
	r4->next=r5;
		ListNode *r6 = new ListNode(9);
	r5->next=r6;
		ListNode *r7 = new ListNode(9);
	r6->next=r7;
		ListNode *r8 = new ListNode(9);
	r7->next=r8;
		ListNode *r9 = new ListNode(9);
	r8->next=r9;
	Solution solu;
	ListNode *get = solu.addTwoNumbers(l,r);
	while(get!=NULL){
		cout<<get->val<<endl;
		get =get->next;
	}
}
