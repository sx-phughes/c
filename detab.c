#include <stdio.h>
#define MAXLINE     1000
#define TABSTOP     4 

int getLine(char s[], int lim);
void copy(char a[], char b[], int start);

int main ()
{
    char line[MAXLINE];
    char allines[MAXLINE];
    int len;
    int totallen = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        copy(allines, line, totallen);
        totallen += len;
    }

    if (totallen > 0) {
        printf("%s", allines);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, tab;
    int spaces = 0;
    int num_tabs, num_spaces;
    
    tab = TABSTOP;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        if (tab <= 0) {
            tab = TABSTOP;
        }

        if (c == '\t') {
            spaces += tab;
            tab = 0;
        } else if (c == ' ') {
            spaces += 1;
        } else if (spaces != 0 && c != '\t' && c != ' ') {
            num_tabs = spaces / TABSTOP;        /* int division drops decimal */
            num_spaces = spaces - num_tabs * TABSTOP; 
        } else {
            spaces = 0;
            s[i] = c;
        }

        --tab;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[], int start)
{
    int i;

    i = 0;
    while ((to[start + i] = from[i]) != '\0') {
        ++i;
    }
}
