#include <stdio.h>

int main()
{	
	int dizi[3][4] = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12} };
	int *p;	//pointer tanimlandi
	p = &dizi[0][0];	//pointer dizinin ilk elemanini gösterdi
	int i , j, secim_i , secim_j , member , control=1;	//degiskenler tanimlandý
	
	printf( ".....3x4'luk dizimiz......\n" );
	printf( "--------------------------\n" );
	
	for ( i = 1 ; i <= 12 ; i++ )	//matrisin ilk halini yazdiracak olan dongu
	{
		printf( "%d\t" , *( p + ( i - 1 ) ) );	//matrisin elemanlarini teker teker yazdirir
		if( i % 4 == 0 ) printf("\n");	//matrisin satir ve sutun galinde gözükmesi için
	}
	
	while (control==1)	//Hatali girisler icin kontrol yapan dongu
	{
		printf("\nLutfen sileceginiz indisin i(satir) ve j(sutun) degerlerini giriniz\n");
		
		printf( "i= " );								
		scanf( "%d" , &secim_i );	//silenecek olan indisin satir degeri girdisi		
		
		printf( "j= " );
		scanf( "%d" , &secim_j );	//silenecek olan indisin sutun degeri girdisi		
		
		printf( "\n" );
		
		if( secim_i < 4 && secim_j < 5 )
		{
			member = ( (secim_i-1) * 4 ) + secim_j;	//silenecek olan indisin matristeki kacinci eleman oldugunu buluyor
			
			printf( ".......Yeni dizimiz.......\n" );
			printf( "--------------------------\n" );
			for ( i = 1 ; i < member ; i++ )	//silinecek olan indise kadar matrisin yazdirilmasi icin gereken dongu
			{
				printf( "%d\t" , *( p + ( i - 1 ) ) );	//matrisin elemanlarini silenecek olan indise kadar yazdirir
				if( i % 4 == 0 ) printf( "\n" );	//matrisin satir ve sutun galinde gözükmesi için
			}					
				
				
			for ( i ; i <= 12 ; i++ )	//silinen indisten sonraki indizlerin yazdirilmasi icin gereken dongu
			{
				printf("%d\t",*( p + i ));	//silinen indisten sonraki elemani yazdirir ve son elemana '0' degerini atar
				if( i % 4 == 0 ) printf( "\n" );	//matrisin satir ve sutun galinde gözükmesi için
			}
				
			control=0;	//Eger tanimlanan aralikta girdi yapilirsa donguden cikarmasi icin
		}
			
		else
		{
			printf( "Hatali giris yaptiniz, Lutfen tekrar deneyiniz!" );
			printf( "\n" );
			control=1;	//Eger tanimlanan aralikta girdi yapilmazsa tekrar donguye girilmesi icin
		}
	}
	
	return 0;	
}
