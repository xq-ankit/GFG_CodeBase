//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans;
        stack <char>st;
        
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ans+=s[i];
            }
           
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
            
            while(!st.empty() && priority(st.top())>=priority(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            }
            
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    
    int priority(char c){
        
        switch (c){
            case '^':
                return 3;
            case '/':
            case '*':
                return 2;
            case '+' : 
            case  '-':
                return 1;
            default:
                return -1;
        }
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends