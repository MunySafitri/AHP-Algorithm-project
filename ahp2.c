#include "system.h"
#include "muny.h"
#include "matriks.h"
int main(){
	int pilih;
	bingkai();
	while(1){
		bersih_tampilan_main();
		bersih_tampilan();
		gotoxy(2,8);printf("1. Sign in");
		gotoxy(2,10);printf("2. Login");
		gotoxy(2,12);printf("3. Keluar");
		gotoxy(2,14);printf("Masukkan pilihan anda : ");scanf("%d",&pilih);
		switch(pilih){
			case 1 : signIn(); break;
			case 2 : login(); break;
			case 3 : exit(0); break;
			default: break;		
		}
		
	}
	
	gotoxy(0,70);
}
	

