/*
** EPITECH PROJECT, 2023
** corners.c
** File description:
** checks if a X is on a corner
*/

#include "my.h"

void display_arr(data_t *data)
{
    for (int i = 0; i != data->nblin; i ++) {
        for (int j = 0; data->arr[i][j] != '\n'; j ++) {
            my_putchar(data->arr[i][j]);
        }
        if (i + 1 != data->nblin) {
            my_putchar('\n');
        }
    }
    my_putchar('\n');
}

static int downrightcorner(data_t *data, int i, int j)
{
    if ((data->arr[i][j + 1] == '#'
        && data->arr[i - 1][j] == '#')
        || (data->arr[i][j + 1] == 'X'
        && data->arr[i - 1][j] == 'X')
        || (data->arr[i][j + 1] == 'X'
        && data->arr[i - 1][j] == '#')
        || (data->arr[i][j + 1] == '#'
        && data->arr[i - 1][j] == 'X')){
        return 1;
    }
    return 0;
}

static int downleftcorner(data_t *data, int i, int j)
{
    if ((data->arr[i][j - 1] == '#'
            && data->arr[i + 1][j] == '#')
            || (data->arr[i][j - 1] == 'X'
            && data->arr[i + 1][j] == 'X')
            || (data->arr[i][j - 1] == 'X'
            && data->arr[i + 1][j] == '#')
            || (data->arr[i][j - 1] == '#'
            && data->arr[i + 1][j] == 'X')){
            return 1;
    }
    return 0;
}

static int upleftcorner(data_t *data, int i, int j)
{
    if ((data->arr[i][j - 1] == '#'
            && data->arr[i - 1][j] == '#')
            || (data->arr[i][j - 1] == 'X'
            && data->arr[i - 1][j] == 'X')
            || (data->arr[i][j - 1] == 'X'
            && data->arr[i - 1][j] == '#')
            || (data->arr[i][j - 1] == '#'
            && data->arr[i - 1][j] == 'X')){
            return 1;
    }
    return 0;
}

static int uprightcorner(data_t *data, int i, int j)
{
    if ((data->arr[i][j + 1] == '#'
            && data->arr[i + 1][j] == '#')
            || (data->arr[i][j + 1] == 'X'
            && data->arr[i + 1][j] == 'X')
            || (data->arr[i][j + 1] == 'X'
            && data->arr[i + 1][j] == '#')
            || (data->arr[i][j + 1] == '#'
            && data->arr[i + 1][j] == 'X')){
            return 1;
    }
    return 0;
}

int isincorner(data_t *data, int i, int j)
{
    if (data->arr[i][j] == 'X') {
        if (downrightcorner(data, i, j) == 1) {
            return 1;
        }
        if (downleftcorner(data, i, j) == 1) {
            return 1;
        }
        if (upleftcorner(data, i, j) == 1) {
            return 1;
        }
        if (uprightcorner(data, i, j) == 1) {
            return 1;
        }
    }
    return 0;
}

void is_blocked(data_t *data)
{
    int cptblocked = 0;

    for (int i = 0; i != data->nblin; i ++) {
        for (int j = 0; data->arr[i][j] != '\n'; j ++) {
            cptblocked += isincorner(data, i, j);
        }
    }
    if (cptblocked >= data->nbO) {
        endwin();
        display_arr(data);
        exit(1);
    }
}
