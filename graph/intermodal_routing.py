import heapq
import sys

def solve():
    # Read n (number of hubs)
    try:
        line = sys.stdin.readline()
        if not line: return
        n = int(line.strip())
    except EOFError:
        return

    adj = [[] for _ in range(2 * n)]

    # Read Road Routes
    r = int(sys.stdin.readline().strip())
    for _ in range(r):
        u, v, t = map(int, sys.stdin.readline().split())
        adj[u].append((v, t))
        adj[v].append((u, t))

    # Read Rail Routes
    s = int(sys.stdin.readline().strip())
    for _ in range(s):
        u, v, t = map(int, sys.stdin.readline().split())
        # Offset rail nodes by n
        adj[u + n].append((v + n, t))
        adj[v + n].append((u + n, t))

    # Read Intermodal Hubs
    m = int(sys.stdin.readline().strip())
    if m > 0:
        intermodal_hubs = list(map(int, sys.stdin.readline().split()))
    else:
        sys.stdin.readline() # consume empty line if present
        intermodal_hubs = []

    # Read Transfer info, Src, Dst
    transfer_time, src, dst = map(int, sys.stdin.readline().split())

    # Add transfer edges between Road and Rail layers
    for hub in intermodal_hubs:
        adj[hub].append((hub + n, transfer_time))
        adj[hub + n].append((hub, transfer_time))

    # Dijkstra's Algorithm
    # dist[i] stores min time to reach hub i (0 to n-1 road, n to 2n-1 rail)
    distances = [float('inf')] * (2 * n)
    
    # Shipment can start on either Road or Rail at the source hub
    distances[src] = 0
    distances[src + n] = 0
    
    pq = [(0, src), (0, src + n)]

    while pq:
        curr_d, curr_u = heapq.heappop(pq)

        if curr_d > distances[curr_u]:
            continue
        
        # Optimization: if we reached the destination hub in either layer
        # we don't return immediately because a shorter path might exist 
        # to the other layer of the same destination.

        for neighbor, weight in adj[curr_u]:
            if distances[curr_u] + weight < distances[neighbor]:
                distances[neighbor] = distances[curr_u] + weight
                heapq.heappush(pq, (distances[neighbor], neighbor))

    # The answer is the minimum of reaching dst via Road or Rail
    ans = min(distances[dst], distances[dst + n])
    
    print(ans if ans != float('inf') else -1)

if __name__ == "__main__":
    solve()
