/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** header
*/

#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct o_s {
    int x;
    int y;
}o_t;

typedef struct data_s {
    char *map;
    char **arr;
    int nblin;
    int maxcol;
    int px;
    int py;
    int key;
    o_t **olist;
    int nbO;
}data_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void test_input(data_t *data);
void fill_data(data_t *data, char *file);
void is_blocked(data_t *data);
void display_arr(data_t *data);
int my_strcmp(char const *s1, char const *s2);
