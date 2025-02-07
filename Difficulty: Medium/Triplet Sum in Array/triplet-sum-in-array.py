#User function Template for python3
class Solution:
    # Function to find if there exists a triplet in the array arr[] which sums up to target.
    def hasTripletSum(self, arr, target):
        arr.sort()
        n = len(arr)
        
        
        for i in range(n-2):
            left, right = i+1, n-1
            
            while left<right:
                current_sum = arr[i]+arr[left]+arr[right]
                if current_sum == target:
                    return True;
                elif current_sum < target:
                    left +=1
                else:
                    right -= 1
        return False

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    tc = int(input().strip())  # Number of test cases
    while tc > 0:
        arr = list(map(int, input().strip().split()))  # Read array
        target = int(input().strip())  # Read the target sum
        ob = Solution()
        print("true"
              if ob.hasTripletSum(arr, target) else "false")  # Output result
        tc -= 1

# } Driver Code Ends