#include <stdio.h>
#include <string.h>

int palindrome(char word[400001]) {
    int i, j, ans = 0;
    i = 0;
    j = strlen(word) - 2;

    while (i <= j) {
        if (word[i] == ' ') {
            i++;
        }
        else if (word[j] == ' ') {
            j--;
        }
        else if (tolower(word[i]) == tolower(word[j])) {
            i++;
            j--;
        }
        else {
            ans++;
            i++;
            j--;
        }
    }
    return ans;
}

int main() {
    int n, ans;
    char word[400001];
    char line[1000];
    
    fgets(line, sizeof(line), stdin);
    n = atoi(line);

    for (int i = 0; i < n; i++) {
        fgets(word, sizeof(word), stdin);

        ans = palindrome(word);
        printf("%d\n", ans);
    }
    return 0;
}