/*#include <math.h>
#include <stdio.h>
#define BETA 8.0/3.0
#define RHO 28
#define SIGMA 2
#define EPSILON .000001
double xfunc(double x,double y,double z)
{
	return SIGMA*(y-x);
}
double yfunc(double x,double y,double z)
{
	return x*(RHO -z)-y;
}
double zfunc(double x,double y,double z)
{
	return x*y - BETA*z;
}
double Rk1(double xa,double ya,double za,double deltat,int loop)
{

							double x=xa,y=ya,z=za,xp,yp,zp,xs,ys,zs,xss,yss,zss,xsss,ysss,zsss;
								for(int val=0;val<loop;val++)
								{
														xs= x+(deltat/2)*xfunc(x,y,z);
														ys= y+(deltat/2)*yfunc(x,y,z);
														zs= z+(deltat/2)*zfunc(x,y,z);
														xss= x+(deltat/2)*xfunc(xs,ys,zs);
														yss= y+(deltat/2)*yfunc(xs,ys,zs);
														zss= z+(deltat/2)*zfunc(zs,ys,zs);
														xsss= x + xfunc(xss, yss, zss);
														ysss= y + yfunc(xss, yss, zss);
														zsss= z + zfunc(xss, yss, zss);
														xp=x+((deltat/6)*(xfunc(x, y, z)+ 2*xfunc(xs, ys, zs)+ 2*xfunc(xss, yss, zss)+xfunc(xsss, ysss, zsss)));
														yp=y+((deltat/6)*(yfunc(x, y, z)+ 2*yfunc(xs, ys, zs)+ 2*yfunc(xss, yss, zss)+yfunc(xsss, ysss, zsss)));
														zp=z+((deltat/6)*(zfunc(x, y, z)+ 2*zfunc(xs, ys, zs)+ 2*zfunc(xss, yss, zss)+zfunc(xsss, ysss, zsss)));
														x=xp;
														y=yp;
														z=zp;
								}
									return xp;
	}
double adj_del_t(double x,double y,double z,double deltat,double xp)
{
	double delta,deltades,sigma;
	//printf("\n%lf %lf\n",Rk1(u1, u2, deltat,1) ,Rk1(u1, u2, deltat/2.0,2));
	delta = fabs(Rk1(x, y,z, deltat/2.0,2)-Rk1(x, y,z, deltat,1));
	if(fabs(x)>fabs(y) && fabs(x)>fabs(z))
	deltades = EPSILON*(fabs(Rk1(x, y,z, deltat/2.0,2)));
	else if(fabs(x)>fabs(y) && fabs(x)>fabs(z))
	deltades = EPSILON*(fabs(Rk1(y, x,z, deltat/2.0,2)));
	else
	deltades = EPSILON*(fabs(Rk1(z, y,x, deltat/2.0,2)));

	sigma= deltades/delta;
	if(delta<deltades)
	{

		return deltat*pow(sigma,.2);
	}
		return deltat*pow(sigma,.25);
}
int main()
{
	FILE *fp;
	fp = fopen("lorenz.csv","w");
	fprintf(fp,"x coord, y coord, z coord, time, velx, vely, velz\n");
	double x=1,y=1,z=1,xp,yp,zp,xs,ys,zs,xss,yss,zss,xsss,ysss,zsss,deltat=.1,velx,vely,velz;
	for(double time=deltat;time<600;time+=deltat)
	{
							xs= x+(deltat/2)*xfunc(x,y,z);
							ys= y+(deltat/2)*yfunc(x,y,z);
							zs= z+(deltat/2)*zfunc(x,y,z);
							xss= x+(deltat/2)*xfunc(xs,ys,zs);
							yss= y+(deltat/2)*yfunc(xs,ys,zs);
							zss= z+(deltat/2)*zfunc(zs,ys,zs);
							xsss= x + (deltat/2)*xfunc(xss, yss, zss);
							ysss= y + (deltat/2)*yfunc(xss, yss, zss);
							zsss= z + (deltat/2)*zfunc(xss, yss, zss);
							xp=x+((deltat/6)*(xfunc(x, y, z)+ 2*xfunc(xs, ys, zs)+ 2*xfunc(xss, yss, zss)+xfunc(xsss, ysss, zsss)));
							yp=y+((deltat/6)*(yfunc(x, y, z)+ 2*yfunc(xs, ys, zs)+ 2*yfunc(xss, yss, zss)+yfunc(xsss, ysss, zsss)));
							zp=z+((deltat/6)*(zfunc(x, y, z)+ 2*zfunc(xs, ys, zs)+ 2*zfunc(xss, yss, zss)+zfunc(xsss, ysss, zsss)));
							velx=(x-xp)*deltat;
							vely=(y-yp)*deltat;
							velz=(z-zp)*deltat;


							x=xp;
							y=yp;
							z=zp;
							deltat=adj_del_t(x, y, z, deltat,xp);
							fprintf(fp,"%lf, %lf, %lf, %lf,%lf ,%lf ,%lf\n",x,y,z,time,velx,vely,velz);
							printf("%lf %lf %lf %lf\n",x,y,z,deltat);
	}
	return 0;
}*/
