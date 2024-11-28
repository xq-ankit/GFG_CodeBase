//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int>st;
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                        st.push(s[i]-'0');
                }
                else{
                    int t1=st.top();
                    st.pop();
                    int t2=st.top();
                    st.pop();
                    st.push(solve(t2,t1,s[i]));
                }
            }
            return st.top();
    }
    
    int solve(int t1,int t2,char c){
        
        switch(c){
            case '^':
                return (t1 ^ t2);
            case '*':
                return (t1 * t2);
            case '/':
                return (t1 / t2);
            case '+':
                return (t1 + t2);
            case '-':
                return (t1 - t2);
            default:
                return 0;
        }
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends