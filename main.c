/*
** EPITECH PROJECT, 2023
** my_popup
** File description:
** displays a caracter string
*/

#include "my.h"

static void display_map(data_t *data)
{
    for (int i = 0; i != data->nblin; i ++) {
        for (int j = 0; data->arr[i][j] != '\n'; j ++) {
            mvprintw(i, j, "%c", data->arr[i][j]);
        }
    }
}

static void check_o(data_t *data)
{
    for (int i = 0; i != data->nbO; i ++) {
        if (data->arr[data->olist[i]->y][data->olist[i]->x] == ' ') {
            data->arr[data->olist[i]->y][data->olist[i]->x] = 'O';
        }
    }
}

static void boxes_on_o(data_t *data)
{
    int count = 0;

    for (int i = 0; i != data->nbO; i ++) {
        if (data->arr[data->olist[i]->y][data->olist[i]->x] == 'X') {
            count ++;
        }
    }
    if (count == data->nbO) {
        endwin();
        display_arr(data);
        exit(0);
    }
}

void test_screensize(data_t *data)
{
    while (data->nblin > LINES || data->maxcol > COLS) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - (my_strlen("enlarge the terminal") / 2)
        , "enlarge the terminal");
        refresh();
        data->key = getch();
        if (data->key == 113) {
            endwin();
            exit(0);
        }
    }
}

void load_map(data_t *data)
{
    while (data->key != 32) {
        test_screensize(data);
        clear();
        test_input(data);
        if (data->key == 113) {
            endwin();
            exit(0);
        }
        check_o(data);
        display_map(data);
        refresh();
        boxes_on_o(data);
        is_blocked(data);
        data->key = getch();
    }
}

void flag(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, ");
        my_putstr("containing '#' for walls,\n         ");
        my_putstr("'P' for the player, 'X' for boxes and 'O'");
        my_putstr(" for storage locations.\n");
        exit(0);
    }
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));

    if (ac != 2) {
        write(2, "invalid number of argument\n", 27);
        return 84;
    }
    flag(av);
    while (1) {
        fill_data(data, av[1]);
        load_map(data);
    }
    endwin();
    for (int i = data->nblin; i != 0; i --) {
        for (int j = 0; data->arr[i][j] != '\n'; j ++) {
            my_putchar(data->arr[i][j]);
        }
    }
    return 0;
}
