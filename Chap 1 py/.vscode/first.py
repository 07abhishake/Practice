def solve(T, test_cases):
    results = []
    for N, A in test_cases:
        # Two prefix sums for simulating the game from both sides
        prefix_start = [0] * (N + 1)
        prefix_end = [0] * (N + 1)
        
        # Calculate prefix sums from start and end
        for i in range(N):
            prefix_start[i + 1] = prefix_start[i] + A[i]
            prefix_end[i + 1] = prefix_end[i] + A[N - 1 - i]
        
        # Alex tries both starting from the left and the right
        min_diff = float('inf')
        for i in range(N + 1):
            sum_alex_left = prefix_start[i]
            sum_bob_left = prefix_start[N] - sum_alex_left
            min_diff = min(min_diff, abs(sum_alex_left - sum_bob_left))
            
            sum_alex_right = prefix_end[i]
            sum_bob_right = prefix_end[N] - sum_alex_right
            min_diff = min(min_diff, abs(sum_alex_right - sum_bob_right))
        
        results.append(min_diff)
    
    print('\n'.join(map(str, results)))

# Input Reading
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    T = int(data[0])  # Number of test cases
    test_cases = []
    index = 1
    for _ in range(T):
        N = int(data[index])
        A = list(map(int, data[index + 1].split()))
        test_cases.append((N, A))
        index += 2
    
    solve(T, test_cases)
