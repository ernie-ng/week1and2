#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//create a function to do cubic
double cubic(double x, double c3, double c2, double c1, double c0)
{
	//double t1,t2,t3,y;
	//t3 = c3 * pow(x,3);
	//t2 = c2 * x * x;
	//t1 = c1 * x;
	//y = t3 + t2 + t1 + c0;
	//condense:

	return c3 * pow(x,3) + c2 * x * x + c1 * x + c0;
}

double quadratic(double x, double c2, double c1, double c0)
{
	return c2 * x * x + c1 * x + c0;
}

//create a function that takes any number of polynomials
double polynomial(double x, int p, double* c)
{
	double y = c[0];
	for(int i=1; i<=p;i++)
	{
		y += c[i]*pow(x,i);
	}

	return y;
}

//create a poylnomial differentiating funtion
void Dpolynomial(double* c, double* diff_c, int p)
{

	for(int i = 1; i<=p; i++)
	{
		diff_c[i-1] = i * c[i];
		printf("%g\n", diff_c[i-1]);
	}
	
}

double newton_raphson(int p, double* c, double tolerance, double x)
{
	//double x = x0;
	double Dc[p-1];
	double F, dF, delta;
	int n=0;
	Dpolynomial(c, Dc, p);
	do
	{
	  //F = 2.0 * pow(x,3) + x - 3.0;
	  //F = cubic(x,2.0,0,1.0,-3.0);
	  F = polynomial(x,p,c);
	  //dF = 6.0 * x * x + 1.0;
	  //dF = quadratic(x,6.0,0,1.0);
	  dF = polynomial(x,p-1,Dc);


	  delta = -F/dF;


	  x = x + delta;
	  //printf("\n%d: x=%g delta=%g",n,x,delta);
	  n++;
	}
	while(fabs(delta) > tolerance);

	return x;
}

//exercise on finding root of 2x^3+x-3
int main(int argc, char const *argv[])
{
	//double x = 0;
	//double tolerance = 1e-9;
	//double F, dF, delta;
	//int n=0, p=3;
	double coeff1[4] = {-3.0,1.0,0,2.0};
	//double coeff2[3]={1.0,0,6.0};
	//double coeff2[3];
	//Dpolynomial(coeff1,coeff2,3);

	
	double x = newton_raphson(3, coeff1, 1e-9, 0);
	printf("\nRoot = %g\n", x);

    

	return 0;
}