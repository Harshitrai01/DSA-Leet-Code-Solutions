//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        if (head==NULL or head->next==NULL)
            return head;
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    void rearrange(struct Node *head)
    {
        if(head==NULL or head->next==NULL) return;
        
        Node*last=new Node(-1);
        Node*l=last;
        Node*prev=head;
        Node*curr=head->next;
        while(prev->next!=NULL){
            Node *temp=new Node(curr->data);
            last->next=temp;
            last=temp;
            prev->next=curr->next;
            
            if(curr->next!=NULL){
                prev=curr->next;
                curr=prev->next;                
            }

        }
        Node*ans=reverse(l->next);
        prev->next=ans;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends