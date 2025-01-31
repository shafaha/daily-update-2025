class Solution
{
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool isValid(int &n, int &x, int &y)
    {
        return (x >= 0 and x < n and y >= 0 and y < n);
    }
    int markIsland(vector<vector<int>> &grid, int &island_number, int &n, int x, int y)
    {
        grid[x][y] = island_number;
        int count = 1;
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];
            if (isValid(n, newX, newY) and grid[newX][newY] == 1)
                count += markIsland(grid, island_number, n, newX, newY);
        }
        return count;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        unordered_map<int, int> island_size;
        int island_number = 2;

        // Mark island
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                if (grid[x][y] == 1)
                {
                    int island = markIsland(grid, island_number, n, x, y);
                    island_size[island_number] = island;
                    island_number++;
                }
            }
        }

        // Try to convert each 0 to 1 one by ond
        int max_size = 0;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                if (grid[x][y] == 0)
                {
                    set<int> islands;
                    for (int i = 0; i < 4; ++i)
                    {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];
                        if (isValid(n, newX, newY))
                            islands.insert(grid[newX][newY]);
                    }
                    // Iterate and find total size of current island
                    int curr_island = 1;
                    for (int key : islands)
                        curr_island += island_size[key];

                    max_size = max(max_size, curr_island);
                }
            }
        }
        return max_size == 0 ? n * n : max_size;
    }
};
/*
//JAVA
import java.util.*;

class Solution {
    private int[] dir = {-1, 0, 1, 0, -1};

    private boolean isValid(int n, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    private int markIsland(int[][] grid, int islandNumber, int n, int x, int y) {
        grid[x][y] = islandNumber;
        int count = 1;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];
            if (isValid(n, newX, newY) && grid[newX][newY] == 1) {
                count += markIsland(grid, islandNumber, n, newX, newY);
            }
        }
        return count;
    }

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        Map<Integer, Integer> islandSize = new HashMap<>();
        int islandNumber = 2;

        // Mark islands
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    int island = markIsland(grid, islandNumber, n, x, y);
                    islandSize.put(islandNumber, island);
                    islandNumber++;
                }
            }
        }

        // Try to convert each 0 to 1 one by one
        int maxSize = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 0) {
                    Set<Integer> islands = new HashSet<>();
                    for (int i = 0; i < 4; ++i) {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];
                        if (isValid(n, newX, newY)) {
                            islands.add(grid[newX][newY]);
                        }
                    }
                    // Iterate and find total size of current island
                    int currIsland = 1;
                    for (int key : islands) {
                        currIsland += islandSize.getOrDefault(key, 0);
                    }
                    maxSize = Math.max(maxSize, currIsland);
                }
            }
        }
        return maxSize == 0 ? n * n : maxSize;
    }
}

#Python
from typing import List

class Solution:
    def __init__(self):
        self.dir = [-1, 0, 1, 0, -1]

    def isValid(self, n: int, x: int, y: int) -> bool:
        return 0 <= x < n and 0 <= y < n

    def markIsland(self, grid: List[List[int]], island_number: int, n: int, x: int, y: int) -> int:
        grid[x][y] = island_number
        count = 1
        for i in range(4):
            newX = x + self.dir[i]
            newY = y + self.dir[i + 1]
            if self.isValid(n, newX, newY) and grid[newX][newY] == 1:
                count += self.markIsland(grid, island_number, n, newX, newY)
        return count

    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        island_size = {}
        island_number = 2

        # Mark islands
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 1:
                    island = self.markIsland(grid, island_number, n, x, y)
                    island_size[island_number] = island
                    island_number += 1

        # Try to convert each 0 to 1 one by one
        max_size = 0
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 0:
                    islands = set()
                    for i in range(4):
                        newX = x + self.dir[i]
                        newY = y + self.dir[i + 1]
                        if self.isValid(n, newX, newY):
                            islands.add(grid[newX][newY])
                    # Iterate and find total size of current island
                    curr_island = 1
                    for key in islands:
                        curr_island += island_size.get(key, 0)
                    max_size = max(max_size, curr_island)

        return max_size if max_size != 0 else n * n
*/