//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	 int modulo = 1e9 + 7;

    int subsetsum(int arr[], int n, int sum) {
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        // Base case: One way to achieve sum 0 (by selecting no elements)
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1; // One way to achieve sum 0: by not choosing any element
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) { // Loop through all sums up to 'sum'
                if (arr[i - 1] <= j) {
                    // Include arr[i-1] and exclude it
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % modulo; 
                } else {
                    // Exclude arr[i-1]
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }

    int perfectSum(int arr[], int n, int sum) {
        // Handle edge cases: if the sum is negative, there are no valid subsets
        if (sum < 0) return 0;
        return subsetsum(arr, n, sum);
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends