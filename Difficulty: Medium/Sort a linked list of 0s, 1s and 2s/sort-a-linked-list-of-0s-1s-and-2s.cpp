//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        Node* dummyzero=new Node(-1);
        Node* dummyone=new Node(-1);
        Node* dummytwo=new Node(-1);
        Node* zero=dummyzero;
        Node* one=dummyone;
        Node* two =dummytwo;
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                zero->next=temp;
                zero=temp;
                
            }
            else if(temp->data==1){
                one->next=temp;
                one=temp;
                
            }
            else {
                two->next=temp;
                two=temp;
                
            }
            temp=temp->next;
        }
        
        zero->next=(dummyone->next)?dummyone->next:dummytwo->next;
        one->next=dummytwo->next;
        two->next = nullptr;
        
        return dummyzero->next;
        
        delete dummyzero;
        delete dummyone;
        delete dummytwo;
        
        
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends