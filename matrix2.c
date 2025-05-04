#include <stdio.h>
#include <stdlib.h>
#include <math.h> //одномерный по столбцам
void Hilbert(double *mas,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            mas[i+j*n]=1.0/(i+j+1.0);
        }
   }return;}
   long long factorial(int n) 
   {
    if (n<=1)
     return 1;
    long long fact=1;
    for (int i=2;i<=n;i++) 
    {
        fact*=i;
    }
    return fact;
}
   void InverseHilbert(double *mas, int n)
    {
    int i,j;
    for(i=0;i<n;i++) 
    {
        for (j=0;j<n;j++) 
        {
     double num=factorial(n+i)*factorial(n+j);
         double denom=pow(factorial(i),2)*pow(factorial(j),2)*factorial(n-i-1)*factorial(n-j-1)*(i+j+1);
            mas[j*n+i]=pow(-1,i+j)*(num/denom);
        }
    }
}
    int main ()
    { int n;
		printf("Укажите количество строк и столбцов \n");
		scanf("%d",&n);
FILE*fp=fopen("output.txt","w");
double *mas=NULL;
      mas=(double*)malloc(n*n*sizeof(double));
	Hilbert(mas,n);
		for(int i=0;i<n;i++)
		{ for(int j=0; j<n ; j++)
			{fprintf(fp,"%10.6lf",mas[i*n+j]);}
			fprintf(fp,"\n");
			}
			fprintf(fp,"Обратная матрица\n");
			InverseHilbert(mas,n);
			
				for(int i=0;i<n;i++)
		 {for(int j=0; j<n ; j++)
			{fprintf(fp,"%10.6lf ",mas[i*n+j]);}
			fprintf(fp,"\n");
			}
	return 0;	}
