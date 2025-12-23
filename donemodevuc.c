#include<stdio.h>
//Melek Sima Özdil 252104020
//bob isimlendirme kurallarına göre geçerli isimleri bulan program
int gezegen(char isim){          //fonksiyon tanımlandı
    return (isim=='a'||isim=='e'||isim=='i'||isim=='o'||isim=='u'); //ünlü harf kontrolü yapılıyor
}
int asal(int n){ //asal sayi kontrolu 
    if (n<2)   //0 ve 1 de asallık aranmıyor
    return 0;
    for (int i=2;i*i<=n;i++){
        if(n%i==0)    //kalana bakılarak asal değilse 0 döndürüyor
        return 0;
    }
    return 1;
}
int main(){
    char a,b;
    int sayac=0;  //geçerli isim sayısı
    for(a='a';a<='z';a++){
        for(b='a';b<='z';b++){  //iki harf için döngü
            if(!gezegen(a)&&gezegen(b)){//ünsüz-ünlü-ünsüz
                int toplam=a+b+a;        //harflerin ascii değerleri toplanıyor
                if(asal(toplam)){
                    sayac++;            //geçerli isim sayısı arttırılıyor
                    printf("%c%c%c\n",a,b,a);
                }
 
            }
            if(gezegen(a)&&!gezegen(b)){//ünlü-ünsüz-ünlü
                int toplam=a+b+a;                            
                if(asal(toplam)){      
                    sayac++;
                    printf("%c%c%c\n",a,b,a);     //geçerli isim yazdırılıyor
                }
            }
        }
    }
    printf("gecerli isim sayisi: %d\n",count);
    return 0;
}