#include <stdio.h>
#include <stdlib.h>

#include "map.h"

// acha a posição do herói
void find_map(MAP* m, POSITION* p, char c)
{
    for(int i = 0; i < (m->rows); i++)
    {
        for(int j = 0; j < (m->columns); j++)
        {
            if(m->matrix[i][j] == c)
            {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

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

void read_map(MAP* m)
{
    FILE* file;

    file = fopen("map.txt", "r");
    
    check_file_existence(file);

    fscanf(file, "%d %d", &(m->rows), &(m->columns));
    printf("Matriz com %d linhas e %d colunas.\n", (m->rows), (m->columns));

    // alocação dinâmica de memória
    m->matrix = malloc(sizeof(char*) * (m->rows));
    for(int i = 0; i < (m->rows); i++)
    {
        m->matrix[i] = malloc(sizeof(char) * ((m->columns) + 1));
    }

    for(int i = 0; i < 5; i++)
    {
        fscanf(file, "%s", m->matrix[i]);
    }

    fclose(file);
}

void print_map(MAP* m)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", m->matrix[i]);
    }
}

// liberação da memória alocada dinamicamente
void release_map(MAP* m)
{  
    for(int i = 0; i < (m->rows); i++) 
    {
        free(m->matrix[i]);
    }
    free(m->matrix);   
}
