#include <stdio.h>
#include<stdlib.h>

#include "header.h"
#include "map.h"

MAP m; // variável global somente nesse arquivo, ou seja, foge_foge.c

void check_file_existence(FILE* file)
{
    if(file == 0)
    {
        puts("");
        puts("********************************************");
        puts("**   Falha no acesso ao banco de dados!   **");
        puts("********************************************");
        puts("");
        exit(1);
    }
}

int finish_game()
{
    return 0;
}

void move(char direction)
{
    int x;
    int y;

    // acha a posição do herói
    for(int i = 0; i < (m.rows); i++)
    {
        for(int j = 0; j < (m.columns); j++)
        {
            if(m.matrix[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
    case 'a':
        m.matrix[x][y - 1] = '@';
        break;
    case 'w':
        m.matrix[x - 1][y] = '@';
        break;
    case 's':
        m.matrix[x + 1][y] = '@';
        break;
    case 'd':
        m.matrix[x][y + 1] = '@';
        break;    
    default:
        puts("Comando inválido. As teclas válidas são apenas 'a', 'w', 's' e 'd'");
        break;
    }

    m.matrix[x][y] = '.';
}

int main()
{
    read_map(&m);

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