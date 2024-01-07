#include <stdio.h>
#include <stdlib.h>



// DOSYADAKÝ ÖÐRENCÝ SAYISINI BULUP NOT ORTALAMALARINI YAZDIRMA
int main() {
	
	FILE *fp = fopen("ogrencinotlari.txt","r");
		
	char c,m;
	char ad[25];
	char soyad[25];
	if(fp == NULL) {
		printf("dosya okunamadi");
	}else {
		
		m=fgetc(fp);
		while(m!=EOF){
			printf("%c",m);
			m=fgetc(fp);
		}
		rewind(fp);
		
		int kisiSayisi=1;
		
		c=fgetc(fp);
		while(c != EOF) {
			if(c=='\n') {
				kisiSayisi++;				
			}
			c=fgetc(fp);	
		}

		rewind(fp); // asagýdaki donguye girmiyor dosyayý baþtan okumaya yolla
		int toplam =0,ortalama=0;
		for(int i=0;i<kisiSayisi;i++) {
			fscanf(fp,"%s",ad);
			fscanf(fp,"%s",soyad);
			fscanf(fp,"%d",&toplam);
			ortalama+=toplam;
		}
		
		printf("\n\nnotlarin ortalamasi : %d\n",(ortalama/kisiSayisi));
		printf("\nOgrenci sayisi : %d", kisiSayisi);
		
		
		
	}
	
	fclose(fp);
	
	return 0;
}
