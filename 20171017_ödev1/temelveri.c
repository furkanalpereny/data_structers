#include <stdio.h>

int main()
{
	int array_1[4] = { 1 , 2 , 3 , 4 };	//dizilerin tanimlanmasi
	int array_2[4] = { 5 , 6 , 7 , 8 };	//dizilerin tanimlanmasi
	int array_3[8]; //dizilerin tanimlanmasi
	int a = 0; //ileride kullanilmasi icin sayac tanimi
	int i;	//donguler icin sayac
	
	int *p1;	//pointer tanimlanmasi
	p1 = &array_1[0];	//pointerin, dizinin ilk elemanina atanmasi
	
	int *p2;	//pointer tanimlanmasi
	p2 = &array_2[0];	//pointerin, dizinin ilk elemanina atanmasi

	int *p3;	//pointer tanimlanmasi
	p3 = &array_3[0];	//pointerin, dizinin ilk elemanina atanmasi
		
	printf( "Ilk array\n" );
	for ( i = 0 ; i < 4 ; i++ )
	{
		printf( "%d\t" , *( p1 + i) );	//tanimlanan ilk arrayin bastirilmasi
	}
	printf( "\n\n" );
	
	printf( "Ikinci array\n" );
	for ( i = 0 ; i < 4 ; i++ )
	{
		printf( "%d\t" , *( p2 + i ) );	//tanimlanan ikinci arrayin bastirilmasi
	}
	printf("\n\n");
	
	for( i = 0 ; i < 4 ; i++ )	
	{
		*( p3 + ( 2 * (i) ) ) = * ( p1 + a );	//birlestirilmis arrayin cift sayili indislerine ilk arrayin elemanlarinin atanmasi
		a++;
	}
	
	a = 0; 
	
	for( i = 0 ; i < 4 ; i++ )
	{
		*( p3 + ( 2 * (i) + 1 ) ) = *( p2 + a );	//birlestirilmis arrayin tek sayili indislerine ilk arrayin elemanlarinin atanmasi
		
		a++;
	}
	
	printf( "Birlestirilmis array\n" );
	for( i = 0 ; i < 8 ; i++ )
	{
		printf( "%d\t" , *( p3 + i ) );	//birlestirilmis arrayin indislerinin basilmasý
	}
	
	return 0;
	
}
