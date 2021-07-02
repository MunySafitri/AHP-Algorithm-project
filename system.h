#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include "muny.h"
#include "matriks.h"


void signIn(){
	bersih_tampilan();
   char login[50] = "login/";
   int x= 37;
   fflush(stdin);
   gotoxy(x,8);printf("Masukkan nama anda :"); scanf(" %[^\n]s",logins.id);
   gotoxy(x,10);printf("Masukkan pass :");scanf(" %[^\n]s",logins.pass);
   strcat(logins.id,logins.pass);
   strcat(logins.id,".txt");
     
   strcat(login,logins.id);
   FILE *file =fopen(login,"wb+");
   if(file == NULL){
   		char mkdir[50]= "mkdir ";
   		strcat(mkdir,"login");
		system(mkdir);
		FILE *file =fopen(login,"wb+");
   }
   fwrite(&logins,sizeof(login),1,file);	
   fclose(file);
} 
void login(){
	bersih_tampilan();
	int x=37;
	char login[50] = "login/";
	fflush(stdin);
    gotoxy(x,8);printf("Masukkan nama anda :"); scanf(" %[^\n]s",logins2.id);
    fflush(stdin);
    //("");
	gotoxy(x,12);printf("Password disembunyikan ^^");
	 gotoxy(x,13);printf("Masukkan pass :");
    
    
	char ch;
    int i =0;
    while((ch = (char) _getch()) != '\r'){
        logins2.pass[i] = ch;
        i++;
    }
    printf("\n");
	
    strcat(logins2.id,logins2.pass);
    strcat(login,logins2.id);
    strcat(login,".txt");
    FILE *file =fopen(login,"ab+");
    if(file == NULL){
    	gotoxy(x,13);printf("Maaf Anda Belum mendaftar Akun,");
		gotoxy(x,14);printf("Sign in terlebih Dahulu");
    	return;
	}else{
		while(fread(&logins,sizeof(logins),1,file)==1);
			strcat(logins2.id,".txt");
			if (strcmp(logins.id,logins2.id)==0){
				gotoxy(x,19);printf("Selamat Datang! ^w^");
				hitung();
			
			}else{
				gotoxy(x,13);printf("Maaf Anda Belum mendaftar Akun,");
				gotoxy(x,14);printf("Sign in terlebih Dahulu");
			}
	}
	return;
}

int matriks(int jumlah){
	do{	
		bersih_tampilan_main();
        gotoxy(2,8);printf("(Min 3 dengan Maks 15 kriteria)");
		gotoxy(2,10);printf("Berapa kriteria yang ingin anda ");
		gotoxy(2,11);printf("bandingkan =>");
        scanf("%d",&jumlah);
        if(jumlah < 3 ) {
            gotoxy(2,12);printf("Minimal harus 3");
            Enter();
        }else if(jumlah >15){
            gotoxy(2,12);printf("Maksimal harus 15");
            Enter();
        }
		//gotoxy(2,6);printf("%d",jumlah);
    }while(jumlah<3 || jumlah >15);
    
    return jumlah;
}


void menu(){
	bersih_tampilan_main();
	gotoxy(2,8);printf("menambah subjek");
}
#endif
