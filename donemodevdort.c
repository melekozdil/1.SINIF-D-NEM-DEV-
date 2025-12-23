
#include <stdio.h>
#include <string.h>
//Melek Sima Özdil 252104020
//Sezar şifreleme algoritması
//mesaj şifreleme
int main() {
    char mesaj[200]; //en fazla 200 karakterlik mesaj
    int cümle;

    printf("Sifrelemek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin);  //fgets boşluklarıda alabildiği için kullanılır
                                           //stdin ile standart girdi alınır
                                             //sizeof ile dizinin boyutu kadar okuma yapılır
    printf("Anahtar degeri girin: ");
    scanf("%d", &cümle);//anahtar değeri alınıyor

    cümle = cümle % 26; //26 harf olduğu için mod 26 alınıyor

    for (int i = 0; mesaj[i] != '\0'; i++) {    //mesajın sonuna kadar döngü
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {        //küçük harf kontrolü
            mesaj[i] = ((mesaj[i] - 'a' + cümle) % 26) + 'a';   //şifreleme işlemi
        }
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {      //büyük harf kontrolü
            mesaj[i] = ((mesaj[i] - 'A' + cümle) % 26) + 'A';   //şifreleme işlemi
        }
        
        
    }
    printf("sifrelenmis mesaj: %s",mesaj);
    return 0;
}