#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m = NULL;
	int	n_cols = 3;
	int	n_rows = 2;
	/************* Dinamyc allocation for matrix ***********/
    m = (int **) calloc(n_rows, sizeof(int*));

	// For each line of the matrix
	for (int i = 0; i < n_rows; i++)
	{
		m[i] = (int*) calloc(n_cols, sizeof(int));
	}
	/*******************************************************/
	
	printf("&m = %p, m = %p\n\n", &m, m);

	int	count = 0;

	for (int i = 0; i < n_rows; i++)
	{
		printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
		
		for (int j = 0; j < n_cols; j++)
		{

			m[i][j] = count++;
			
			printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
		}
		puts("");
	}

	/**********	Memory desalocation matrix dinamyc ************/

	for (int i = 0; i < n_rows; i++)
	{
		free(m[i]);
	}
	free(m);
	m = NULL;

	/**********************************************************/

	return 0;
	
}