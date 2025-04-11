//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int>ans;
        map<int,int>mpp;
        int l=0,r=0;
        while(r<arr.size()){
           mpp[arr[r]]++;
    
            
        if(r-l+1==k){
            ans.push_back(mpp.size());
            mpp[arr[l]]--;
            if(mpp[arr[l]]<1){
                mpp.erase(arr[l]);
            }
            l++;
        }
        r++;
        }
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends