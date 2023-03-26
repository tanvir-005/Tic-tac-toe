/* TIC TAC TOE */
#include<stdio.h>
void main()
{
    game();
}

void game();
void game()
{
    char grid[5][11], p[5][11];
    int m, n, f=0;
    printf("Player 1 will play with: O\n");
    printf("Player 2 will play with: X\n\n");
    structure(grid, p);
    for(m=1; m<10; m++)
    {
        if(grid[0][1]==grid[0][5] && grid[0][1]==grid[0][9] && grid[0][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[0][1]);
            f++;
            break;
        }
        else if(grid[2][1]==grid[2][5] && grid[2][1]==grid[2][9] && grid[2][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[2][1]);
            f++;
            break;
        }
        else if(grid[4][1]==grid[4][5] && grid[4][1]==grid[4][9] && grid[4][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[4][1]);
            f++;
            break;
        }
        else if(grid[0][1]==grid[2][1] && grid[0][1]==grid[4][1] && grid[0][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[0][1]);
            f++;
            break;
        }
        else if(grid[0][5]==grid[2][5] && grid[0][5]==grid[4][5] && grid[0][5]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[0][5]);
            f++;
            break;
        }
        else if(grid[0][9]==grid[2][9] && grid[0][9]==grid[4][9] && grid[0][9]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[0][9]);
            f++;
            break;
        }
        else if(grid[0][1]==grid[2][5] && grid[0][1]==grid[4][9] && grid[0][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[0][1]);
            f++;
            break;
        }
        else if(grid[4][1]==grid[2][5] && grid[4][1]==grid[0][9] && grid[4][1]!=' ')
        {
            Show(grid);
            printf("\n\nGame Over\n%c wins", grid[4][1]);
            f++;
            break;
        }
        if(m%2!=0) in_O(grid, p);
        else in_X(grid, p);
    }
    if(f==0)
    {
        Show(grid);
        printf("\n\nGame Over\nDraw");
    }
    printf("\n\n\n\nAgain?\n1. Yes\n2. No\n");
    scanf("%d", &n);
    if(n==1)
    {
        printf("\n\n\n");
        game();
    }
    else printf("Ok.");
}

void show(char z[5][11], char Z[5][11]);
void show(char z[5][11], char Z[5][11])
{
    int i, j;
    printf("\nPlaying grid:    Position grid:\n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<11; j++)
        {
            printf("%c", z[i][j]);
        }
        printf("      ");
        for(j=0; j<11; j++)
        {
            printf("%c", Z[i][j]);
        }
        printf("\n");
    }
}

void structure(char grid[5][11], char p[5][11]);
void structure(char grid[5][11], char p[5][11])
{
    int i, j;
    for(i=0; i<5; i++) for(j=0; j<11; j++)
        {
            if(i%2!=0) grid[i][j]='-';
            else if(j==3 || j==7) grid[i][j]='|';
            else grid[i][j]=' ';
        }
    for(i=0; i<5; i++) for(j=0; j<11; j++)
        {
            if(i%2!=0) p[i][j]='-';
            else if(j==3 || j==7) p[i][j]='|';
            else if(j==1 || j==5 || j==9) p[i][j]=',';
        }
    p[0][0]='1';
    p[0][2]='1';
    p[0][4]='1';
    p[0][6]='2';
    p[0][8]='1';
    p[0][10]='3';

    p[2][0]='2';
    p[2][2]='1';
    p[2][4]='2';
    p[2][6]='2';
    p[2][8]='2';
    p[2][10]='3';

    p[4][0]='3';
    p[4][2]='1';
    p[4][4]='3';
    p[4][6]='2';
    p[4][8]='3';
    p[4][10]='3';
}

void in_O(char grid[5][11], char p[5][11]);
void in_O(char grid[5][11], char p[5][11])
{
    int x, y, a, b;
    show(grid, p);
    printf("\nPosition (x and y) for : O\n");
    scanf("%d%d", &a, &b);
    x=(a*2)-2;
    y=(b*4)-3;
    if(grid[x][y]!=' ')
    {
        printf("\nWrong input\nEnter again:\n");
        in_O(grid, p);
    }
    else grid[x][y]='O';
}

void in_X(char grid[5][11], char p[5][11]);
void in_X(char grid[5][11], char p[5][11])
{
    int x, y, a, b;
    show(grid, p);
    printf("\nPosition (x and y) for : X\n");
    scanf("%d%d", &a, &b);
    x=(a*2)-2;
    y=(b*4)-3;
    if(grid[x][y]!=' ')
    {
        printf("\nWrong input\nEnter again:\n");
        in_X(grid, p);
    }
    else grid[x][y]='X';
}

void Show(char z[5][11]);
void Show(char z[5][11])
{
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<11; j++)
        {
            printf("%c", z[i][j]);
        }
        printf("\n");
    }
}
