#include "snakelogic.c"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void draw(const gamestate* state) {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int is_snake = 0;
            for (int i = 0; i < state->snake.length; i++) {
                if (state->snake.body[i].x == x && state->snake.body[i].y == y) {
                    is_snake = 1;
                    break;
                }
            }
            if (is_snake) {
                printf("O");
            }
            else if (state->food.pos.x == x && state->food.pos.y == y) {
                printf("F");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", state->score);
    if (state->game_over) {
        printf("Game Over! Press 'r' to restart or 'q' to quit\n");
    }
}

int main() {
    gamestate state;
    init_game(&state);

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'w': change_direction(&state, UP); break;
            case 's': change_direction(&state, DOWN); break;
            case 'a': change_direction(&state, LEFT); break;
            case 'd': change_direction(&state, RIGHT); break;
            case 'r': init_game(&state); break;
            case 'q': return 0;
            }
        }

        update_game(&state);
        draw(&state);
        Sleep(300);
    }

    return 0;
}