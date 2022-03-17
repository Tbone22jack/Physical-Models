/*#include <math.h>
#include <stdio.h>
#define N 1
#define x_length (double)(M_PI * 1.0)
#define t_length (double)1
#define lambda .004
#define D 1.0
#define deltax (double)(M_PI/10.0)
#define x_num (int)(round(x_length/deltax))+1
#define deltat (double)((lambda/D)*(deltax*deltax))
#define t_num (int)(round(t_length/deltat))



double function(double x)
{
	return sin(N*x);
}
void init_array(double u[t_num][x_num])
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
		temp=function(xi);
		u[0][x]=temp;

		//printf("%lf ",function(xi));

		x++;
	}
	u[0][x_num-1]=0;
}
void fill_array_explicit(double u[t_num][x_num])
{

	for (int var2 = 0; var2 < t_num-1; var2++)
	{
		u[var2+1][0]=0;
		u[var2+1][x_num-1]=0;
		for (int var = 1; var <x_num-1; var++) {
				u[var2+1][var]=u[var2][var] + lambda*(u[var2][var-1] - 2*u[var2][var] +u[var2][var+1]);

			}
	}

}
void printArr(double u[t_num][x_num])
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
			printf("%lf ",exp(-(N*N*(var2)))*sin(N*var));
			//printf("%lf %lf\n", var2,var);
		}
		printf(" %lf", 0.0);
			printf("\n");
			v++;
		}
}
void implicit(double u[t_num][x_num])
{

	double f_array[x_num],A[x_num],B[x_num],C[x_num],alpha[x_num],g[x_num];
	int xi;
for (int var2 = 1; var2 < t_num; ++var2) {
			u[var2][0]= 0;
			xi=0;
			for(int c=0;c< x_num;c++)
							{
					A[c]=(1+2*lambda);
					xi++;
				}
					A[0]=1;
					A[x_num-1]=1;
				xi=0;
				for(int c=0;c< x_num;c++)
				{
					B[c]=-(lambda);
					C[c]=-(lambda);

				}
							B[0]=0;
							B[x_num-1]=0;
							C[x_num-1]=0;
							C[0]=0;
				xi=1;


			for(int x=1;x<x_num-1;x++)
				{
				f_array[x]=u[var2-1][x];
				}

			f_array[0]=u[var2-1][0];


			alpha[0]= A[0];
			g[0]=f_array[0];

			int j=1;

			for(j=1;j<x_num;j++)
			{

				alpha[j]= A[j] - (B[j]*C[j-1])/alpha[j-1];
				g[j]= f_array[j]-(B[j]*g[j-1])/alpha[j-1];

			}
			u[var2][x_num-2]= g[x_num-2]/alpha[x_num-2];
			j=2;
			for (j=x_num-3;j>0;j--)
			{
				u[var2][j]= (g[j]-C[j]*u[var2][j+1])/alpha[j];
			}



	}
}
void C_N(double u[t_num][x_num])
{

	double f_array[x_num],A[x_num],B[x_num],C[x_num],alpha[x_num],g[x_num];
	int xi;
	for (int var2 = 1; var2 < t_num; ++var2) {
		u[var2][0]= 0;
		xi=0;
		for(int c=0;c< x_num;c++)
						{
				A[c]=(1+lambda);
				xi++;
			}
			A[0]=1;
			A[x_num-1]=1;
			xi=0;
			for(int c=0;c< x_num;c++)
							{
				B[c]=-(lambda/2);
				C[c]=-(lambda/2);
				xi++;
			}
			B[0]=0;
			B[x_num-1]=0;
			C[x_num-1]=0;
			C[0]=0;
			xi=1;


		for(int x=1;x<x_num-1;x++)
			{
			f_array[x]=(lambda/2.0)*u[var2-1][x-1]+(1-lambda)*u[var2-1][x]+(lambda/2.0)*u[var2-1][x+1];
			}

		f_array[0]=0;
		f_array[x_num-1]=0;

		alpha[0]= A[0];
		g[0]=f_array[0];

		int j=1;

		for(j=1;j<x_num;j++)
		{

			alpha[j]= A[j] - (B[j]*C[j-1])/alpha[j-1];
			g[j]= f_array[j]-(B[j]*g[j-1])/alpha[j-1];

		}
		u[var2][x_num-1]= 0;
		j=2;
		for (j=x_num-2;j>0;j--)
		{
			u[var2][j]= (g[j]-C[j]*u[var2][j+1])/alpha[j];
		}


	}
}
void print_error(double uex[t_num][x_num],double uim[t_num][x_num],double ucn[t_num][x_num]){
	FILE *f = fopen("Error.csv","w"),*f2=fopen("Numbers.csv","w");
	fprintf(f,"Ex_Error, Im_Error, CN_Error,time\n");
	fprintf(f2,"Ex, Im, CN, Exact, time\n");
	double exact;
	int v=0;
	for (double var2 = 0; var2 < t_length-deltat; var2+=deltat) {
		exact=exp(-(N*N*(var2)))*sin(N*(deltax));
		fprintf(f,"%lf, ",fabs(((exact-uex[v][1])/exact))*100);
		fprintf(f,"%lf, ",fabs(((exact-uim[v][1])/exact))*100);
		fprintf(f,"%lf, ",fabs(((exact-ucn[v][1])/exact))*100);
		fprintf(f,"%lf",var2);
		fprintf(f,"\n");
		fprintf(f2,"%lf, ",uex[v][1]);
		fprintf(f2,"%lf, ",uim[v][1]);
		fprintf(f2,"%lf, ",ucn[v][1]);
		fprintf(f2,"%lf, ",exact);
		fprintf(f2,"%lf",var2);
		fprintf(f2,"\n");
		v++;	}
	fclose(f);
	fclose(f2);

}
int main(){


	double u[t_num][x_num];
	printf("%d %d\n",x_num,t_num);
	init_array(u);

	fill_array_explicit(u);



	//printf("\n");
	double u1[t_num][x_num];
	//print_array(u1);
	init_array(u1);

	implicit(u1);


	printArr(u1);
	double u2[t_num][x_num];
	init_array(u2);
	C_N(u2);
	print_error(u, u1, u2);
	return 1;
}*/

