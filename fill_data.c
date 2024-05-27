/*
** EPITECH PROJECT, 2023
** fill_data.c
** File description:
** fills the data structure
*/

#include "my.h"

static void make_arr(data_t *data)
{
    int index = 0;
    int i = 0;
    int j = 0;

    data->arr = malloc(sizeof(char *) * data->nblin);
    for (int i = 0; i != data->nblin; i ++) {
        data->arr[i] = malloc(sizeof(char) * data->maxcol);
    }
    while (j != data->nblin) {
        if (data->map[index] == '\n') {
            data->arr[j][i] = '\n';
            i = 0;
            j ++;
        } else {
            data->arr[j][i] = data->map[index];
            i ++;
        }
        index ++;
    }
}

static void find_nblin(data_t *data)
{
    data->nblin = 0;
    for (int i = 0; data->map[i] != '\0'; i ++) {
        if (data->map[i] == '\n') {
            data->nblin ++;
        }
    }
}

static void find_maxcol(data_t *data)
{
    int max = 0;

    data->maxcol = 0;
    for (int i = 0; data->map[i] != '\n'; i ++) {
        if (data->maxcol < max) {
            max ++;
            data->maxcol = max;
        }
        if (data->map[i] == '\n') {
            max = 0;
        }
        max = 0;
    }
}

void get_pcoos(data_t *data)
{
    int i = 0;
    int j = 0;

    while (data->arr[i][j] != 'P') {
        if (data->arr[i][j] == '\n') {
            i ++;
            j = 0;
        } else {
            j ++;
        }
    }
    data->px = i;
    data->py = j;
}

o_t *create_o(int j, int i)
{
    o_t *O = malloc(sizeof(o_t));

    O->x = i;
    O->y = j;
    return O;
}

void data_iso(data_t *data, int j, int i)
{
    if (data->arr[j][i] == 'O') {
        data->olist[data->nbO] = create_o(j, i);
        data->nbO ++;
    }
}

void get_o(data_t *data)
{
    int nb = 0;

    data->nbO = 0;
    for (int j = 0; data->map[j] != '\0'; j ++) {
        if (data->map[j] == 'O')
            nb ++;
    }
    data->olist = malloc(sizeof(o_t) * nb);
    for (int j = 0; j != data->nblin; j ++) {
        for (int i = 0; data->arr[j][i] != '\n'; i ++) {
            data_iso(data, j, i);
        }
    }
}

static void test_file(char *str)
{
    int nbP = 0;

    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] != '#' && str[i] != ' ' && str[i] != 'X' && str[i] != 'O'
        && str[i] != '\n' && str[i] != 'P')
            exit(84);
        if (str[i] == 'P')
            nbP ++;
    }
    if (nbP != 1)
        exit(84);
}

static void open_file(data_t *data, char *file)
{
    struct stat s;
    char *str;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit(84);
    lstat(file, &s);
    if (s.st_size <= 0 || (s.st_mode & S_IFMT) != S_IFREG)
        exit(84);
    str = malloc(sizeof(char) * s.st_size + 1);
    read(fd, str, s.st_size);
    test_file(str);
    data->map = str;
    data->key = 0;
}

void fill_data(data_t *data, char *file)
{
    open_file(data, file);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    find_nblin(data);
    find_maxcol(data);
    make_arr(data);
    get_pcoos(data);
    get_o(data);
}
