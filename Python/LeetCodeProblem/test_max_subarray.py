import unittest
from max_subarray import maxSubArray

class TestMaxSubArray(unittest.TestCase):
    def test_example(self):
        self.assertEqual(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]), 6)
    def test_all_negative(self):
        self.assertEqual(maxSubArray([-2, -3, -1, -5]), -1)

    def test_all_positive(self):
        self.assertEqual(maxSubArray([1, 2, 3, 4]), 10)

    def test_single_element(self):
        self.assertEqual(maxSubArray([3]), 3)


if __name__ == '__main__':
    unittest.main()
