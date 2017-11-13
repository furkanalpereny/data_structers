#include<stdio.h>

int main()
{
	int x ,i , sonuc = 1;
	int *p;
	p = &x;
	int *p2;
	p2 = &sonuc;
	int *pi;
	pi = &i;
	
	printf( "Faktoriyelini almak istediginiz sayi: " );
	scanf( "%d" , p );
	
	for( (*pi) = 1 ; (*pi) <= (*p) ; (*pi)++ )
	{
		(*p2) *= (*pi) ;
	}
	
	printf( "%d" , *p2 );
}
