import sys

# Increase recursion depth for deep DFS in large components
sys.setrecursionlimit(200000)

def solve():
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    m = int(input_data[1])
    
    codes = list(map(int, input_data[2:2+n]))
    
    adj = [[] for _ in range(n)]
    idx = 2 + n
    for _ in range(m):
        u = int(input_data[idx]) - 1
        v = int(input_data[idx+1]) - 1
        adj[u].append(v)
        adj[v].append(u)
        idx += 2
        
    visited = [False] * n
    total_distinct_sum = 0
    
    for i in range(n):
        if not visited[i]:
            # New council found: Start DFS to gather all members' codes
            component_codes = []
            stack = [i]
            visited[i] = True
            
            while stack:
                u = stack.pop()
                component_codes.append(codes[u])
                for v in adj[u]:
                    if not visited[v]:
                        visited[v] = True
                        stack.append(v)
            
            # Calculate Linear Basis for this council
            basis = []
            for x in component_codes:
                for b in basis:
                    x = min(x, x ^ b)
                if x > 0:
                    basis.append(x)
                    basis.sort(reverse=True)
            
            # If basis size is k, distinct XOR values = 2^k
            total_distinct_sum += (1 << len(basis))
            
    print(total_distinct_sum)

if __name__ == "__main__":
    solve()
