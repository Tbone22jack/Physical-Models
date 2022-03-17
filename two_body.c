/*#include <math.h>
#include <stdio.h>
#define G 6.67*pow(10,-11)
#define EPSILON pow(10,-11)
struct R_Vector
{
	double x,y,mass;
	double velx,vely;
};
double r12 (struct R_Vector r1,struct R_Vector r2)
{
	return pow(pow(r1.x-r2.x,2)+pow(r1.y-r2.y,2),.5);
}
struct R_Vector function2(struct R_Vector r1,struct R_Vector r2)
{

	struct R_Vector  temp;
	temp.x= r1.velx;
	temp.y= r1.vely;
	temp.velx=-(G*r2.mass*(r1.x-r2.x))/pow(r12(r1,r2),3);
	//printf("%lf ",r2.mass);
	temp.vely=-(G*r2.mass*(r1.y-r2.y))/pow(r12(r1,r2),3);
	temp.mass=r1.mass;
	return temp;
}
struct R_Vector * RK1(struct R_Vector r1,struct R_Vector r2,int size,int num,double deltat)
{





	struct R_Vector r[size],star[size],sstar[size],ssstar[size],p[size];


						r[0].x=r1.x;
						r[0].y=r1.y;
						r[0].velx=r1.velx;
						r[0].vely=r1.vely;
						r[1].x=r2.x;
						r[1].y=r2.y;
						r[1].velx=r2.velx;
						r[1].vely=r2.vely;
						r[0].mass=r1.mass;
						r[1].mass=r2.mass;

	for (double var = 0; var < ((double)num*deltat); var+=deltat)
	{


		for(int loop = 0; loop<size; loop+=2){

				star[loop].mass= r[loop].mass;
				star[loop+1].mass= r[loop+1].mass;
				sstar[loop].mass= r[loop].mass;
				sstar[loop+1].mass= r[loop+1].mass;
				ssstar[loop].mass= r[loop].mass;
				ssstar[loop+1].mass= r[loop+1].mass;




				//printf("%lf %lf %lf",r[loop+1].vely,function2(r[loop+1],r[loop]).vely,star[loop+1].vely);

				}
		for(int loop = 0; loop<size; loop+=2){

		star[loop].x= r[loop].x+(deltat/2)*function2(r[loop],r[loop+1]).x;
		star[loop].y= r[loop].y+(deltat/2)*function2(r[loop],r[loop+1]).y;
		star[loop].velx= r[loop].velx+(deltat/2)*function2(r[loop],r[loop+1]).velx;
		star[loop].vely= r[loop].vely+(deltat/2)*function2(r[loop],r[loop+1]).vely;
		star[loop+1].x= r[loop+1].x+(deltat/2)*function2(r[loop+1],r[loop]).x;
		star[loop+1].y= r[loop+1].y+(deltat/2)*function2(r[loop+1],r[loop]).y;
		star[loop+1].velx= r[loop+1].velx+((deltat/2)*function2(r[loop+1],r[loop]).velx);
		star[loop+1].vely= r[loop+1].vely+(deltat/2)*function2(r[loop+1],r[loop]).vely;

		//printf("%lf %lf %lf",r[loop+1].vely,function2(r[loop+1],r[loop]).vely,star[loop+1].vely);
		//printf("star %lf %lf %lf %lf\n",star[loop].x,star[loop].y,star[loop].velx,star[loop].vely);

		}


		for(int loop = 0; loop<size; loop+=2)
		{
				sstar[loop].x= r[loop].x+(deltat/2)*function2(star[loop],star[loop+1]).x;
				sstar[loop].y= r[loop].y+(deltat/2)*function2(star[loop],star[loop+1]).y;
				sstar[loop].velx= r[loop].velx+(deltat/2)*function2(star[loop],star[loop+1]).velx;
				sstar[loop].vely= r[loop].vely+(deltat/2)*function2(star[loop],star[loop+1]).vely;
				sstar[loop+1].x= r[loop+1].x+(deltat/2)*function2(star[loop+1],star[loop]).x;
				sstar[loop+1].y= r[loop+1].y+(deltat/2)*function2(star[loop+1],star[loop]).y;
				sstar[loop+1].velx= r[loop+1].velx+((deltat/2)*function2(star[loop+1],star[loop]).velx);
				sstar[loop+1].vely= r[loop+1].vely+(deltat/2)*function2(star[loop+1],star[loop]).vely;
			//	printf("%lf\n",function2(r[loop+1],r[loop]).vely);
				//printf("sstar %lf %lf %lf %lf\n",sstar[loop].x,sstar[loop].y,sstar[loop].velx,sstar[loop].vely);

				}
		for(int loop = 0; loop<size; loop+=2)
				{
						ssstar[loop].x= r[loop].x+deltat*function2(sstar[loop],sstar[loop+1]).x;
						ssstar[loop].y= r[loop].y+deltat*function2(sstar[loop],sstar[loop+1]).y;
						ssstar[loop].velx= r[loop].velx+deltat*function2(sstar[loop],sstar[loop+1]).velx;
						ssstar[loop].vely= r[loop].vely+deltat*function2(sstar[loop],sstar[loop+1]).vely;
						ssstar[loop+1].x= r[loop+1].x+deltat*function2(sstar[loop+1],sstar[loop]).x;
						ssstar[loop+1].y= r[loop+1].y+deltat*function2(sstar[loop+1],sstar[loop]).y;
						ssstar[loop+1].velx= r[loop+1].velx+(deltat*function2(sstar[loop+1],sstar[loop]).velx);
						ssstar[loop+1].vely= r[loop+1].vely+deltat*function2(sstar[loop+1],sstar[loop]).vely;
						//printf("%lf ",ssstar[loop+1].vely);

						//printf("%lf %lf %lf %lf %lf \n",r[loop+1].x,star[loop+1].x,sstar[loop+1].x,ssstar[loop+1].x,deltat);
						//printf("ssstar %lf %lf %lf %lf\n",ssstar[loop].x,ssstar[loop].y,ssstar[loop].velx,ssstar[loop].vely);
						}

		for(int loop = 0; loop<size; loop+=2)
		{
										p[loop].x= r[loop].x+((deltat/6)*(function2(r[loop],r[loop+1]).x+ 2*function2(star[loop],star[loop+1]).x+ 2*function2(sstar[loop],sstar[loop+1]).x+function2(ssstar[loop],ssstar[loop+1]).x));
										p[loop].y= r[loop].y+((deltat/6)*(function2(r[loop],r[loop+1]).y+ 2*function2(star[loop],star[loop+1]).y+ 2*function2(sstar[loop],sstar[loop+1]).y+function2(ssstar[loop],ssstar[loop+1]).y));
										p[loop].velx= r[loop].velx+((deltat/6)*(function2(r[loop],r[loop+1]).velx+ 2*function2(star[loop],star[loop+1]).velx+ 2*function2(sstar[loop],sstar[loop+1]).velx+function2(ssstar[loop],ssstar[loop+1]).velx));
										p[loop].vely= r[loop].vely+((deltat/6)*(function2(r[loop],r[loop+1]).vely+ 2*function2(star[loop],star[loop+1]).vely+ 2*function2(sstar[loop],sstar[loop+1]).vely+function2(ssstar[loop],ssstar[loop+1]).vely));
										p[loop+1].x= r[loop+1].x+((deltat/6)*(function2(r[loop+1],r[loop]).x+ 2*function2(star[loop+1],star[loop]).x+ 2*function2(sstar[loop+1],sstar[loop]).x+function2(ssstar[loop+1],ssstar[loop]).x));
										p[loop+1].y= r[loop+1].y+((deltat/6)*(function2(r[loop+1],r[loop]).y+ 2*function2(star[loop+1],star[loop]).y+ 2*function2(sstar[loop+1],sstar[loop]).y+function2(ssstar[loop+1],ssstar[loop]).y));
										p[loop+1].velx= r[loop+1].velx+((deltat/6)*(function2(r[loop+1],r[loop]).velx+ 2*function2(star[loop+1],star[loop]).velx+ 2*function2(sstar[loop+1],sstar[loop]).velx+function2(ssstar[loop+1],ssstar[loop]).velx));
										p[loop+1].vely= r[loop+1].vely+((deltat/6)*(function2(r[loop+1],r[loop]).vely+ 2*function2(star[loop+1],star[loop]).vely+ 2*function2(sstar[loop+1],sstar[loop]).vely+function2(ssstar[loop+1],ssstar[loop]).vely));

		}
		for(int loop = 0; loop<size; loop+=1)
				{
										//printf("%lf,%lf,%lf,%lf,%lf\n",p[loop].x,p[loop].y,p[loop].velx,p[loop].vely,var);
				}
		//printf("\n");
		for(int loop = 0; loop<2; loop+=1)
				{
					r[loop].x=p[loop].x;
					r[loop].y=p[loop].y;
					r[loop].velx=p[loop].velx;
					r[loop].vely=p[loop].vely;
				}


		//printf("%lf %lf\n",r[0].x,r[1].x);
}
//printf("\n");
return r;
}
double adj_del_t(struct R_Vector r1, struct R_Vector r2,double deltat)
{
	double delta[4],deltades[4];
	//printf("\n%lf %lf\n",Rk1(u1, u2, deltat,1) ,Rk1(u1, u2, deltat/2.0,2));
	struct R_Vector *rs,r1s[2],r2s[2];
	rs=RK1(r1, r2,2,2, deltat/2.0);
	for(int var=0;var<2;var++)
		{
			r2s[var].x=rs[var].x;
			r2s[var].y=rs[var].y;
			r2s[var].velx=rs[var].velx;
			r2s[var].vely=rs[var].vely;
		}

	//printf("%d ",RK1(r1, r2,2,2, deltat/2.0));
	rs=RK1(r1, r2,2,1, deltat);
	for(int var=0;var<2;var++)
			{
				r1s[var]=rs[var];
			}

	//printf("%lf ",fabs(r2s[0].x-r1s[0].x));
	if(fabs(r2s[0].x-r1s[0].x)>fabs(r2s[1].x-r1s[1].x)){
		delta[0]=fabs(r2s[0].x-r1s[0].x);
		deltades[0] = EPSILON*(fabs(r1.x)+deltat*fabs(r1.velx));
	}
	else{
		delta[0]=fabs(r2s[1].x-r1s[1].x);
		deltades[0] = EPSILON*(fabs(r2.x)+deltat*fabs(r2.velx));
	}

	if(fabs(r2s[0].y-r1s[0].y)>fabs(r2s[1].y-r1s[1].y)){
		delta[1]=fabs(r2s[0].y-r1s[0].y);
		deltades[1] = EPSILON*(fabs(r1.y)+deltat*fabs(r1.vely));}
	else{
		delta[1]=fabs(r2s[1].y-r1s[1].y);
		deltades[1] = EPSILON*(fabs(r2.y)+deltat*fabs(r2.vely));}

	if(fabs(r2s[0].velx-r1s[0].velx)>fabs(r2s[1].velx-r1s[1].velx)){
		delta[2]=fabs(r2s[0].velx-r1s[0].velx);
	deltades[0] = EPSILON*(fabs(r1.x)+deltat*fabs(r1.velx));}
	else{
		delta[2]=fabs(r2s[1].velx-r1s[1].velx);
		deltades[0] = EPSILON*(fabs(r2.x)+deltat*fabs(r2.velx));}

	if(fabs(r2s[0].vely-r1s[0].vely)>fabs(r2s[1].vely-r1s[1].vely)){
		delta[3]=fabs(r2s[0].vely-r1s[0].vely);
		deltades[1] = EPSILON*(fabs(r1.y)+deltat*fabs(r1.vely));}
	else{
		delta[3]=fabs(r2s[1].vely-r1s[1].vely);
		deltades[1] = EPSILON*(fabs(r2.y)+deltat*fabs(r2.vely));}
	double simgaSmallest=deltades[0]/delta[0];



	for(int var=0;var<4;var++)
	{


		if(simgaSmallest>deltades[var%2]/delta[var]){
		simgaSmallest=deltades[var%2]/delta[var];}
		//printf("%lf ",deltades[var%2]/delta[var]);

	}

	if(simgaSmallest==0.0)
		return deltat;


	//printf("%lf ",simgaSmallest);
	if(simgaSmallest>1)
	{

		return deltat*pow(simgaSmallest,.2);
	}
		return deltat*pow(simgaSmallest,.25);
}
struct R_Vector ** RK(struct R_Vector r[],int size,double timem,double delta)
{

	FILE *f;
		f = fopen("two_body.csv","w");
		fprintf(f,"x,y,velx,vely,time\n");

	double deltat = delta;
	struct R_Vector **xpoints;
	xpoints = malloc(2 * sizeof(struct R_Vector *));
    for(int i = 0; i < 2; i++)
    {
        xpoints[i] = malloc(timem/deltat * sizeof(struct R_Vector));
    }
	struct R_Vector star[size],sstar[size],ssstar[size],p[size];
	for (int var = 0; var < timem/deltat; var+=1) {
		for(int loop = 0; loop<size; loop+=2){

				star[loop].mass= r[loop].mass;
				star[loop+1].mass= r[loop+1].mass;
				sstar[loop].mass= r[loop].mass;
				sstar[loop+1].mass= r[loop+1].mass;
				ssstar[loop].mass= r[loop].mass;
				ssstar[loop+1].mass= r[loop+1].mass;




				//printf("%lf %lf %lf",r[loop+1].vely,function2(r[loop+1],r[loop]).vely,star[loop+1].vely);

				}
		for(int loop = 0; loop<size; loop+=2){

		star[loop].x= r[loop].x+(deltat/2)*function2(r[loop],r[loop+1]).x;
		star[loop].y= r[loop].y+(deltat/2)*function2(r[loop],r[loop+1]).y;
		star[loop].velx= r[loop].velx+(deltat/2)*function2(r[loop],r[loop+1]).velx;
		star[loop].vely= r[loop].vely+(deltat/2)*function2(r[loop],r[loop+1]).vely;
		star[loop+1].x= r[loop+1].x+(deltat/2)*function2(r[loop+1],r[loop]).x;
		star[loop+1].y= r[loop+1].y+(deltat/2)*function2(r[loop+1],r[loop]).y;
		star[loop+1].velx= r[loop+1].velx+((deltat/2)*function2(r[loop+1],r[loop]).velx);
		star[loop+1].vely= r[loop+1].vely+(deltat/2)*function2(r[loop+1],r[loop]).vely;

		//printf("%lf %lf %lf",r[loop+1].vely,function2(r[loop+1],r[loop]).vely,star[loop+1].vely);
		//printf("star %lf %lf %lf %lf\n",star[loop].x,star[loop].y,star[loop].velx,star[loop].vely);

		}


		for(int loop = 0; loop<size; loop+=2)
		{
				sstar[loop].x= r[loop].x+(deltat/2)*function2(star[loop],star[loop+1]).x;
				sstar[loop].y= r[loop].y+(deltat/2)*function2(star[loop],star[loop+1]).y;
				sstar[loop].velx= r[loop].velx+(deltat/2)*function2(star[loop],star[loop+1]).velx;
				sstar[loop].vely= r[loop].vely+(deltat/2)*function2(star[loop],star[loop+1]).vely;
				sstar[loop+1].x= r[loop+1].x+(deltat/2)*function2(star[loop+1],star[loop]).x;
				sstar[loop+1].y= r[loop+1].y+(deltat/2)*function2(star[loop+1],star[loop]).y;
				sstar[loop+1].velx= r[loop+1].velx+((deltat/2)*function2(star[loop+1],star[loop]).velx);
				sstar[loop+1].vely= r[loop+1].vely+(deltat/2)*function2(star[loop+1],star[loop]).vely;
			//	printf("%lf\n",function2(r[loop+1],r[loop]).vely);
				//printf("sstar %lf %lf %lf %lf\n",sstar[loop].x,sstar[loop].y,sstar[loop].velx,sstar[loop].vely);

				}
		for(int loop = 0; loop<size; loop+=2)
				{
						ssstar[loop].x= r[loop].x+deltat*function2(sstar[loop],sstar[loop+1]).x;
						ssstar[loop].y= r[loop].y+deltat*function2(sstar[loop],sstar[loop+1]).y;
						ssstar[loop].velx= r[loop].velx+deltat*function2(sstar[loop],sstar[loop+1]).velx;
						ssstar[loop].vely= r[loop].vely+deltat*function2(sstar[loop],sstar[loop+1]).vely;
						ssstar[loop+1].x= r[loop+1].x+deltat*function2(sstar[loop+1],sstar[loop]).x;
						ssstar[loop+1].y= r[loop+1].y+deltat*function2(sstar[loop+1],sstar[loop]).y;
						ssstar[loop+1].velx= r[loop+1].velx+(deltat*function2(sstar[loop+1],sstar[loop]).velx);
						ssstar[loop+1].vely= r[loop+1].vely+deltat*function2(sstar[loop+1],sstar[loop]).vely;
						//printf("%lf ",ssstar[loop+1].vely);

					//	printf("%lf %lf %lf %lf p ",r[loop+1].x,star[loop+1].x,sstar[loop+1].x,ssstar[loop+1].x);
						//printf("ssstar %lf %lf %lf %lf\n",ssstar[loop].x,ssstar[loop].y,ssstar[loop].velx,ssstar[loop].vely);
						}

		for(int loop = 0; loop<size; loop+=2)
		{
										p[loop].x= r[loop].x+((deltat/6)*(function2(r[loop],r[loop+1]).x+ 2*function2(star[loop],star[loop+1]).x+ 2*function2(sstar[loop],sstar[loop+1]).x+function2(ssstar[loop],ssstar[loop+1]).x));
										p[loop].y= r[loop].y+((deltat/6)*(function2(r[loop],r[loop+1]).y+ 2*function2(star[loop],star[loop+1]).y+ 2*function2(sstar[loop],sstar[loop+1]).y+function2(ssstar[loop],ssstar[loop+1]).y));
										p[loop].velx= r[loop].velx+((deltat/6)*(function2(r[loop],r[loop+1]).velx+ 2*function2(star[loop],star[loop+1]).velx+ 2*function2(sstar[loop],sstar[loop+1]).velx+function2(ssstar[loop],ssstar[loop+1]).velx));
										p[loop].vely= r[loop].vely+((deltat/6)*(function2(r[loop],r[loop+1]).vely+ 2*function2(star[loop],star[loop+1]).vely+ 2*function2(sstar[loop],sstar[loop+1]).vely+function2(ssstar[loop],ssstar[loop+1]).vely));
										p[loop+1].x= r[loop+1].x+((deltat/6)*(function2(r[loop+1],r[loop]).x+ 2*function2(star[loop+1],star[loop]).x+ 2*function2(sstar[loop+1],sstar[loop]).x+function2(ssstar[loop+1],ssstar[loop]).x));
										p[loop+1].y= r[loop+1].y+((deltat/6)*(function2(r[loop+1],r[loop]).y+ 2*function2(star[loop+1],star[loop]).y+ 2*function2(sstar[loop+1],sstar[loop]).y+function2(ssstar[loop+1],ssstar[loop]).y));
										p[loop+1].velx= r[loop+1].velx+((deltat/6)*(function2(r[loop+1],r[loop]).velx+ 2*function2(star[loop+1],star[loop]).velx+ 2*function2(sstar[loop+1],sstar[loop]).velx+function2(ssstar[loop+1],ssstar[loop]).velx));
										p[loop+1].vely= r[loop+1].vely+((deltat/6)*(function2(r[loop+1],r[loop]).vely+ 2*function2(star[loop+1],star[loop]).vely+ 2*function2(sstar[loop+1],sstar[loop]).vely+function2(ssstar[loop+1],ssstar[loop]).vely));

		}
		for(int loop = 0; loop<size; loop+=1)
				{
										//printf("%lf,%lf,%lf,%lf,%lf\n",r[loop].x,r[loop].y,r[loop].velx,r[loop].vely,var);
				}
		//printf("\n");
		deltat=adj_del_t(r[0], r[1], deltat);
		printf("%lf ",deltat);
		for(int loop = 0; loop<size; loop+=1)
				{
					r[loop].x=p[loop].x;
					r[loop].y=p[loop].y;

					r[loop].velx=p[loop].velx;
					r[loop].vely=p[loop].vely;
					fprintf(f,"%lf,%lf,%lf,%lf,%lf\n",r[loop].x,r[loop].y,r[loop].velx,r[loop].vely,var);


				}





}
	fclose(f);
return xpoints;
}
int main()
{
	int size=2;

	//printf("%.20lf ",G);
	double deltat=10,timem=60*36000;

	struct R_Vector r[size];
	r[0].x=0;r[0].y=0;
	r[0].velx=0;
	r[0].vely=0;
	r[1].x=1.9889*pow(10,8);
	r[1].y=-1.651*pow(10,9);
	r[1].velx= 79348.8;
	r[1].vely=9078.256;
	r[0].mass = .08 * 1.989*pow(10,30);
	r[1].mass = .85 * 5.9722*pow(10,24);
	//printf("%f",r[1].x);
	struct R_Vector ** rk = RK(r, size, timem,deltat);




	return 1;
}*/
