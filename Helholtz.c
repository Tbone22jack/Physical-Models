/*#include <stdio.h>
#include <math.h>
#define Uo 0
#define Ul 0

int main()
{

	int N=1000;
	double u_array[N],f_array[N],A[N],B[N],C[N],alpha[N],g[N];
	double L=1.0,temp=0,h= ((double)L)/((double)N),Q=10,lambda=1.0;
	int xi=0;

	for(double c=0;c<L;c+=h)
		{

			A[xi]=2+pow(h,2);
			xi++;
		}

		xi=0;
		for(double c=0;c<L;c+=h)
		{
			B[xi]=-1;
			C[xi]=-1;

			xi++;

		}
		B[0]=0;
		C[N-1]=0;
		xi=0;


	for(double x=0;x<L;x+=h)
		{
		f_array[xi]=exp(-Q*x)*pow(h,2);
		xi++;

		}
	alpha[0]= A[0];
	g[0]=f_array[0];

	int j=1;

	for(double x=h; x<L;x+=h)
	{

		alpha[j]= A[j] - (B[j]*C[j-1])/alpha[j-1];
		g[j]= f_array[j]-(B[j]*g[j-1])/alpha[j-1];
		j++;

	}
	u_array[N-1]= g[N-1]/alpha[N-1];
	j=2;
	for (double x = 2*h; x < L+h; x+=h)
	{

		u_array[N-j]= (g[N-j]-C[N-j]*u_array[N-j+1])/alpha[N-j];
		j++;
		//printf("%lf\n", u_array[N-k]);
	}
	//for(int j=0;j<N;j++)
		//printf("%lf\n", u_array[j]);
	double exact;
	j=0;
	for(double b =0; b<L-h;b+=h)
		{

			exact= (Q/(lambda*(Q*Q - lambda*lambda)*sinh(lambda*L)))*(sinh(b-L)- exp(-Q*b)*(sinh(lambda*L)-sinh(lambda*b)));


			printf("appox[%d]:%lf exact[%d]:%lf error:%lf\n",j, u_array[j],j,exact,(fabs(exact - u_array[j])/exact)*100);
			j++;
		}
	return 0;
}
*/
