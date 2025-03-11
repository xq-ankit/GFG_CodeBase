//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution {
    Node* Reverse(Node* head){
        Node* curr=head;
        Node* prev=nullptr;
        while(curr){
            Node* upcoming=curr->next;
            curr->next=prev;
            prev=curr;
            curr=upcoming;
        }
        return prev;
    }
    Node* AddOne(Node* head) {
    int carry = 1; 
    Node* temp = head;

    while (temp) {
        int sum = temp->data + carry;
        temp->data = sum % 10;  // Update the digit
        carry = sum / 10;       // Compute the new carry
        if (!temp->next && carry) { 
            // If last node and there's still a carry, add a new node
            temp->next = new Node(carry);
            carry = 0; // Reset carry
        }
        temp = temp->next;
    }

    return Reverse(head);
}

    
  public:
    Node* addOne(Node* head) {
        head=Reverse(head);
        return AddOne(head);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends