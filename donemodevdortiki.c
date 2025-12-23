#include <stdio.h>
#include <string.h>
//Melek Sima Özdil 252104020
//Sezar şifreleme algoritması
//mesaj çözme
int main() {
    char mesaj[200]; //en fazla 200 karakterlik mesaj
    int cümle;

    printf("Cozmek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin); //fgets boşluklarıda alabildiği için kullanılır
                                           //stdin ile standart girdi alınır
                                           //sizeof ile dizinin boyutu kadar okuma yapılır

    printf("Anahtar degeri girin: ");
    scanf("%d", &cümle);  //anahtar değeri alınıyor

    cümle = cümle % 26; //26 harf olduğu için mod 26 alınıyor

    for (int i = 0; mesaj[i] != '\0'; i++) {  //mesajın sonuna kadar döngü
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {   //küçük harf kontrolü
            mesaj[i] = ((mesaj[i] - 'a' - cümle + 26) % 26) + 'a';   //çözme işlemi
        }
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {   //büyük harf kontrolü
            mesaj[i] = ((mesaj[i] - 'A' - cümle + 26) % 26) + 'A';  //çözme işlemi
        }
    }

    printf("Cozulmus Mesaj: %s", mesaj);
    return 0;
}