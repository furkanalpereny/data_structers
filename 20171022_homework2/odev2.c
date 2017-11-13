#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//Furkan Alperen Yildirim 21/10/2017 
//163301014


	/*------------------------------------------------------------------------------------------*/	
	int puan ( int x, int y , int z)
	{
	
	int islem1 	= ( 10 * x );
	int islem2 	= ( 5 * y );
	int islem3 	= ( ( 1 / z ) * 1000 );
	int islem4 	= ( ( x * y ) / ( x + y ) );
	int sonuc 	= islem1 + islem2 + islem3 - islem4;
	return sonuc;
	
	} 
	/*------------------------------------------------------------------------------------------*/




int main(){
	struct uyeler{
		char isim[20];
		int skor;
	};

	struct uyeler uye[10]; 
	
	int i,j;
	
	
	
	
	
	srand(time(NULL));
	
	
	int random;
	int *rand_bas;
	int rand_basamak[4];
	rand_bas=&rand_basamak[0];
	int control=1;
	int gecici,gecici2;	

	
	/*-------------------------------------------------------------------------------------*/	
		//rakamlari birbirinden farkli sayi uretme dongusu
		while( control == 1 )
		{	
			//1000-9999 arasi rastgele sayi uretme
			random = rand()%9000+1000;
			//sayilari basamaklarina ayirma islemi
			*(rand_bas+0) = random / 1000;
			gecici = random - ( *(rand_bas+0) * 1000 );
			
			*(rand_bas+1) = gecici / 100;
			gecici2 = gecici - ( *(rand_bas+1) * 100 );
			
			*(rand_bas+2) = gecici2 / 10;
			*(rand_bas+3) = gecici2 - ( *(rand_bas+2) * 10 );
			
			//rakamlarin birbirine esit olup olmadigini kontrol ediyor
			if( *(rand_bas+0) == *(rand_bas+1)	||
				*(rand_bas+0) == *(rand_bas+2)	||
				*(rand_bas+0) == *(rand_bas+3)	||
				*(rand_bas+1) == *(rand_bas+2)	||
				*(rand_bas+1) == *(rand_bas+3)	||
				*(rand_bas+2) == *(rand_bas+3)	)
			{
				control = 1; //eger birbirine esit rakamlar varsa donguyu basa alilyor		
			}	
		
			else
			{		
				control = 0; //eger birbirine esit rakamlar yoksa donguden cikiyor
			}
				
		}
		/*-----------------------------------------------------------------------------------*/	
		
		
	printf("sayi: %d\n",random);
	
		
	
	int girilen_sayi;
	
	int *gir_bas;
	int girilen_basamak[4];
	gir_bas=&girilen_basamak[0];
	
	int hak=0;
	
	
	
	int eksi;
	
	int dogru_yerde=0 , rakam_var=0 , dogru_sayac=0 , eksi_sayac=0;
	
	while (hak<10)
		{	
			hak++; //donguye her girdiginde kullanilan hakki artiriyor
			
			printf( "%d. tahmininiz nedir? : " , hak );
			scanf( "%d" , &girilen_sayi ); //tahmin girdisi
			
			if ( girilen_sayi > 999 && girilen_sayi < 10000 ) //girilen formatin dogrulugunu kontrol ediyor
			{
				//sayilari basamaklarina ayirma islemi
				*(gir_bas+0) = girilen_sayi / 1000;
				gecici = girilen_sayi - ( *(gir_bas+0) * 1000 );
				
				*(gir_bas+1) = gecici / 100;
				gecici2 = gecici - ( *(gir_bas+1) * 100 );
				
				*(gir_bas+2) = gecici2 / 10;
				*(gir_bas+3) = gecici2 - ( *(gir_bas+2) * 10 );
				
				if( *(gir_bas+0) == *(gir_bas+1)	||
					*(gir_bas+0) == *(gir_bas+2)	||
					*(gir_bas+0) == *(gir_bas+3)	||
					*(gir_bas+1) == *(gir_bas+2)	||
					*(gir_bas+1) == *(gir_bas+3)	||
					*(gir_bas+2) == *(gir_bas+3)	)
				{
					eksi = -4; //yanlis format girildiginde minimum puani veriyor
					printf( "Format disi giris yaptiniz!\n" );	
				}	
			
				else
				{		
					//uretilen sayi ile girilen sayinin rakamlarinin karsilastirilmasi
					for (i=0;i<4;i++)
					{
						//girilen rakamlardan kac tanesi dogru yerde kontrolu	
						if ( *(rand_bas+i) == *(gir_bas+i) )
						{
							dogru_yerde++;
						}
								
						for (j=0;j<4;j++)
						{
							//girilen rakamlardan kac tanesi var kontrolu
							if ( *(rand_bas+i) == *(gir_bas+j) )
							{
								rakam_var++;
							}
						}	
					}
					
					eksi = dogru_yerde - rakam_var; //girilen andaki eksi puani tekrar tanimladi
					dogru_sayac += dogru_yerde;	//arti toplayip, sakliyor
					
				}
				
						
			}
			
			else
			{	
				eksi = -4; //yanlis format girildiginde minimum puani veriyor
				printf( "Format disi giris yaptiniz!\n" );
			}
			
			printf( "%d, +%d\tgirilenlerden %d tane var; %d tanesi dogru yerde, %d tanesi yanlis yerde\n\n" , eksi , dogru_yerde , rakam_var , dogru_yerde, ( (-1) * eksi ) ); //durum ciktisi
			
			dogru_yerde = 0; //girilen andaki degeri vermesi icin deger sifirlaniyor
			rakam_var = 0; //girilen andaki degeri vermesi icin deger sifirlaniyor
			
			eksi_sayac += eksi; //eksileri toplayip, sakliyor
			
			if( random == girilen_sayi ) break; //eger sayi bulunmussa donguden cikar
			
		}
		
		
				
	
				int score = puan( dogru_sayac , eksi_sayac , hak );
		
				if( random == girilen_sayi ) 
				{
					printf( "Tebrikler! %d. seferde bildiniz!\n" , hak );
					printf( "Puaniniz: %d" , score );		
				}
				
				
				else 
				{
					printf( "Hakkiniz bitti\n" );
					printf( "Puaniniz: %d" , score ) ;	
				}
	
	
	
	return 0;
}
