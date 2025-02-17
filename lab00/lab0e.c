#include <stdio.h>
#include <string.h>

void scaleMaze(int r, int c, char maze[30][32], int s) {
    char new_maze[1000][1000];
    int new_r = 0;
    
    for (int i = 0; i < r; i++) {
        char new_row[1000] = "";
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
    
    for (int i = 0; i < new_r; i++) {
        printf("%s\n", new_maze[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int r, c, s;
        scanf("%d", &s);
        scanf("%d %d", &r, &c);
        getchar();
        char maze[30][32];
        
        for (int j = 0; j < r; j++) {
            fgets(maze[j], c + 2, stdin);
            maze[j][strcspn(maze[j], "\n")] = 0;
        }


        scaleMaze(r, c, maze, s);
    }
    
    return 0;
}