# 2D Graphics Editor in C

## Problem Statement

Develop a **2D Graphics Editor** using `*` and `_` characters. The program uses a **2D character array** as a canvas and provides functions to create and manipulate graphical objects.

## Features

### Draw Shapes

The editor supports drawing the following objects:

* Rectangle
* Line
* Circle
* Triangle

### Object Operations

Users can:

* Add objects to the picture
* Delete objects from the picture
* Modify existing objects
* Display the current picture

## Data Structure

The canvas is represented using a **2D array of characters**:

```c
#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];
```

* `'*'` represents the pixels occupied by shapes.
* `'_'` represents empty space.

## Supported Shapes

### 1. Rectangle

Defined by:

* x-coordinate
* y-coordinate
* width
* height

### 2. Line

Defined by:

* Starting point `(x1, y1)`
* Ending point `(x2, y2)`

### 3. Circle

Defined by:

* Center coordinates `(x, y)`
* Radius

### 4. Triangle

Defined by three vertices:

* `(x1, y1)`
* `(x2, y2)`
* `(x3, y3)`

## Menu Options

```
1. Add Object
2. Delete Object
3. Modify Object
4. Display Canvas
5. Exit
```

### Add Object

```
1. Rectangle
2. Line
3. Circle
4. Triangle
```

Each object is assigned a unique ID so that it can later be deleted or modified.

## Functions Used

```c
void clearCanvas();
void displayCanvas();

void drawRectangle(int x, int y, int width, int height);
void drawLine(int x1, int y1, int x2, int y2);
void drawCircle(int x, int y, int radius);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

void addObject();
void deleteObject(int id);
void modifyObject(int id);

void redrawCanvas();
```

## Working Principle

1. The canvas is initialized with `_`.
2. Objects are stored in an array of structures.
3. When an object is added, its details are saved and the shape is drawn using `*`.
4. Deleting an object removes it from the object list and redraws the canvas.
5. Modifying an object updates its parameters and redraws the canvas.
6. The current picture can be displayed at any time.

## Sample Output

```
__________________________________________________
__________________________________________________
__________********__________________
__________*______*__________________
__________*______*__________________
__________********__________________
__________________________________________________
__________________________________________________
```

## Concepts Used

* Arrays
* Structures
* Functions
* Loops
* Conditional Statements
* 2D Character Arrays
* Object Management

## Language

* C Programming

## Compilation

Using GCC:

```bash
gcc graphics_editor.c -o graphics_editor
```

Run the program:

```bash
./graphics_editor
```

## Applications

* Basic computer graphics simulation
* Understanding raster graphics
* Learning structures and arrays in C
* Object manipulation and redraw techniques
