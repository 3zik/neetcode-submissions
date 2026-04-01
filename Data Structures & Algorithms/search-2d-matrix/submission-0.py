class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # plan: BS maximum of each row
        # return the row # that is between l and r
        # then BS the row
        # consider edge cases where m or n = 1
        l = 0
        r = len(matrix) - 1
        while l <= r:
            mid = l + (r-l) // 2
            if matrix[mid][-1] > target:
                r = mid - 1
            elif matrix[mid][-1] < target:
                l = mid + 1
            else:
                return True

        if l >= len(matrix):
            return False

        low = 0
        high = len(matrix[l]) -1
        while low <= high:
            middle = low + (high-low) // 2
            if matrix[l][middle] > target:
                high = middle -1
            elif matrix[l][middle] < target:
                low = middle + 1
            else:
                return True
        return False