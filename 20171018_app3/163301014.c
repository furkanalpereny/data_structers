#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//Furkan Alperen Yildirim 18/10/2017 
//163301014

int main(){
	
    int buyuk=0;
    int kucuk;
    int i=0;
    int n;
    
    printf("n= ");
    scanf("%d",&n);
    int dizi[n];
    
	srand(time(NULL));
	
    for(i;i<n;i++)
	{  	
	    dizi[i]=rand();
	    printf("Dizinin %d. elemani : %d\n",(i+1),dizi[i]);
	
	}
	
	kucuk = dizi[0];
	for(i=0;i<n;i++)//buyuk-kucuk buluyor
	{
		if(dizi[i]>=buyuk)
		{
	    	buyuk = dizi[i];
		}
		
		if(kucuk > dizi[i])
		{
			kucuk = dizi[i];
		}	
	}
	
	printf("En buyuk sayi= %d\n", buyuk);
	printf("En kucuk sayi= %d\n", kucuk);
	
	printf("Fark= %d",buyuk-kucuk);	
		
    getch();
}
