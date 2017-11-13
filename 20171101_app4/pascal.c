#include <stdio.h>
#include <time.h>
long hesap(int y)
{
    int z;
    long sonuc = 1;
 
    for( z = 1 ; z <= y ; z++ )
        sonuc = sonuc*z;
 
    return sonuc;
}
int main()
{
    int x, y, z,s,a;
    clock_t basla,dur;
	basla=clock();
	
	
    
    printf("Satir: ");
    scanf("%d",&y);
   	a=y+1;
    int dizi[a][a];
    for ( x = 0 ; x < a ; x++ )
    {
        
        for( z = 0 ; z <= x ; z++ )
            dizi[x][z] = hesap(x)/(hesap(z)*hesap(x-z));
 
       
    }
    
    printf("Satir: ");
    scanf("%d",&s);
    
    printf("%d. satirin %d. pozisyonunun degeri : %d\n",y,s,dizi[y][s]);
    
  	dur=clock();
	double fark = (double)(dur - basla) / CLOCKS_PER_SEC;
	printf("sayac = %f\n",fark);
    
    
    return 0;
}
