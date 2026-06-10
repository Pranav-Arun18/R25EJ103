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
int activeMode = 0; 

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
        if(activeMode != 0 && shapes[i].id != activeMode)
            continue;
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
        printf("\n9.View Single Object");
        printf("\n10.View All Objects");

        printf("\nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,width,height;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&width,&height);

                Shape s;
                s.id = count + 1;
                s.type = 1;
                s.x1 = x;
                s.y1 = y;
                s.width = width;
                s.height = height;
                shapes[count] = s;
                count++;
                clearCanvas();
                drawRectangle(x,y,width,height);
                displayCanvas();
                break;
            }

            case 2:
            {
                int x1,y1,x2,y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                Shape s;
                s.id = count + 1;
                s.type = 2;
                s.x1 = x1;
                s.y1 = y1;
                s.x2 = x2;
                s.y2 = y2;
                shapes[count] = s;
                count++;
                clearCanvas();
                drawLine(x1,y1,x2,y2);
                displayCanvas();
                break;
            }

            case 3:
            {
                int xc,yc,r;
                printf("Enter center_x center_y radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                Shape s;
                s.id = count + 1;
                s.type = 3;
                s.x1 = xc;
                s.y1 = yc;
                s.radius = r;
                shapes[count] = s;
                count++;
                clearCanvas();
                drawCircle(xc,yc,r);
                displayCanvas();
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

                Shape s;
                s.id = count + 1;
                s.type = 4;
                s.x1 = x1;
                s.y1 = y1;
                s.x2 = x2;
                s.y2 = y2;
                s.x3 = x3;
                s.y3 = y3;
                shapes[count] = s;
                count++;
                clearCanvas();
                drawTriangle(x1,y1,x2,y2,x3,y3);
                displayCanvas();
                break;
            }

            case 5:
            {
                int id,i,j;
                printf("Enter object ID to delete: ");
                scanf("%d",&id);

                for(i=0;i<count;i++)
                {
                    if(shapes[i].id==id)
                    {
                        for(j=i;j<count-1;j++)
                        {
                            shapes[j]=shapes[j+1];
                        }
                        count--;
                        redrawCanvas();
                        printf("Object deleted.\n");
                        break;
                    }
                }
                break;
            }

            case 6:
            {
                int id,i;
                printf("Enter object ID to modify: ");
                scanf("%d",&id);
                for(i=0;i<count;i++)
                {
                    if(shapes[i].id==id)
                    {
                        switch(shapes[i].type)
                        {
                            case 1:
                                printf("Enter new x y width height: ");
                                scanf("%d%d%d%d",
                                    &shapes[i].x1,
                                    &shapes[i].y1,
                                    &shapes[i].width,
                                    &shapes[i].height);
                                break;

                            case 2:
                                printf("Enter new x1 y1 x2 y2: ");
                                scanf("%d%d%d%d",
                                    &shapes[i].x1,
                                    &shapes[i].y1,
                                    &shapes[i].x2,
                                    &shapes[i].y2);
                                break;

                            case 3:
                                printf("Enter new center_x center_y radius: ");
                                scanf("%d%d%d",
                                    &shapes[i].x1,
                                    &shapes[i].y1,
                                    &shapes[i].radius);
                                break;

                            case 4:
                                printf("Enter new x1 y1 x2 y2 x3 y3: ");
                                scanf("%d%d%d%d%d%d",
                                    &shapes[i].x1,
                                    &shapes[i].y1,
                                    &shapes[i].x2,
                                    &shapes[i].y2,
                                    &shapes[i].x3,
                                    &shapes[i].y3);
                                break;
                        }

                        redrawCanvas();
                        printf("Object modified.\n");
                        break;
                    }
                }
                break;
            }

            case 7:
            {
                redrawCanvas();
                displayCanvas();
                break;
            }

            case 8:
            {
                printf("Exiting...\n");
                break;
            }

            case 9:
            {
                int id;
                printf("Enter object ID to view: ");
                scanf("%d", &id);

                activeMode = id;   
                redrawCanvas();
                displayCanvas();
                break;
            }

            case 10:
            {
                activeMode = 0;    
                redrawCanvas();
                displayCanvas();
                break;
            }

            default:
            {
                printf("Invalid Choice\n");
                break;
            }
        }
    }
    while(choice != 8);
    return 0;
}