def is_palindrome(base, n):
    digits = []
    while n > 0:
        digits.append(n % base)
        n //= base
    return digits == digits[::-1]

def find_palindrome_bases(n):
    if n == 2:
        return ["*"]
    
    sqrt_n = int(n**0.5) + 1
    results = set()
    results.add(n - 1)  # n-1 is always a solution for n > 2
    
    for i in range(2, sqrt_n):
        if is_palindrome(i, n):
            results.add(i)
        if n % i == 0:
            quotient = n // i
            if quotient > 3 and quotient <= n:
                results.add(quotient - 1)
    
    return sorted(results)

# Main execution
n = int(input())
bases = find_palindrome_bases(n)

if bases:
    print(" ".join(map(str, bases)))
else:
    print("-1")  # No bases found