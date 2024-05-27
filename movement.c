/*
** EPITECH PROJECT, 2023
** movement.c
** File description:
** moves the player
*/

#include "my.h"

int movebox_left(data_t *data)
{
    if (data->arr[data->px][data->py - 1] == 'X' &&
    (data->arr[data->px][data->py - 2] == ' ' ||
    data->arr[data->px][data->py - 2] == 'O')) {
        data->arr[data->px][data->py - 2] = 'X';
        return 0;
    }
    if (data->arr[data->px][data->py - 1] != 'X') {
        return 0;
    }
    return 1;
}

int movebox_up(data_t *data)
{
    if (data->arr[data->px - 1][data->py] == 'X' &&
    (data->arr[data->px - 2][data->py] == ' ' ||
    data->arr[data->px - 2][data->py] == 'O')) {
        data->arr[data->px - 2][data->py] = 'X';
        return 0;
    }
    if (data->arr[data->px - 1][data->py] != 'X') {
        return 0;
    }
    return 1;
}

int movebox_right(data_t *data)
{
    if (data->arr[data->px][data->py + 1] == 'X' &&
    (data->arr[data->px][data->py + 2] == ' ' ||
    data->arr[data->px][data->py + 2] == 'O')) {
        data->arr[data->px][data->py + 2] = 'X';
        return 0;
    }
    if (data->arr[data->px][data->py + 1] != 'X') {
        return 0;
    }
    return 1;
}

int movebox_down(data_t *data)
{
    if (data->arr[data->px + 1][data->py] == 'X' &&
    (data->arr[data->px + 2][data->py] == ' ' ||
    data->arr[data->px + 2][data->py] == 'O')) {
        data->arr[data->px + 2][data->py] = 'X';
        return 0;
    }
    if (data->arr[data->px + 1][data->py] != 'X') {
        return 0;
    }
    return 1;
}

static void move_down(data_t *data)
{
    if (data->arr[data->px + 1][data->py] != '#') {
        if (movebox_down(data) == 0) {
            data->arr[data->px][data->py] = ' ';
            data->arr[data->px + 1][data->py] = 'P';
            data->px ++;
        }
    }
}

static void move_left(data_t *data)
{
    if (data->arr[data->px][data->py - 1] != '#') {
        if (movebox_left(data) == 0) {
            data->arr[data->px][data->py] = ' ';
            data->arr[data->px][data->py - 1] = 'P';
            data->py --;
        }
    }
}

static void move_up(data_t *data)
{
    if (data->arr[data->px - 1][data->py] != '#') {
        if (movebox_up(data) == 0) {
            data->arr[data->px][data->py] = ' ';
            data->arr[data->px - 1][data->py] = 'P';
            data->px --;
        }
    }
}

static void move_right(data_t *data)
{
    if (data->arr[data->px][data->py + 1] != '#') {
        if (movebox_right(data) == 0) {
            data->arr[data->px][data->py] = ' ';
            data->arr[data->px][data->py + 1] = 'P';
            data->py ++;
        }
    }
}

void test_input(data_t *data)
{
    if (data->key == KEY_RIGHT) {
        move_right(data);
    }
    if (data->key == KEY_UP) {
        move_up(data);
    }
    if (data->key == KEY_LEFT) {
        move_left(data);
    }
    if (data->key == KEY_DOWN) {
        move_down(data);
    }
}
