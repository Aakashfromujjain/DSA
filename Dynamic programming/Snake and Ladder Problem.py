class Solution:
    def minThrows(self, n, lad, sn):
        adj={}
        for ix in range(0,len(lad),2):
            adj[lad[ix]]=lad[ix+1]
        for ix in range(0,len(sn),2):
            adj[sn[ix]]=sn[ix+1]
        seen=set()
        cnt=0
        q=[1]
        while q:
            nq=[]
            cnt+=1
            for cur in q:
                if cur in seen:
                    continue
                seen.add(cur)
                for nxt in range(cur+1,cur+7):
                    if nxt in adj:
                        nxt=adj[nxt]
                    if nxt>=n*n:
                        return cnt
                    nq.append(nxt)
            q=nq
        return -1
