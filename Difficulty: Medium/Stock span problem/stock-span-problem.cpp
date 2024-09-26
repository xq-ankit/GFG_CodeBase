//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       stack<int>st;
       vector<int>v(n,1);
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]<=arr[i]){
               st.pop();
           }
           if(!st.empty())
            v[i]=i-st.top();
            else{
                v[i]=i+1;
            }
          st.push(i);
       }
       return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends