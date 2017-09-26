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

void decomposicaoLU(double **M, int dim)
{	
	double **L, **U;
     	int i,j,k, numop;
     	float soma1, soma2;
     	
     
      	U = malloc(dim*sizeof(double*));
      	L = malloc(dim*sizeof(double*));
      
      	numop=0;

     	for(i=0;i<dim;i++)
     	{	
     		L[i] = malloc((dim)*sizeof(double));	
        		L[i][0] = M[i][0];
     	}

     	i=0;

     	for(j=0;j<dim;j++)
     	{   
         	U[i] = malloc((dim)*sizeof(double)); 
         	if(i==j)
     		{	U[i][j] = 1.0;
     	  	 	i++;
     		}
         	U[0][j] = M[0][j]/L[0][0];
         	numop++;
         } 
     
    	soma1=0; soma2=0; 

     	for(i=1;i<dim;i++)
     	{	for(j=1;j<dim;j++)
     	  	{		 
     	        	for(k=0;k<j-1;k++)
     	        	{	soma1 = soma1 + U[k][i]*L[i][k];	
     	       			 L[i][j] = M[i][j] - soma1;
     	        
     	        		numop++;
     	        	}
     	  	}
     	  	
     	  	for(j=i+1;j<dim-1;j++)
     	 	{     
     	      		for(k=0;k<i-1;i++)
     	      		{	soma2 = soma2 + U[k][j]*L[i][k]; 	
     	      			numop++;	
     	      		}
 	      	U[i][j] = (M[i][j] - soma2)/L[i][i];
 	      	numop++;
 	      	}
    	}
 	
 	printf ("\nA matriz L é:\n");
 	imprime(L, dim);
 	printf ("\nA matriz U é:\n");
 	imprime(U, dim);
 	
 	printf ("\nO número de operações (n) é: %d \n", numop);
}

int main(int argc, char *argv[])
{
	int i, j, dim;
	double **M, a;
	FILE *leitura;

	leitura = fopen(argv[1],"r");
	i = fscanf(leitura, "%d", &dim);
	M = malloc(dim*sizeof(double*));

	lermatriz(M,dim,leitura);

	printf("matriz digitada: \n");
	imprime(M,dim);

	decomposicaoLU(M, dim);
}


























