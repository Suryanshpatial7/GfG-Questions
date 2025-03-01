#User function Template for python3

class Solution:
    def evenlyDivides(self, n):
        count =0
        s = []
        for i in str(n):
            s.append(int(i))
            count = 0
           
            for i in s:
                if i!=0 and n%i==0:
                    count +=1
        
        return count


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.evenlyDivides(N))
        print("~")

# } Driver Code Ends