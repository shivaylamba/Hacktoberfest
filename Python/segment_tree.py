# segment_tree
# Gourav Saha
# Description: Segment Tree implementation in Python for range sum queries and point updates.

class SegmentTree:
    def __init__(self, arr):
        """
        Initialize the segment tree with the given array.
        """
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)  
        self.build(arr, 0, 0, self.n - 1)

    def build(self, arr, index, low, high):
        """
        Recursively build the segment tree.
        """
        if low == high:
            self.tree[index] = arr[low]
            return
        mid = (low + high) // 2
        self.build(arr, 2 * index + 1, low, mid)
        self.build(arr, 2 * index + 2, mid + 1, high)
        self.tree[index] = self.tree[2 * index + 1] + self.tree[2 * index + 2]

    def query(self, index, low, high, l, r):
        """
        Return the sum of elements in the range [l, r].
        """
        if r < low or l > high:
            return 0
        if l <= low and high <= r:
            return self.tree[index]
        mid = (low + high) // 2
        left = self.query(2 * index + 1, low, mid, l, r)
        right = self.query(2 * index + 2, mid + 1, high, l, r)
        return left + right

    def update(self, index, low, high, i, val):
        """
        Update the element at position i to val.
        """
        if low == high:
            self.tree[index] = val
            return
        mid = (low + high) // 2
        if i <= mid:
            self.update(2 * index + 1, low, mid, i, val)
        else:
            self.update(2 * index + 2, mid + 1, high, i, val)
        self.tree[index] = self.tree[2 * index + 1] + self.tree[2 * index + 2]


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    seg = SegmentTree(arr)

    print("Original array:", arr)
    print("Sum of range [1, 3]:", seg.query(0, 0, seg.n - 1, 1, 3))

    seg.update(0, 0, seg.n - 1, 1, 10)
    print("After updating index 1 to 10:")
    print("Sum of range [1, 3]:", seg.query(0, 0, seg.n - 1, 1, 3))
