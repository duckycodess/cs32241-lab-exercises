#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROWS 60
#define MAX_COLS 60

char grid[MAX_ROWS][MAX_COLS];
bool visited[MAX_ROWS][MAX_COLS];

void check(int i, int j, int *b, int *p){
    visited[i][j] = true;
    if (grid[i][j+2] == '#' && grid[i+1][j-1] == '#' && grid[i+1][j-1] == '#' && grid[i+1][j+1] == '#' && grid[i+1][j+3] == '#'){
        visited[i][j+2] = true;
        visited[i+1][j-1] = true;
        visited[i+1][j+1] = true;
        visited[i+1][j+3] = true;
        (*b)++;
    }
    //down plane
    else if (grid[i+1][j-2] == '#' && grid[i+1][j+2] == '#'){
        visited[i+1][j-2] = true;
        visited[i+1][j+2] = true;
        visited[i+1][j] = true;
        visited[i+2][j] = true;
        visited[i+3][j] = true;
        visited[i+2][j-1] = true;
        visited[i+2][j+1] = true;
        (*p)++;
    }
    //up plane
    else if (grid[i+1][j+1] == '#' && grid[i+1][j-1] == '#'){
        visited[i+1][j+1] = true;
        visited[i+1][j] = true;
        visited[i+1][j-1] = true;
        visited[i+2][j-2] = true;
        visited[i+2][j] = true;
        visited[i+2][j+2] = true;
        visited[i+3][j] = true;
        (*p)++;
    }
    //right
    else if (grid[i+1][j+1] == '#' && grid[i+2][j+1] == '#'){
        visited[i+1][j+1] = true;
        visited[i+2][j-1] = true;
        visited[i+2][j] = true;
        visited[i+2][j+1] = true;
        visited[i+2][j+2] = true;
        visited[i+3][j+1] = true;
        visited[i+4][j] = true;
        (*p)++;
    }
    //left
    else if (grid[i+1][j-1] == '#' && grid[i+2][j-1] == '#'){
        visited[i+1][j-1] = true;
        visited[i+2][j-2] = true;
        visited[i+2][j-1] = true;
        visited[i+2][j] = true;
        visited[i+2][j+1] = true;
        visited[i+3][j-1] = true;
        visited[i+4][j] = true;
        (*p)++;
        
}
}
void count(int *bird, int *plane, int r, int c){
    int i, j;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            if (grid[i][j] == '#' && !visited[i][j]){
                check(i, j, bird, plane);
            }
        }
    }

}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++) {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar();

        for (int i = 0; i < r; i++) {
            fgets(grid[i], c + 2, stdin);
            grid[i][strcspn(grid[i], "\n")] = 0;
        }
    memset(visited, false, sizeof(visited));
    
    int bird= 0, plane= 0;
    count(&bird, &plane, r, c);
    printf("There are %d bird(s) and %d plane(s).\n", bird, plane);
    
    }

    return 0;
}