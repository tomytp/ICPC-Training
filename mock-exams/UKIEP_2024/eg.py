def min_removal_cost(arr):
    n = len(arr)
    # dp[mask] represents minimum cost to make array sorted using the subset of elements
    # represented by mask (1 means keep element, 0 means remove)
    dp = {}
    
    def is_sorted(mask):
        # Get array corresponding to current mask
        nums = [arr[i] for i in range(n) if (mask >> i) & 1]
        return all(nums[i] <= nums[i+1] for i in range(len(nums)-1))
    
    def get_intervals_cost(mask):
        # Calculate cost of removal intervals
        interval_len = 0
        cost = 0
        # Count consecutive zeros to get interval lengths
        for i in range(n):
            if not ((mask >> i) & 1):
                interval_len += 1
            else:
                if interval_len > 0:
                    cost += interval_len * interval_len
                interval_len = 0
        if interval_len > 0:
            cost += interval_len * interval_len
        return cost
    
    def solve(mask):
        if mask in dp:
            return dp[mask]
        
        # If current selection is sorted, return cost of removals
        if is_sorted(mask):
            return get_intervals_cost(mask)
            
        min_cost = float('inf')
        # Try removing each element
        for i in range(n):
            if (mask >> i) & 1:  # if element is currently kept
                # Try removing it
                new_mask = mask ^ (1 << i)
                min_cost = min(min_cost, solve(new_mask))
        
        dp[mask] = min_cost
        return min_cost
    
    # Start with all elements kept (mask of all 1s)
    initial_mask = (1 << n) - 1
    return solve(initial_mask)

# Test case
n = input()
a = [int(x) for x in input().split()]
result = min_removal_cost(a)
print(result)  # Should print 6