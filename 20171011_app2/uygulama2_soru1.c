#include <stdio.h>

int function (int x)
{	
	if( x <= 0 )
	{
		return 0;
	}
	
	return x + function( x - 2 );
	
}

int main()
{
	int x;
	int *p;
	p = &x;
	
	printf( "a(n) = 2+4+6+8+10+....+2n\n" );
	printf( "a(n); n=" );
	
	scanf("%d",p);
	printf( "a(n)=%d" , function( (*p) *= 2 ) );
	
}
