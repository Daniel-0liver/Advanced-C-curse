#include <stdio.h>
#include <stdlib.h>

void    sum_vector_scaling(int vs[], int n, int	scaling) {
	for (int i = 0; i < n; i++)
	{
		vs[i] += scaling;
	}
}

void	print_vector(int *vs, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
	}
	puts("");
}

void	vector_desalocation(int	**v) {
	free(*v);
	*v = NULL;
}


int main() {

	puts("### STATIC VECTOR ###");
	int vs[5] = {0, 10, 20, 30, 40};
	
	print_vector(vs, 5);
	sum_vector_scaling(vs, 5, 9);
	print_vector(vs, 5);


	puts("### DINAMYC VECTOR WITH MALLOC ###");
	int *vm = (int *) malloc(5 * sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		vm[i] = i * 100;
	}

	print_vector(vm, 5);
	sum_vector_scaling(vm, 5, 9);
	print_vector(vm, 5);


	puts("### DINAMYC VECTOR WITH CALLOC ###");
	int *vc = (int *) calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		vc[i] = i * 1000;
	}

	print_vector(vc, 5);
	sum_vector_scaling(vc, 5, 9);
	print_vector(vc, 5);


	// Memory desalocation 
	vector_desalocation(&vc);

    return 0;
}