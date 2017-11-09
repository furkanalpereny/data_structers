/*A�a��da verilen ba�l� liste �rne�ini dikkatlice inceleyiniz. Bu programa 

a) Ba�l� listedeki eleman say�s�n� veren eleman_say() fonksiyonunu++++++++++

b) Ba�l� listedeki elemanlar�n toplam�n�  veren liste_toplam() fonksiyonunu+++++++++++

c) Ba�l� listedeki elemanlar�n aritmetik ortalamas�n�  veren ortalama() fonksiyonunu yaz�n�z.  */

#include <stdio.h>
#include <stdlib.h>

struct node {
int data;

struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;












	//ODEV KODLARI (FURKAN ALPEREN YILDIRIM 163301014)


	//elemanlarin aritmetik ortalamasini alan fonksiyon
	double ortalama(){
		return liste_toplam()/eleman_say();
	}

	//Listedeki elemanlari toplar
	int liste_toplam(){
		int toplam=0;
		struct node *ptr = head;
		while(ptr != NULL) {
			toplam+=ptr->data; 
			ptr = ptr->next;
		}
		return toplam;
	}
	
	//eleman say
	int eleman_say() {
		int sayac=0;
		struct node *ptr = head;
		while(ptr != NULL) { 
			ptr = ptr->next;
			sayac++;
		}
		return sayac;
	}
















	//listeyi g�ster
	void ListeyiGoster() {
	
		struct node *ptr = head;
		
		printf("\n[baslama] =>");
		
		//bastan baslayarak goster
		while(ptr != NULL) { 
			printf(" %d =>",ptr->data);
			ptr = ptr->next;
		}
		
		printf(" [null]\n");
	}

	

	//Bagli Liste olustur
	void ekle(int data) {
	// yeni dugum icin haf�zada yer ay�r;
		struct node *link = (struct node*) malloc(sizeof(struct node));
	
		link->data = data;
		link->next = NULL;
		
		// eger baslang�c pointer null ise , yeni bir liste olustur
		if(head==NULL) {
			head = link;
			return;
		}
		
		// dolasma icin olusturdugumuz pointer
		current = head;
		
		// current pointerini listenin sonuna getir
		while(current->next!=NULL)
			current = current->next;
		
		// listenin sonuna yeni eleman� ekle
		current->next = link; 
}

	// ekleme islemini� lsitenin basina yapal�m
	void basa_ekle(int data) {
		//bir d���m� haf�zada olu�tur
		struct node *link = (struct node*) malloc(sizeof(struct node));
		
		//gelen veriyi d���me ekleyelim
		link->data = data;
		
		//pointeri eski ilk dugume yonlendirelim 
		link->next = head;
		
		//baslang�c pointeri yeni dugumu gostersin
		head = link;
	}


	//listeyi ters s�rada goster
	void ListeyiGoster_ters(struct node *list) {
		if(list == NULL) {
			printf("[null] => ");
			return;
		}
		ListeyiGoster_ters(list->next);
		printf(" %d =>",list->data);
	
	}

	void arama(int item) {
		int pos = 0;
		
		if(head==NULL) {
			printf("Bagli liste mevcut degil");
			return;
		}
		
		current = head;
		while(current->next!=NULL) {
			if(current->data == item) {
				printf("%d verisinin listede bulundugu pozisyon %d\n", item, pos);
				return;
			}
			current = current->next;
			pos++;
		}
		printf("%d verisi listede mevcut degil", item);
	}


	void veri_sil(int data) {
		int pos = 0;
		
		if(head==NULL) {
			printf("Bagli liste mevcut degil");
			return;
		} 
		
		if(head->data == data) {
			if(head->next != NULL) {
				head = head->next;
				return;
			}else {
				head = NULL;
				printf("Liste bos");
				return;
			}
		}
		else if(head->data != data && head->next == NULL) {
			printf("%d verisi listede bulundu\n", data);
			return;
		}
		
		
		
		// prev = head;
		current = head;
		
		while(current->next != NULL && current->data != data) {
			prev = current;
			current = current->next;
		}
		
		if(current->data == data) {
			prev->next = prev->next->next;
			free(current);
		}else
			printf("%d verisi listede bulunamad�.", data);
	
	}

	int main() {
		// listeye yeni elemenalar ekleyelim
		ekle(10);
		ekle(20);
		ekle(30);
		ekle(1);
		ekle(40);
		ekle(56); 
		
		// listedeki elemanlar� yazd�ral�m
		printf("\nYeni elemanlar listeleniyor");
		ListeyiGoster();
		
		//Basa Ekleme Yapal�m
		basa_ekle(4);
		
		// listedeki elemanlar� yazd�ral�m
		printf("\nListe basina eklemeden sonraki liste gorunumu");
		ListeyiGoster();
		
		// listedeki elemanlar� tersden yazd�ral�m
		printf("\nListenin tersten gorunumu");
		ListeyiGoster_ters(head);
		
		// arama islemi yapal�m
		arama(10); // mevcut veri arama
		arama(99); //mevcut olmayan veriyi arama
		printf("\nSilme islemi oncesi listeyi goruntule");
		ListeyiGoster();
		veri_sil(20);
		printf("\nSilme islemi sonrasi listeyi goruntule");
		ListeyiGoster();
		
		
		
		
		
		
		
		//ka� eleman oldugunu basar
		printf("\n%d kadar eleman var.",eleman_say());
		
		//Listedeki elemanlari toplar
		printf("\nListedeki elemanlarin toplami= %d",liste_toplam());
		
		//Listedeki elemanlari toplar
		printf("\nListedeki elemanlarin aritmetik ortalamasi= %f",ortalama());
		
		
		
		
		
		
		
		return 0;
		
	}
