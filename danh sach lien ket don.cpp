#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node *next;
};
void nodedau(Node **head,int data){
	Node *x=new Node;
	x->data=data;
	x->next=*head;
	*head=x;	
}
void duyet(Node *head){
	while(head!=NULL){
		cout<<head->data<<endl;
		head=head->next;
	}
}
int main(){
	Node *head=NULL;
	nodedau(&head,2);
	nodedau(&head,3);
	nodedau(&head,2);
	duyet(head);
	return 0;
	
}
