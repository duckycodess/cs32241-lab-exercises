#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void traverse(int r, int c, char maze[800][800]){
    char traversed[800][800];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            traversed[i][j] = ' ';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == '#'){
                traversed[i][j] = '#';
                continue;
            }

            bool up = (i > 0 && maze[i-1][j] == '#');
            bool down = (i < r-1 && maze[i+1][j] == '#');
            bool left = (j > 0 && maze[i][j-1] == '#');
            bool right = (j < c-1 && maze[i][j+1] == '#');

            bool down_right = (i < r-1 && j < c-1 && maze[i+1][j+1] == '#');
            bool down_left = (i < r-1 && j > 0 && maze[i+1][j-1] == '#');
            bool up_right = (i > 0 && j < c-1 && maze[i-1][j+1] == '#');
            bool up_left = (i > 0 && j > 0 && maze[i-1][j-1] == '#');

            if (up && left && !down && !right) {
                traversed[i][j] = 'v';
            } else if (up && right && !down && !left) {
                traversed[i][j] = '<';
            } else if (down && right && !left && !up) {
                traversed[i][j] = '^';
            } else if (down && left && !right && !up) {
                traversed[i][j] = '>';
            } else if (up && !down && !left && !right) {
                traversed[i][j] = '<';
            } else if (down && !left && !right && !up) {
                traversed[i][j] = '>';
            } else if (left && !right && !up && !down) {
                traversed[i][j] = 'v';
            } else if (right && !up && !left && !down) {
                traversed[i][j] = '^';
            } else if (down_right) {
                traversed[i][j] = '>';
            } else if (down_left) {
                traversed[i][j] = 'v';
            } else if (up_left) {
                traversed[i][j] = '<';
            } else if (up_right) {
                traversed[i][j] = '^';
            } else {
                traversed[i][j] = ' ';
            }
        }
    }
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            printf("%c", traversed[row][col]);
        }
        printf("\n");
    }

}


void scaleMaze(int r, int c, char maze[800][800], int s) {
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
        if (i % 2) {
            for (int l = 1; l < s; l++) {
                strcpy(new_maze[new_r++], new_row); 
            }
        }
    }
    
    traverse(new_r, strlen(new_maze[0]), new_maze);
}


int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar();
        char maze[800][800];
        
        for (int j = 0; j < r; j++) {
            fgets(maze[j], c + 2, stdin);
            maze[j][strcspn(maze[j], "\n")] = 0;
        }


        scaleMaze(r, c, maze, 4);
    }
    
    return 0;
}