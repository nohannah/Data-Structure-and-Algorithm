#include <stdio.h>

// Function to calculate island perimeter
int islandPerimeter(int rows, int cols, int grid[rows][cols]) {
    int perimeter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 1) {
                perimeter += 4;

                // check right neighbor
                if (j + 1 < cols && grid[i][j + 1] == 1)
                    perimeter -= 2;

                // check bottom neighbor
                if (i + 1 < rows && grid[i + 1][j] == 1)
                    perimeter -= 2;
            }
        }
    }

    return perimeter;
}

int main() {
    int grid[4][4] = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1}
    };

    int rows = 4;
    int cols = 4;

    int result = islandPerimeter(rows, cols, grid);

    printf("Perimeter = %d\n", result);

    return 0;
}