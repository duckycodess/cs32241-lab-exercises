#include <stdio.h>
#include <string.h>
void redrawMaze(int r, int c, char maze[1000][1000]){
    char newer_maze[1000][1000];

    for (int i = 0; i < r; i++) {
        char new_row[1000] = "";
        for (int j = 0; j < c; j++) {
            if (j % 2 && maze[i][j] == '#' && j > 0 && maze[i][j-1]) {
                    strncat(new_row, "___", 4);
                }
                
            else if (j%2){
                strncat(new_row, "   ", 4);
            }
            else if (i > 0 && maze[i][j] == '#' && maze[i-1][j] == '#'){
                    strncat(new_row, "|", 2);
                }
            
            else {
                strncat(new_row, " ", 2);
            }
        }
        strcpy(newer_maze[i], new_row);
            }
    for (int k = 0; k < r; k++){
        printf("%s\n", newer_maze[k]);
    }
}



int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar();
        char maze[1000][1000];
        
        for (int j = 0; j < r; j++) {
            fgets(maze[j], c + 2, stdin);
            maze[j][strcspn(maze[j], "\n")] = 0;
        }


        redrawMaze(r, c, maze);
    }
    
    return 0;
}