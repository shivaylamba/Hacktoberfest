import math

def catalan_number(n: int) -> int:
    """Return the nth Catalan number."""
    return math.comb(2*n, n) // (n+1)

# Example usage:
for i in range(10):
    print(f"C({i}) = {catalan_number(i)}")
