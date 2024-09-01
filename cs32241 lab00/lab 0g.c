#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void redrawMaze(int r, int c, char maze[800][800]) {
    char new_maze[800][800];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            new_maze[i][j] = ' ';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == ' ') {
                new_maze[i][j] = ' ';
                continue;
            }
            bool up = ((i > 0) && maze[i-1][j] == '#');
            bool down = ((i < r-1) && maze[i+1][j] == '#');
            bool left = ((j > 0) && maze[i][j-1] == '#');
            bool right = ((j < c-1) && maze[i][j+1] == '#');

            if ((up || down) && (left || right)){
                new_maze[i][j] = '+';
            }
            else if (up && down) {
                new_maze[i][j] = '|';
            } else if (left && right) {
                new_maze[i][j] = '-';
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

void scaleMaze(int r, int c, char maze[800][802], int s) {
    char new_maze[800][800];
    int new_r = 0;
    
    for (int i = 0; i < r; i++) {
        char new_row[800] = "";
        for (int j = 0; j < c; j++) {
            if (j % 2) {
                for (int k = 0; k < s; k++) {
                    strncat(new_row, &maze[i][j], 1);
                }
            } else {
                strncat(new_row, &maze[i][j], 1);
            }
        }
        strcpy(new_maze[new_r++], new_row);
            }

    redrawMaze(new_r, strlen(new_maze[0]), new_maze);
}


int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar();
        char maze[800][802];
        
        for (int j = 0; j < r; j++) {
            fgets(maze[j], c + 2, stdin);
            maze[j][strcspn(maze[j], "\n")] = 0;
        }

        scaleMaze(r, c, maze, 2);
    }
    
    return 0;
}