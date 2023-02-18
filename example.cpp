#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** ilk;
int ** ikinci;
int ** girdiler;
int ** cevaplar;
int kacinciTekrar = 0;
int oran;
void program1() {
  srand(time(NULL));

  int i,  ilkSayi, ikinciSayi, girdi, mesajIndisi;
  float dogru = 0, yanlis = 0;
  char iltifat[5][20] = {
    "cok guzel",
    "Mukemmel",
    "Aferin",
    "Boyle Devam Et"
  };

  char teselli[4][40] = {
    "Hayir. Lutfen tekrar deneyin",
    "Yanlis. Lutfen bir daha deneyin",
    "Pes etmeyin",
    "Hayir. Denemeye devam edin"
  };
  

  ilk = (int ** ) malloc(1 * sizeof(int * ));
  ikinci = (int ** ) malloc(1 * sizeof(int * ));
  girdiler = (int ** ) malloc(1 * sizeof(int * ));
  cevaplar = (int ** ) malloc(1 * sizeof(int * ));
  ilk[0] = (int * ) malloc(10 * sizeof(int));
  ikinci[0] = (int * ) malloc(10 * sizeof(int));
  girdiler[0] = (int * ) malloc(10 * sizeof(int));
  cevaplar[0] = (int * ) malloc(10 * sizeof(int));

  int ctrl = 0;

  while (ctrl == 0) {
    for (i = 0; i < 10; i++)
    {
      ilkSayi = rand() % 10;
      ikinciSayi = rand() % 10;
      mesajIndisi = rand() % 4;
      ilk[kacinciTekrar][i] = ilkSayi;
      ikinci[kacinciTekrar][i] = ikinciSayi;
      cevaplar[kacinciTekrar][i] = ilkSayi * ikinciSayi;
      printf("%d kere %d = ", ilkSayi, ikinciSayi);
      scanf("%d", &girdi);
      girdiler[kacinciTekrar][i] = girdi;

      if (girdi == ilkSayi*ikinciSayi) {
        dogru++;
        printf("%s \n", iltifat[mesajIndisi]);
      } else {
        yanlis++;
        printf("%s \n", teselli[mesajIndisi]);
      }
    }

      if (dogru / (dogru + yanlis) >= 0.85) 
  {
      ctrl = 1;
      printf("basardin \n ");
    }
  else if (dogru / (dogru + yanlis) >= 0.75)
  {
      ctrl = 0;
      printf("10 soru daha. \n");
      kacinciTekrar++;

      ilk = (int ** ) realloc(ilk, (kacinciTekrar + 1) * sizeof(int * ));
      ikinci = (int ** ) realloc(ikinci, (kacinciTekrar + 1 ) * sizeof(int * ));
      girdiler = (int ** ) realloc(girdiler, (kacinciTekrar + 1 ) * sizeof(int * ));
      cevaplar = (int ** ) realloc(cevaplar, (kacinciTekrar + 1 ) * sizeof(int * ));

      ilk[kacinciTekrar] = (int * ) malloc(10 * sizeof(int));
      ikinci[kacinciTekrar] = (int * ) malloc(10 * sizeof(int));
      girdiler[kacinciTekrar] = (int * ) malloc(10 * sizeof(int));
      cevaplar[kacinciTekrar] = (int * ) malloc(10 * sizeof(int));
    } 
    else {
      ctrl = 1;
      printf("basaramadin,carpim tablosunu biraz daha calis \n");
    }
  }
  oran = (dogru / (dogru + yanlis)*100);
 }
void program2(){
	int n=0,i;
  	for (i = 0; i <= kacinciTekrar; i++) {
    	for (n = 0; n < 10; n++) {
     	 printf("%d kere %d verilen cevap--> %d dogru cevap-->%d \n", ilk[i][n], ikinci[i][n], girdiler[i][n], cevaplar[i][n]);
    	}
  	}
	printf("basari yuzdeniz = %% %d",oran);
}
  

int main() {
program1();
program2();
return 0;
}
