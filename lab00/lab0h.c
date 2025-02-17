#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void redrawMaze(int r, int c, char maze[800][800]) {
    char new_maze[800][800];

    // Initialize new_maze with spaces
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            new_maze[i][j] = ' ';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == '#') {
                new_maze[i][j] = ' ';
                continue;
            }

            bool up = (i > 0 && maze[i-1][j] == '#');
            bool down = (i < r-1 && maze[i+1][j] == '#');
            bool left = (j > 0 && maze[i][j-1] == '#');
            bool right = (j < c-1 && maze[i][j+1] == '#');

            if ((up || down) && (left || right)){
                new_maze[i][j] = '+';
            }
            else if (up && down) {
                new_maze[i][j] = '-';
            } else if (left && right) {
                new_maze[i][j] = '|';
            } else {
                new_maze[i][j] = '+';
            }
        }
    }

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            printf("%c", new_maze[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar(); // Consume the newline character after the number input
        char maze[800][800];

        for (int j = 0; j < r; j++) {
            fgets(maze[j], c + 2, stdin);
            maze[j][strcspn(maze[j], "\n")] = 0; // Remove newline
        }

        redrawMaze(r, c, maze);
    }

    return 0;
}