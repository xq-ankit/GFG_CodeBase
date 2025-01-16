//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int prefixsum=0;
        mpp[0]=-1;
        int count=0;
        for(int i=0;i<arr.size();i++){
            prefixsum+=arr[i];
            int req=prefixsum-k;
            if(mpp.find(req)!=mpp.end()){
                int idx=mpp[req];
                count=max(count,i-idx);
            }
           if(mpp.find(prefixsum)==mpp.end()) mpp[prefixsum]=i;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends