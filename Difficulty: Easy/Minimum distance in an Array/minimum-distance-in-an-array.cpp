//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
  int minDist(int a[], int n, int x, int y) {
        int x_index = -1, y_index = -1;
        int dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                x_index = i;  
            }
            if (a[i] == y) {
                y_index = i; 
            }
            
          
            if (x_index != -1 && y_index != -1) {
                dist = min(dist, abs(x_index - y_index));
            }
        }
        
        return dist == INT_MAX ? -1 : dist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends