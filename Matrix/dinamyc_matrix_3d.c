#include <stdlib.h>
#include <stdio.h>

int main() {
    
    int n_slices = 10;
    int n_rows = 10;
    int n_cols = 10;
    

    /************* Dinamyc allocation for matrix 3D ***********/
    int ***m = (int ***) calloc(n_slices, sizeof(int**));

	// For each slice of the matrix
	for (int i = 0; i < n_slices; i++)
	{
        m[i] = (int**) calloc(n_rows, sizeof(int*));

        for (int j = 0; j < n_rows; j++)
        {
            m[i][j] = (int *) calloc(n_cols, sizeof(int));   
        }
        
	}

    printf("&m = %p, m = %p\n\n", &m, m);
    /**********************************************************/

    int count = 0;

    for (int i = 0; i < n_slices; i++)
	{
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
        for (int j = 0; j < n_rows; j++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", i, j, &m[i][j], i, j, m[i][j]);
            for (int k = 0; k < n_cols; k++)
            {
                m[i][j][k] = count++;
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);
            }
            puts("");
        }
        puts("");
	}
    
    /**********	Memory desalocation 3D matrix dinamyc ************/

	for (int i = 0; i < n_slices; i++)
	{
        for (int j = 0; j < n_rows; j++)
        {
            free(m[i][j]);
        }
		free(m[i]);
        
	}
	free(m);
	m = NULL;

	/**********************************************************/

    return 0;

}