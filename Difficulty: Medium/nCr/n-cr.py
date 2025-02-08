#User function Template for python3
''
class Solution:
    def factorial(self, num):
        res = 1
        for i in range(2, num + 1):
            res *= i
        return res
        
    def nCr(self, n, r):
        
        MOD = 10 ** 9 + 7
        if r > n:
            return 0
        # nCr = n! / r!(n-r)!
        n_fact = self.factorial(n)
        r_fact = self.factorial(r)
        n_r_diff = n - r
        n_r_diff_fact = self.factorial(n_r_diff)
        ans1 = r_fact * n_r_diff_fact
        ncr = n_fact // ans1
        return ncr % MOD


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        r = int(input())
        ob = Solution()
        print(ob.nCr(n, r))
# } Driver Code Ends