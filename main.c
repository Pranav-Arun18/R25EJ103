#include<stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void clearCanvas()
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void displayCanvas()
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x,int y,int width,int height)
{
    int i,j;

    for(i=x;i<x+height && i<ROWS;i++)
    {
        for(j=y;j<y+width && j<COLS;j++)
        {
            if(i==x || i==x+height-1 ||
               j==y || j==y+width-1)
            {
                canvas[i][j]='*';
            }
        }
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int i;

    if(x1==x2)
    {
        for(i=y1;i<=y2;i++)
            canvas[x1][i]='*';
    }

    else if(y1==y2)
    {
        for(i=x1;i<=x2;i++)
            canvas[i][y1]='*';
    }
}

int main()
{
    int choice;

    clearCanvas();

    do
    {
        printf("\n1.Rectangle");
        printf("\n2.Line");
        printf("\n3.Display");
        printf("\n4.Clear");
        printf("\n5.Exit");

        printf("\nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,w,h;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h);
                break;
            }

            case 2:
            {
                int x1,y1,x2,y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2);
                break;
            }

            case 3:
                displayCanvas();
                break;

            case 4:
                clearCanvas();
                break;
        }

    }while(choice!=5);

    return 0;
}