#include<stdio.h>
#include<stdlib.h>

void imprime(double **M, int dim)
{
	int i, j;

		for(i=0; i<dim; i++)
		{
		  for(j=0; j<dim+1; j++)
		  {
			printf("%.2lf \t", M[i][j]);
		  }
		printf("\n");
		}
	printf("\n");
}
	
	
void lermatriz(double **M, int dim, FILE*leitura)
{
	int i, j;
	double a;

		for(i=0; i<dim; i++)
		{
			M[i]=malloc((dim+1)*sizeof(double));
		}
	i=j=0;

		while(fscanf(leitura, "%lf", &a) != EOF)
		{
			M[i][j]=a;
			j++;
			if(j==dim+1)
				{
					j=0;
					i++;
				}
		}

}

int main()
{
	int i, j, dim;
	double **M, a;
	FILE *leitura;

	leitura = fopen("matriz.dat","r");
	i = fscanf(leitura, "%d", &dim);
	M = malloc(dim*sizeof(double*));

	lermatriz(M,dim,leitura);

	printf("Matriz digitada: \n");
	imprime(M,dim);
}


























