#include <stdio.h>
#include <conio.h>  
#include <windows.h> 

#define WIDTH 10
#define HEIGHT 10


#define COLOR_RESET  "\033[0m"
#define COLOR_WALL   "\033[1;34m"  
#define COLOR_PATH   "\033[0;37m"  
#define COLOR_PLAYER "\033[1;32m"  

char maze[HEIGHT][WIDTH] = {
    "##########",
    "#        #",
    "# ###### #",
    "# #    # #",
    "# # ## # #",
    "# # ## # #",
    "# #    # #",
    "# ###### #",
    "#        #",
    "##########"
};

int playerX = 1, playerY = 1;

void displayMaze() {
    system("cls"); 

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == playerY && j == playerX)
                printf(COLOR_PLAYER "P " COLOR_RESET);  
            else if (maze[i][j] == '#')
                printf(COLOR_WALL "# " COLOR_RESET);  
            else
                printf(COLOR_PATH ". " COLOR_RESET);  
        }
        printf("\n");
    }
}

void moveSmoothly(int newX, int newY) {
    while (playerX != newX || playerY != newY) {
        if (playerX < newX) playerX++;
        if (playerX > newX) playerX--;
        if (playerY < newY) playerY++;
        if (playerY > newY) playerY--;

        displayMaze();
        Sleep(100);  
    }
}

void movePlayer(char direction) {
    int newX = playerX, newY = playerY;

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: return;
    }

    if (maze[newY][newX] == ' ') {
        moveSmoothly(newX, newY);  
    }
}

int main() {
    char input;
    
    while (1) {
        displayMaze();
        input = _getch();

        if (input == 'q') break;  
        movePlayer(input);
    }

    return 0;
}
