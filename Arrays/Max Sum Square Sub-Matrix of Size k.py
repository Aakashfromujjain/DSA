class Solution:
    def maximumSum(self, mat, k):
        n=len(mat)
        for y in range(n):
            for x in range(n):
                mat[y][x]+=mat[y][x-1] if x-1>=0 else 0
        for y in range(n):
            for x in range(n):
                mat[y][x]+=mat[y-1][x] if y-1>=0 else 0
        mx=-float('inf')
        for y in range(k-1,n):
            for x in range(k-1,n):
                tmp=mat[y][x]
                tmp-=mat[y-k][x] if y-k>=0 else 0
                tmp-=mat[y][x-k] if x-k>=0 else 0
                tmp+=mat[y-k][x-k] if y-k>=0 and x-k>=0 else 0
                mx=max(mx,tmp)
        return mx

