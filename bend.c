/*#include <stdio.h>
#include <math.h>
int main(){
	double low=0,high=1,error=100.0,answer,fresult;
	while (error > .0000001)
	{
		answer= (low+high)/2;
		fresult=exp(-answer)-answer;
		if(fresult*(exp(-low)-low)<0)
		{
			high=answer;
		}
		else
		{
			low=answer;
		}
		error= fabs((((double)low-(double)high)/((double)low+(double)high)))*100.0;
		//printf("%lf %lf ",high,low);
	}
	printf("%lf",answer);

}

*/
