#include<stdio.h>
#include<stdlib.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];
#define MAX_OBJECTS 100

typedef struct
{
    int id;
    int type;      //1 Rectangle
                   //2 Line
                   //3 Circle
                   //4 Triangle

    int x1,y1;
    int x2,y2;
    int x3,y3;

    int width,height;

    int radius;

} Shape;

Shape shapes[MAX_OBJECTS];

int count=0;

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
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);

    int steps=(dx>dy)?dx:dy;

    float xInc=(float)(x2-x1)/steps;
    float yInc=(float)(y2-y1)/steps;

    float x=x1;
    float y=y1;

    int i;

    for(i=0;i<=steps;i++)
    {
        if((int)x>=0 && (int)x<ROWS &&
           (int)y>=0 && (int)y<COLS)
        {
            canvas[(int)x][(int)y]='*';
        }

        x+=xInc;
        y+=yInc;
    }
}

void drawTriangle(int x1,int y1,
                  int x2,int y2,
                  int x3,int y3)
{
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}

void drawCircle(int xc,int yc,int r)
{
    int x,y;

    for(x=0;x<ROWS;x++)
    {
        for(y=0;y<COLS;y++)
        {
            int dx=x-xc;
            int dy=y-yc;

            if(dx*dx + dy*dy <= r*r)
                canvas[x][y]='*';
        }
    }
}

void redrawCanvas()
{
    int i;

    clearCanvas();

    for(i=0;i<count;i++)
    {
        switch(shapes[i].type)
        {
            case 1:
                drawRectangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].width,
                    shapes[i].height);
                break;

            case 2:
                drawLine(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2);
                break;

            case 3:
                drawCircle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].radius);
                break;

            case 4:
                drawTriangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2,
                    shapes[i].x3,
                    shapes[i].y3);
                break;
        }
    }
}

int main()
{
    int choice;

    clearCanvas();

    do
    {
        printf("\n1.Add Rectangle");
        printf("\n2.Add Line");
        printf("\n3.Add Circle");
        printf("\n4.Add Triangle");
        printf("\n5.Delete Object");
        printf("\n6.Modify Object");
        printf("\n7.Display");
        printf("\n8.Exit");

        printf("\nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,width,height;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&width,&height);

                drawRectangle(x,y,width,height);

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
            {
                int xc,yc,r;

                printf("Enter center_x center_y radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r);

                break;
            }

            case 4:
            {
                int x1,y1,x2,y2,x3,y3;

                printf("Enter x1 y1 x2 y2 x3 y3: ");

                scanf("%d%d%d%d%d%d",
                      &x1,&y1,
                      &x2,&y2,
                      &x3,&y3);

                drawTriangle(x1,y1,x2,y2,x3,y3);

                break;
            }

            case 5:
            {
                displayCanvas();

                break;
            }

            case 6:
            {
                clearCanvas();

                printf("Canvas Cleared\n");

                break;
            }

            case 7:
            {
                printf("Exiting...\n");

                break;
            }

            default:
            {
                printf("Invalid Choice\n");

                break;
            }
        }

    }while(choice != 7);

    return 0;
}