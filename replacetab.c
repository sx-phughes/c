#include <stdio.h>
#define MAXLINE     1000
#define TABSTOP[]   "    "

int getLine(char s[], int lim);
void copy(char a[], char b[]);

int main ()
{
    char line[MAXLINE];
    char allines[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        copy(allines, line);
    }

    if (len > 0) {
        printf("%s", allines);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
