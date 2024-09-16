#include <stdio.h>
#include <stdlib.h>

#include "map.h"

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
