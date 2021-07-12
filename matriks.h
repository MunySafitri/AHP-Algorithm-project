#ifndef MATRIKS_H_INCLUDED
#define MATRIKS_H_INCLUDED
#include "muny.h"
#include "system.h"

void hitung(){
	
	int jumlah;
	int Jumlah;
	int pilihan;
	menu:
	Jumlah=MenuPertama(jumlah);
	gotoxy(2,16);printf("%d",Jumlah);
	//Enter();
	if(Jumlah ==1){
		pilihan =matriks(jumlah);
		jmlh_Matriks(pilihan);
	}else if(Jumlah == 2){
		dua:
		jumlah = MainKedua(jumlah);
		gotoxy(2,20);printf("%d",jumlah);
		//Enter();
		if(jumlah ==1){
			//gotoxy(2,20);printf("%s",logins.id);
			MenambahSubjek();
			goto dua;
		}if(jumlah == 4){
			//printf("sampaidisini");
			goto menu;
		}
	}else{
		return;
	}
	return;
}


void jmlh_Matriks(int jumlah){
	double nilaiIR [13] = {0.58, 0.90, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49, 1.51, 1.48, 1.56, 1.57, 1.59 };
	 
	 do{
	 	bersih_tampilan();
	 	bersih_tampilan_main();
	 	int i,j ,l=8,p=9;
	 	//gotoxy(2,7);printf(jumlah);
		for(i=0;i<jumlah;i++){
            gotoxy(2,l);printf("Masukkan nama kriteria ke-%i: ",i+1);
            gotoxy(2,p);scanf(" %[^\n]s",kriteria.nama_criteria[i]);  
			l+=2;
			p+=2; 
			if (l==24){
				l=8,p=9;
				bersih_tampilan_main();	
			}    
        }
        
        bersih_tampilan_main();
        
        for(i=0;i<jumlah;i++){
        	l=8;
        	gotoxy(2,l);printf("Masukkan nilai hubungan kriteria");
            for(j=0;j<jumlah;j++){
	            gotoxy(2,l+1);printf("%s dengan %s: ",kriteria.nama_criteria[i],kriteria.nama_criteria[j]);
	            scanf("%f",&kriteria.criteria[i][j]);
	            l+=1; 
            }
            bersih_tampilan_main();
            //gotoxy(2,l+1);printf("%.2f",kriteria.criteria[i][j]);
        }

        for(i=0;i<jumlah;i++){
            for(j=0;j<jumlah;j++){
                kriteria.tot_criteria[i] = kriteria.tot_criteria[i] + kriteria.criteria[j][i];   
            }
            //printf("[%i]:%f\n",i,kriteria.tot_criteria[i]);
            for(j=0;j<jumlah;j++){
                kriteria.des_tot_criteria[j][i] =  kriteria.criteria[j][i] / kriteria.tot_criteria[i];
                //printf("[%i][%i]:%.2f\n",j,i,kriteria.des_tot_criteria[j][i] );
            }
        }

        int k;
        for(i=0;i<jumlah;i++){
            kriteria.weight[i] = 0;
            for(k=0;k<jumlah;k++){
                kriteria.weight[i] = kriteria.weight[i] + kriteria.des_tot_criteria[i][k];
                //printf("[%i]=%f\n",i,kriteria.weight[i]);
            }
            //printf("hasil bagi dari %.2f / %i =",kriteria.weight[i] , jumlah);
            kriteria.weight[i] = kriteria.weight[i] / jumlah;
             //gotoxy(2,10);printf(" W= %f \n",kriteria.weight[i] );
        }

        for(i=0;i<jumlah;i++){
            kriteria.wsm[i]=0;
            for(k=0;k<jumlah;k++){
                kriteria.wsm[i] = kriteria.wsm[i] + kriteria.criteria[i][k] * kriteria.weight[k];
                ///printf("[%i] %.2f, %.2f",i,kriteria.criteria[i][k],kriteria.weight[k]);
            }
            //printf("[%i] %.2f \n",i+1,kriteria.wsm[i]);
        }

        for(i=0;i<jumlah;i++){
            kriteria.cv[i]=0;
            kriteria.cv[i] = kriteria.wsm[i] / kriteria.weight[i];
            //printf("%.2f",kriteria.cv[i]);
        }

        double sum = 0;
        for(i=0;i<jumlah;i++){
            sum = sum + kriteria.cv[i];
        }
        kriteria.average = sum / jumlah;
        //printf("Average(CV):%.2f\n",kriteria.average);

        kriteria.cl = (kriteria.average -jumlah)/(jumlah-1);
        //gotoxy(2,7);printf("CL4: %.2f\n",kriteria.cl);
        
		char *nm_matriks[15] ={"tiga","empat","lima","Enam","Tujuh","Delapan","Sembilan","Sepuluh","Sebelas","Dua Belas","Tiga Belas"};
        //printf("%s",nm_matriks[jumlah-3]);
		kriteria.cr = kriteria.cl / nilaiIR[jumlah-3];
        gotoxy(2,8);printf("nilai dari matriks ke");
		gotoxy(2,9);printf("%s adalah %.2f",nm_matriks[jumlah-3],kriteria.cr);
		Enter();
		
        if (kriteria.cl > 0.1) {
        	bersih_tampilan_main();
            gotoxy(2,8);printf("Terdapat penilaian data judgement");
			gotoxy(2,10);printf("yang perlu diperbaiki");
			gotoxy(2,12);printf("Mohon masukkan dengan benar\n");
            fflush(stdin);
            Enter();
        }else{
        	bersih_tampilan_main();
        	gotoxy(2,8);printf("Penilaian data sudah benar!");
        	char tumbal[40];
        	//strcpy(tumbal,logins.pass);
        	//strcat(tumbal,"/Data.txt")
        	//FILE *simpan=fopen(tumbal,"wb+");
        	Enter();
		}

    }while(kriteria.cl > 0.1);
    //next , bagaimana cara masukan matriks yang berbeda, dengan isi file yang berbeda setelah memasukkan data
    //bukan hanya masuk ke Data.txt aja,dimana letak harus meminta nama programnya
    
}

void MenambahSubjek(){
	char tumbal[40];	
	strcpy(tumbal,logins.pass);
	strcat(tumbal,"/Data.txt");
	
	//gotoxy(2,18);printf("%s\n",tumbal);
	Enter();
	
}



#endif
