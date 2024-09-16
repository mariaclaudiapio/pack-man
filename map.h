struct map
{
    char** matrix;
    int rows;
    int columns;
};

typedef struct map MAP;

void read_map(MAP* m);
void print_map(MAP* m);
void release_map(MAP* m);