#include <stdio.h>
#include <string.h>

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);
    int c[1+m][1+n]; /* Possible to reduce space to O(m+n) but didn't bother */
    int i,j;
    for(i=0;i<=m;i++)
        c[i][0] = i;
    for(j=1;j<=n;j++)
        c[0][j] = j;
#define min(a,b,c) ((a<b)?((a<c)?a:c):((b<c)?b:c))
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            if(word1[i-1] == word2[j-1])
                c[i][j] = c[i-1][j-1];
            else
                c[i][j] = 1+min(c[i-1][j-1],c[i][j-1],c[i-1][j]);
        }
    }
#undef min
    return c[m][n];
}

int main() {
    char word1[] = "horse";
    char word2[] = "ros";
    printf("Input: word1 = \"%s\", word2 = \"%s\"\n", word1, word2);
    printf("Output: %d\n", minDistance(word1, word2));

    char word3[] = "intention";
    char word4[] = "execution";
    printf("Input: word1 = \"%s\", word2 = \"%s\"\n", word3, word4);
    printf("Output: %d\n", minDistance(word3, word4));

    return 0;
}
