/*#include <math.h>
#include <stdio.h>
#define N 1
#define x_length (double)(M_PI * 1.0)
#define t_length (double)10
#define lambda .004
#define D 1.0
#define deltax (double)(M_PI/10.0)
#define x_num (int)(round(x_length/deltax))+1
#define deltat (double)((lambda/D)*(deltax*deltax))
#define t_num (int)(round(t_length/deltat))

void Jacobi(double UJ[t_num][x_num])
{
	int k,max=10;
	double A=1+ 2*lambda,B=-lambda,C=-lambda,U[x_num], g_array[x_num];
	for (int var2 = 1; var2 < t_num; ++var2) {

		for(k=0;k<x_num-1;k++)
		{
			U[k]=0;
			g_array[k]=UJ[var2-1][k];

		}
		for(k=0;k<max;k++)
		{
			for(int x=1;x<x_num-1;x++)
			{
						U[x]= (g_array[x] - ( B*U[x-1] + C*U[x+1]))/A;
					//printf("x %d,g %lf, U[x]=%lf ",x, g_array[x],( B*U[x-1] + C*U[x+1]));

			}
			//printf("\n");
		}
	//	printf("\n");
		for(k=0;k<x_num-1;k++)
				{
					UJ[var2][k]=U[k];
				}

	}

}
double function(double x)
{
	return sin(N*x);
}
double function2(double x)
{
	return cos((N-.5)*x);
}
void init_array(double u[t_num][x_num],int n)
{

	for(int xi =0; xi<t_num;xi++)
		{
		for(int xii =0; xii<x_num;xii++)
		{
			u[xi][xii]=0;


		}}
	int x=0;
	double temp;
	for(double xi =0; xi<x_length;xi+=deltax)
	{
		if(x>x_num)
			break;
		if(n==1)
		temp=function(xi);
		else
		temp = function2(xi);
		u[0][x]=temp;

		//printf("%lf ",function(xi));

		x++;
	}
	u[0][x_num-1]=0;
}
void printArr(double u[t_num][x_num],int n)
{
	int v=0;
	for (double var2 = 0; var2 < t_length-deltat; var2+=deltat) {
		for (int var = 0; var < x_num; var++)
		{
			printf("%lf ",u[v][var]);

		}
		printf(" ");
		for (double var = 0; var < x_length; var+=deltax)
		{
			if(n==1) printf("%lf ",exp(-(N*N*(var2)))*sin(N*var));
			else printf("%lf ",exp(-pow((N-.5),2)*var2)*cos((N-.5)*var));
			//printf("%lf %lf\n", var2,var);
		}
		printf(" %lf", 0.0);
			printf("\n");
			v++;
		}
	printf("\n");
}
void print_error(double uex[t_num][x_num],double uex2[t_num][x_num]){
	FILE *f = fopen("Error_linear.csv","w"),*f2=fopen("Numbers.csv","w");
	fprintf(f,"Ex_Error,Ex2_Error,time\n");
	fprintf(f2,"Ex,Exact, time\n");
	double exact,exact2;
	int v=0;
	for (double var2 = 0; var2 < t_length-deltat; var2+=deltat) {
		exact=exp(-(N*N*(var2)))*sin(N*(deltax));
		exact2=exp(-pow((N-.5),2)*var2)*cos((N-.5)*deltax);
		fprintf(f,"%lf, ",fabs(((exact-uex[v][1])/exact))*100);
		fprintf(f,"%lf, ",fabs(((exact2-uex2[v][1])/exact2))*100);
		fprintf(f,"%lf",var2);
		fprintf(f,"\n");
		v++;}
	fclose(f);
	fclose(f2);

}
void Jacobi2(double UJ[t_num][x_num])
{
	int k,max=8;
	double A=1+ 2*lambda,B=-lambda,C=-lambda,U[x_num], g_array[x_num];
	for (int var2 = 1; var2 < t_num; ++var2) {

		for(k=0;k<x_num;k++)
		{
			U[k]=cos((N-.5)*(k*deltax));
		//	printf("%lf ",U[k]);
			g_array[k]=UJ[var2-1][k];

		}
		for(k=0;k<max;k++)
		{
			for(int x=0;x<x_num-1;x++)
			{

					if(x==0)
					{
						U[x]= (g_array[x] - (B*U[x+1] + C*U[x+1]))/A;
					}
					else
					U[x]= (g_array[x] - ( B*U[x-1] + C*U[x+1]))/A;

			}
		}

		for(k=0;k<x_num-1;k++)
				{
					UJ[var2][k]=U[k];
				}

	}

}
int main()
{
	double U2[t_num][x_num];
	//printf("%d",x_num);
	init_array(U2,1);
	Jacobi(U2);
	//printArr(U2,1);

	double U3[t_num][x_num];
	//printf("%d",x_num);
	init_array(U3,2);
	Jacobi2(U3);
	printArr(U3,2);
	print_error(U2,U3);
	return 1;
}*/

