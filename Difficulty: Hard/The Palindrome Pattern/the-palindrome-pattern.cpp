//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool isPaindrome(string S){
        for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]){
                return false;
            }
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        for(int i=0; i<n; i++){
            string st = "";
            for(int j=0; j<n; j++){
                if(arr[i][j] == 0){
                    st += "0";
                }
                else{
                    st += "1";
                }
            }
            if(isPaindrome(st)){
                st = "";
                st += to_string(i);
                st += " R";
                return st;
            }
        }
        
        for(int i=0; i<n; i++){
            string st = "";
            for(int j=0; j<n; j++){
                if(arr[j][i] == 0){
                    st += "0";
                }
                else{
                    st += "1";
                }
            }
            if(isPaindrome(st)){
                st = "";
                st += to_string(i);
                st += " C";
                return st;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends