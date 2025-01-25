#Your task is to complete this function
 
class Solution:
     def maxLen(self, arr):
        # code here
        maxi = 0
        total = 0
        exist = {total: -1}
        for i in range(len(arr)):
            total += arr[i]
            if total in exist:
                maxi = max(maxi, i - exist[total])
            exist[total] = exist.get(total, i)

        return maxi


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maxLen(arr))
        print("~")

# } Driver Code Ends