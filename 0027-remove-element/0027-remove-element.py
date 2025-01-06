class Solution(object):
    def removeElement(self, arr, val):
        n = len(arr)-1
        k = n
        for i in range(n, -1, -1):
            if val == arr[i]:
                arr[i], arr[k] = arr[k], arr[i]
                k -= 1
        return k+1
        