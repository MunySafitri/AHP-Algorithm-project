#ifndef MUNY_H_INCLUDED
#define MUNY_H_INCLUDED

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

#define maks 15 

struct datas{
    double total;
    float criteria[maks][maks];
    float tot_criteria[maks];
    float des_tot_criteria[maks][maks];
    char nama_criteria[100][maks];
    double weight[maks];
    double wsm[maks];
    double average;
    double cv[maks];
    double cl;
    double cr;
    float saw[maks];
};
struct datas kriteria;

struct data{
	char id[30];
	char pass[30];
};
struct data logins;
struct data logins2;

void gotoxy(int x,int y);
void Enter();
void bersih_tampilan();
void bingkai();
void hitung();
void jmlh_Matriks(int jumlah);
int matriks(int jumlah);

void Enter(){
    getchar();
    getchar();
}

void gotoxy(int x,int y){
	COORD coord;
	coord.X = x; coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void bersih_tampilan(){
	int y,z;
	for( y=36;y<78;y++){
		for(z=7;z<25;z++){
			gotoxy(y,z);
			printf(" ");
		}
	}
	//gotoxy(26,7);
}
void bersih_tampilan_main(){
	int y,z;
	for( y=1;y<35;y++){
		for(z=7;z<25;z++){
			gotoxy(y,z);
			printf(" ");
		}
	}
	//gotoxy(26,7);
}
void bingkai(){
	int i,j;
	gotoxy(0,0);
	printf("%c",201);
	for (i=1; i<78; i++){
		gotoxy(i,0);
		printf("%c",205);
	}
	gotoxy(78,0);
	printf("%c",187);
	for(i=1;i<25;i++){
		gotoxy(78,i);
		if (i == 6){
			printf("%c",185);
		}else{
			printf("%c",186);
		}
	}
	gotoxy(78,25);
	printf("%c",188);
	for(i=1;i<78 ;i++){
		gotoxy (i,25);
		if (i == 35){
			printf("%c",202);
		}else{
			printf("%c",205);
		}
	}
	gotoxy (0,25);
	printf("%c",200);
	for(i=1;i<78;i++){
		gotoxy(i,6);
		if(i==35){
			printf("%c",203);
		}else{
			printf("%c",205);
		}
	}
	gotoxy(0,25);
	for(i=24;i>0;i--){
		gotoxy(0,i);
		if(i==6){
			printf("%c",204);
		}else{
			printf("%c",186);
		}
	}
	for(i=7; i<25; i++){
		gotoxy(35,i);
		printf("%c",186);
    }
    gotoxy(30,2);
    printf("====PROGRAM AHP====");
	gotoxy(28,4);
	printf("UNIVERSITAS SYIAH KUALA");	
}
#endif
