#include <stdio.h>
#include <stdlib.h>

int **int_matrix(int n_rows, int n_cols) {
    int **m = (int **) calloc(n_rows, sizeof(int*));
    int count = 0;

    for (int i = 0; i < n_rows; i++)
    {
        m[i] = (int*) calloc(n_cols, sizeof(int));
    }

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            m[i][j] = count++;
        }
    }
    
    return m;
}

void print_matrix(int **m, int n_rows, int n_cols) {
    
    for (int i = 0; i < n_rows; i++)
	{
		printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
		
		for (int j = 0; j < n_cols; j++)
		{
			printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
		}
		puts("");
	}
}

void    matrix_scaling(int **m, int n_rows, int n_cols, int	scaling) {
	for (int i = 0; i < n_rows; i++)
	{
        for (int j = 0; j < n_cols; j++)
        {
            m[i][j] += scaling;
        }
	}
}

void unlock_all_matrix(int ***m, int n_rows, int n_cols) {
    for (int i = 0; i < n_rows; i++)
    {
        free(m[i]);
    }
    free(*m);
    *m = NULL;
}

int main(int argc, char **argv) {

    if (argc != 4)
    {
        printf("ERROR\n");
        exit(-1);
    }

    int n_rows = atoi(argv[1]);
    int n_cols = atoi(argv[2]);
    int scaling = atoi(argv[3]);

    int **m = int_matrix(n_rows, n_cols);
    print_matrix(m, n_rows, n_cols);
    matrix_scaling(m, n_rows, n_cols, scaling);
    print_matrix(m, n_rows, n_cols);   
    unlock_all_matrix(&m, n_rows, n_cols);

    printf("\nm is free? %d\n", m == NULL);

    return 0;
}