import sys

def solve():
    # Read input
    try:
        line1 = sys.stdin.readline()
        if not line1:
            return
        n = int(line1.strip())
        line2 = sys.stdin.readline()
        if not line2:
            return
        a = list(map(int, line2.split()))
    except ValueError:
        return

    max_len = 0
    unique_elements_total = len(set(a))

    # Iterate over the possible number of unique elements 'k' 
    # that could be in a balanced subarray
    for k in range(1, unique_elements_total + 1):
        counts = {}
        unique_in_window = 0
        left = 0
        
        # We also need to track how many elements in the window 
        # share the same frequency.
        for right in range(n):
            # Add element at 'right'
            val = a[right]
            if val not in counts or counts[val] == 0:
                unique_in_window += 1
                counts[val] = 1
            else:
                counts[val] += 1
            
            # If we have more than k unique elements, shrink from left
            while unique_in_window > k:
                left_val = a[left]
                counts[left_val] -= 1
                if counts[left_val] == 0:
                    unique_in_window -= 1
                left += 1
            
            # Check if balanced: All k elements must have same frequency
            # Length must be divisible by k
            window_size = right - left + 1
            if unique_in_window == k and window_size % k == 0:
                freq = window_size // k
                # Verify if all 'k' elements actually have count == freq
                # Optimization: This check can be slow, but since we 
                # only check when unique_in_window == k, we can optimize 
                # by tracking how many elements have frequency == window_size // k
                is_balanced = True
                for v in counts:
                    if counts[v] > 0 and counts[v] != freq:
                        is_balanced = False
                        break
                
                if is_balanced:
                    max_len = max(max_len, window_size)

    print(max_len)

if __name__ == "__main__":
    solve()
