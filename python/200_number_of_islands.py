class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        island_count = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.findIsland(i, j, grid)
                    island_count += 1
        
        return island_count

    def findIsland(self, i, j, grid):
        """
        :type i, j: int
        :type grid: List[List[str]]
        :rtype: None
        """
        queue = [(i, j)]
        x_max = len(grid) - 1
        y_max = len(grid[0]) - 1

        while len(queue) != 0:
            grid_square = queue.pop()
            gx = grid_square[0]
            gy = grid_square[1]
            if grid[gx][gy] == '1':
                grid[gx][gy] = '2'
                if gx > 0 and grid[gx - 1][gy] == '1':
                    queue.append((gx - 1, gy))
                if gx < x_max and grid[gx + 1][gy] == '1':
                    queue.append((gx + 1, gy))
                if gy > 0 and grid[gx][gy - 1] == '1':
                    queue.append((gx, gy - 1))
                if gy < y_max and grid[gx][gy + 1] == '1':
                    queue.append((gx, gy + 1))
            

