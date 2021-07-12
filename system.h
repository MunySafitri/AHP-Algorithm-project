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
   char tumbal[30];
   
   strcpy(tumbal,logins.id);
   strcpy(logins2.direk,logins.id);
   gotoxy(x,16);printf("loginsdirek : %s",logins.direk);
   strcat(tumbal,".txt");
   strcat(login,tumbal);
   gotoxy(x,12);printf("%s",login);
   //FILE *file =fopen(login,"wb+");
   FILE *file =fopen(login,"r");
   if(file == NULL){
   		char mkdir2[50]= "mkdir ";
   		strcat(mkdir2,logins.pass);//sementara
   		system(mkdir2);
   		if(fopen(login,"wb+") == NULL){   
	   		char mkdir[50]= "mkdir ";
	   		strcat(mkdir,"login");
			system(mkdir);
			gotoxy(x,13);printf("MKDIR2: %s",mkdir2);
			//FILE *file =fopen(login,"wb+");
		}
   }else{
   		gotoxy(x,15);printf("Akun ini sudah terpakai");
   		MessageBeep(0);
   		Enter();
   		return;
   }
   file =fopen(login,"ab+");
   strcpy(logins.id,tumbal);
   gotoxy(x,14);printf("%s",logins.id);
  // gotoxy(x,17);printf("%s",logins.direk);
   Enter();
   fwrite(&logins,sizeof(login),1,file);
   //fwrite(&logins2,sizeof(login),1,file);	
   fclose(file);
} 
void login(){
	bersih_tampilan();
	int x=37;
	char login[50] = "login/";
	fflush(stdin);
    gotoxy(x,8);printf("Masukkan nama anda :"); scanf(" %[^\n]s",logins2.id);
    fflush(stdin);
	gotoxy(x,12);printf("Password disembunyikan ^^");
	gotoxy(x,13);printf("Masukkan pass :");
    
    //fflush(logins2.pass);
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
		Enter();
		MessageBeep(0);
    	return;
	}else{
		while(fread(&logins,sizeof(logins),1,file)==1);
		//while(fread(&logins2,sizeof(logins2),1,file)==1);
			strcat(logins2.id,".txt");
			gotoxy(x,12);printf("%s:%s",logins.id,logins2.id);
			Enter();
			if (strcmp(logins.id,logins2.id)==0){
				gotoxy(x,19);printf("Selamat Datang! ^w^");
				hitung();
				return;
			
			}else{
				gotoxy(x,13);printf("Maaf Anda Belum mendaftar Akun,");
				gotoxy(x,14);printf("Sign in terlebih Dahulu");
				MessageBeep(0);
				Enter();
			}
	}
	return;
}
int MenuPertama(int Pilihans){
		bersih_tampilan_main();
        gotoxy(2,8);printf("1. Membuat Data baru");
		gotoxy(2,10);printf("2. Data telah ada sebelumnya");
		gotoxy(2,12);printf("3. Keluar");
		gotoxy(2,14);printf("Masukkan pilihan anda: ");
		scanf("%d",&Pilihans);
		if(Pilihans == 3 ) return 3;
		
		return Pilihans;
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


int MainKedua(int Pilihans){
		do{
			bersih_tampilan_main();
			gotoxy(2,8);printf("1. Menambah subjek");
			gotoxy(2,10);printf("2. Menghapus subjek");
			gotoxy(2,12);printf("3. Menampilkan tabel bobot");
			gotoxy(2,14);printf("4. Kembali");
			gotoxy(2,16);printf("Masukan pilihan anda: ");	
			scanf("%i",&Pilihans);
		}while(Pilihans < 1 || Pilihans > 4);
		//if (Pilihans == 4) return EXIT_FAILURE;
	
	return Pilihans;	
	
}
#endif
