typedef struct map
{
    char** matrix;
    int rows;
    int columns;
} MAP;

typedef struct position
{
    int x;
    int y;
} POSITION;

void check_file_existence(FILE* file);
void read_map(MAP* m);
void print_map(MAP* m);
void release_map(MAP* m);
void find_map(MAP* m, POSITION* p, char c);