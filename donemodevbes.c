#include <stdio.h>
//Melek Sima Özdil 252104020
//Labirentte çıkış yolu bulma

#define BOYUT 5      //boyut tanımlanıyor
                     //define kullanımı sabit değerlerde tercih edilir

int labirent[BOYUT][BOYUT] = {  //labirent matrisi yazılıyor
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

int yol[BOYUT][BOYUT] = {0};  //yol matrisi başlangıçta 0larla dolduruluyor

//Hücre geçerli mi
int gecer(int x, int y) {
    return (x >= 0 && x < BOYUT &&  //x ve y sınırları içinde mi
            y >= 0 && y < BOYUT &&
            labirent[x][y] == 1);  //labirentte 1 ise geçerli
}
//yol bulma
int yolBul(int x, int y) {  //x ve y koordinatları

    //cıkış
    if (x == BOYUT - 1 && y == BOYUT - 1 && labirent[x][y] == 1) {  
        yol[x][y] = 1;              //çıkış noktasını işaretle
        return 1;                   //başarıyla çıkış bulundu
    }

    if (gecer(x, y)) {

        if (yol[x][y] == 1)      //zaten var ise
            return 0;            //geri döndür

        yol[x][y] = 1;             //şu anki yolu işaretle

        //asagı
        if (yolBul(x + 1, y))    
            return 1;

        //saga
        if (yolBul(x, y + 1))
            return 1;

        //yukarı
        if (yolBul(x - 1, y))
            return 1;

        //sola
        if (yolBul(x, y - 1))
            return 1;

        //geri
        yol[x][y] = 0;
        return 0;
    }

    return 0;
}

//yolu yazdır
void yazdir() {
    for (int i = 0; i < BOYUT; i++) {      //satırlar
        for (int j = 0; j < BOYUT; j++) {   //sütunlar
            printf("%d ", yol[i][j]);       //yolu yazdır
        }
        printf("\n");
    }
}

int main() {

    //baslangıc ve cıkış kontrolü
    if (labirent[0][0] == 0 || labirent[BOYUT - 1][BOYUT - 1] == 0) {  //başlangıç veya bitişin önünde engel varsa
        printf("Baslangic veya cikis gecersiz\n");
        return 0;
    }

    if (yolBul(0, 0)) {               //yol bulma fonksiyonu çağırılır
        printf("Cikis yolu bulundu:\n");
        yazdir();
    } else {                           //yol bulunamazsa
        printf("Cikis yolu bulunamadi.\n");
    }

    return 0;
}