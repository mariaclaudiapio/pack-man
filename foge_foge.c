#include <stdio.h>
#include<stdlib.h>

#include "header.h"
#include "map.h"

MAP m; // variável global somente nesse arquivo, ou seja, foge_foge.c
POSITION hero;

int finish_game()
{
    return 0;
}

void move(char direction)
{
    m.matrix[hero.x][hero.y] = '.';    

    switch (direction)
    {
    case 'a':
        m.matrix[hero.x][hero.y - 1] = '@';
        hero.y--;
        break;
    case 'w':
        m.matrix[hero.x - 1][hero.y] = '@';
        hero.x--;
        break;
    case 's':
        m.matrix[hero.x + 1][hero.y] = '@';
        hero.x++;
        break;
    case 'd':
        m.matrix[hero.x][hero.y + 1] = '@';
        hero.y++;
        break;    
    default:
        puts("Comando inválido. As teclas válidas são apenas 'a', 'w', 's' e 'd'");
        break;
    }
}

int main()
{
    read_map(&m);
    find_map(&m, &hero, '@');

    do
    {
        print_map(&m);

        char comand;
        scanf(" %c", &comand);
        move(comand);
    }
    while(!finish_game());    

    release_map(&m);   
}