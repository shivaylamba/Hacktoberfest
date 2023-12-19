class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        if not img: return []
        
        rows, cols = len(img), len(img[0])
        smoothed_img = [[0 for _ in range(cols)] for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                total, count = 0, 0

                # Iterating through the neighboring cells including the cell itself
                for x in range(max(0, i-1), min(i+2, rows)):
                    for y in range(max(0, j-1), min(j+2, cols)):
                        total += img[x][y]
                        count += 1

                # Assign the floor value of the average to the smoothed_img
                smoothed_img[i][j] = total // count

        return smoothed_img
