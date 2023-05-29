//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    //Return the sum as a string.
    string findSum(string str1, string str2)
{
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;

	// Initially take carry zero
	int carry = 0;

	// Traverse from end of both strings
	for (int i=n1-1; i>=0; i--)
	{
		// Do school mathematics, compute sum of
		// current digits and carry
		int sum = ((str1[i]-'0') +
				(str2[i+diff]-'0') +
				carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining digits of str2[]
	for (int i=n2-n1-1; i>=0; i--)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry+'0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

    struct Node* addTwoLists(struct Node* head1, struct Node* head2)
    {
        string str1="";
        Node*curr1=head1;
        while(curr1!=NULL){
            str1+=to_string(curr1->data);
            curr1=curr1->next;
        }
        
        string str2="";
        Node*curr2=head2;
        while(curr2!=NULL){
            str2+=to_string(curr2->data);
            curr2=curr2->next;
        }
        string str3=findSum(str1,str2);
        // cout<<str3<<endl;
        Node *ans=new Node(-1);
        Node *a=ans;
        for(int i=0;i<str3.size();i++){
                Node* curr=new Node(str3[i]-'0');
                ans->next=curr;
                if(i!=str3.size()-1)
                ans=ans->next;
        }
        return a->next;
        // return head1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends