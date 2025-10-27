class Maximum_water:
    def maxArea(self, height: List[int]) -> int:
        lt, rt = 0, len(height) - 1
        max_water = 0
        while lt < rt:
            if height[lt] < height[rt]:
                max_water = max(max_water, (rt-lt) * height[lt])
                lt += 1
            else:
                max_water = max(max_water, (rt-lt) * height[rt])
                rt -= 1
        return max_water