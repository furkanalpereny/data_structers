#include <stdio.h>

//FURKAN ALPEREN YILDIRIM 163301014


int main(){
	
	
	int satir, sutun1, sutun2, toplam = 0;
	int A[5][3],B[3][6],Sonuc[5][6]={0},i,j,k;
	
	srand(time(NULL));
	int *ptr_a, *ptr_b, *ptr_s;
	ptr_a=&A;
	ptr_b=&B;
	ptr_s=&Sonuc;
	
	//T(n)=n^2
	for (i=0;i<=5;i++){
		for (j=0;j<=5;j++){
			*(ptr_a+i+j)=rand()%10;
			*(ptr_b+i+j)=rand()%10;
		}
	}
	
	
	//T(n)=n^2
	printf("1.Matris...\n\n");
	for(i=0;i<=4;i++){
		for(j=0;j<=2;j++){
			printf("%d\t",*(ptr_a+i+j));
		}
		printf("\n");
	}
	
	printf("\n");
	
	//T(n)=n^2
	printf("2.Matris...\n\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=5;j++){
			printf("%d\t",*(ptr_b+i+j));
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	
	printf("Matrislerin Carpimi...\n\n");
	
	//T(n)=n^3
    for(i=0; i<5; i++){  
        for(j=0; j<6; j++){
            for(k=0; k<3; k++){
                toplam += *(ptr_a+i+k) * *(ptr_b+k+j);
            }
            *(ptr_s+i+j) = toplam;
            toplam = 0;
            printf("%d\t", *(ptr_s+i+j));
        }
        printf("\n");
	}
	
	
	////T(n) = n^2 + n^2 + n^2 + + n^3 = *****n^3*****
	
	//T(n)=n^3
	
	return 0;
}
