class Solution(object):
    def searchMatrix(self, matrix, target):
        n = len(matrix)
        m = len(matrix[0])
        i, j = n - 1, 0
        
        while i >= 0 and j < m:
            if matrix[i][j] == target:
                return True
            elif target > matrix[i][j]:
                j += 1
            else:
                i -= 1
        
        return False