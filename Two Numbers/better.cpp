#include <iostream>
using namespace std;
#include <stack>
#include <vector>
struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	int in =0;
    	ListNode *curr = NULL;
    	ListNode *root;
		int partSum =  getTheNodeSum(l1,l2)+in;
		if(partSum>=10){
			in =1;
			root =new ListNode(partSum%10);

		}else{
			in =0;
			root =new ListNode(partSum);
		}
		curr= root;
		l1 = l1->next;
		l2=l2->next;
		while(l1!=NULL||l2!=NULL){
			int partSum =  getTheNodeSum(l1,l2)+in;
			if(partSum>=10){
				in =1;
				ListNode *tmp =new ListNode(partSum%10);
				curr->next=tmp;
			}else{
				in =0;
				ListNode *tmp =new ListNode(partSum);
				curr->next = tmp;
			}
			curr = curr->next;
			if(l1!=NULL){
				l1=l1->next;
			}
			if(l2!=NULL)
				l2= l2->next;
		}
		if(in == 1){
			ListNode *tmp =new ListNode(1);
			curr->next = tmp;
		}
		return root;
    }
    int getTheNodeSum(ListNode* node1,ListNode* node2){
    	if(node1==NULL)
    		return node2->val;
    	else if(node2==NULL)
    		return node1->val;
    	else{
    		return node1->val+node2->val;
		}
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
