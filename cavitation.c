/*#include <stdio.h>
#include <math.h>]
#define EPSILON .00000001
double f1(double u1,double u2)
{
	double ans = (-(1.5)*pow(u2,2) - 1.0 )/u1 + 1.0/pow(u1,4);
			return  ans;
}
double Rk1(double ur,double uf,double deltat,int loop)
	{

							jdouble u2=uf,u1=ur,u1st,u1sst,u1ssst,u1p,u2st,u2sst,u2ssst,u21;
							for (int var = 0; var < loop; ++var) {


														u1st= u1+(deltat/2)*u2;
														u2st= u2+(deltat/2)*f1(u1,u2);
														u1sst= u1 + (deltat/2)*u2st;
														u2sst= u2 + (deltat/2)*f1(u1st,u2st);
														u1ssst = u1 + deltat * u2sst;
														u2ssst = u2 + deltat * f1(u1sst,u2sst);
														u1p=u1+((deltat/6)*(u2+ 2*u2st+ 2*u2sst+u2ssst));
														u21=u2+((deltat/6)*((f1(u1,u2)+ 2*f1(u1st,u2st)+ 2*f1(u1sst,u2sst)+f1(u1ssst,u2ssst))));
														u1=u1p;
														u2=u21;
							//printf("%lf ",u1);
							}

									return u1;
	}
double adj_del_t(double u1,double u2,double deltat)
{
	double delta,deltades,sigma;
	//printf("\n%lf %lf\n",Rk1(u1, u2, deltat,1) ,Rk1(u1, u2, deltat/2.0,2));
	delta = fabs(Rk1(u1, u2, deltat/2.0,2)-Rk1(u1, u2, deltat,1));
	deltades = EPSILON*(fabs(u1)+deltat*fabs(u2));

	sigma= deltades/delta;
	if(delta<deltades)
	{

		return deltat*pow(sigma,.2);
	}
		return deltat*pow(sigma,.25);
}
int main()
{
	double u1=1.0 +.2,u1p,u1st,u1sst,u1ssst,u2sst,u2ssst,u2st,u2=0.0,u21,deltat=.1;

	//deltat= adj_del_t(u1, u2, deltat);

	for(double time=deltat;time<4;time+=deltat)
	{



						u1st= u1+(deltat/2)*u2;
						u2st= u2+(deltat/2)*f1(u1,u2);
						u1sst= u1 + (deltat/2)*u2st;
						u2sst= u2 + (deltat/2)*f1(u1st,u2st);
						u1ssst = u1 + deltat * u2sst;
						u2ssst = u2 + deltat * f1(u1sst,u2sst);
						u1p=u1+((deltat/6)*(u2+ 2*u2st+ 2*u2sst+u2ssst));
						u21=u2+((deltat/6)*((f1(u1,u2)+ 2*f1(u1st,u2st)+ 2*f1(u1sst,u2sst)+f1(u1ssst,u2ssst))));
						u1=u1p;
						u2=u21;
						deltat = adj_del_t(u1, u2, deltat);
						//printf("%lf ", deltat);
						printf("%lf ", u1);


	}

	return 0;
}*/
