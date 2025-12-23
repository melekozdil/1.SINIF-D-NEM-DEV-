#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Melek Sima Özdil 252104020
//12 aylık para miktarıyla ciro grafiği çizme

int main() {
    int ciro[12];
    int i, j;
    srand(time(NULL));              //random sayıların aynı gelmemesi için
    printf("Uretilen aylik ciro verileri (1K cinsinden) \n");
    for (i = 0; i < 12; i++) {
        ciro[i] = (rand() % 10) + 1;      //1 ile 10 arasında rastgele sayılar üretir
        printf("%d. Ay: %dK\n", i + 1, ciro[i]);
    }


    int enbuyuk = ciro[0];
    // dikey grafik için en büyük değer bulunur
    for(i = 1; i < 12; i++) {
        if(ciro[i] > enbuyuk)        //en büyük değer bulunur
            enbuyuk = ciro[i];
    }

    //yatay bar grafiği yapılıyor
    printf("yatay bar grafigi\n\n");
    for(i = 0; i < 12; i++) {        //ay numarası yazılır ciro kadar yıldız basılır
        printf("%2d.: ", i + 1);
        for(j = 0; j < ciro[i]; j++) {   //ciro kadar döner
            printf("* ");
        }
        printf("\n");
    }

    //dikey bar grafiği yapılıyor
    printf("dikey bar grafigi\n\n");

    for(i = enbuyuk; i >= 1; i--) {   //en büyük değerden bire kadar döner
        for(j = 0; j < 12; j++) {
            if(ciro[j] >= i)         //ciro değeri i den büyük veya eşitse yıldız basılır
                printf(" * ");
            else
                printf("   ");   //boşluk için
        }
        printf("\n");
    }

    // Ay numaraları yazılıyor
    for(i = 1; i <= 12; i++) {  
        printf("%2d ", i);       //grafiğin altına 1 den 12 ye kadar yazılır
                                 //tablo düzgün olsun diye %2d kullanıldı
    }

    return 0;
}