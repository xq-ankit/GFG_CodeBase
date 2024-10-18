//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int x) {
	 int start=binarySearch(nums,n, x, true);
     int end=binarySearch(nums,n, x, false);
     if (start == -1 || end == -1) {
        return 0; 
    }
    return (end - start) + 1;
    
	}
	
	int binarySearch(int* nums,int n, int target, bool findStart) {
    int start = 0, end = n - 1, ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

       if(nums[mid]==target){
            ans = mid;
            if (findStart) {
                end = mid - 1; 
            } else {
                start = mid + 1; 
            }
        }
        
        else if (nums[mid] > target) {
            end = mid - 1;
        }  
        else{
            start = mid + 1;
        }
    }

    return ans;
}
	
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends