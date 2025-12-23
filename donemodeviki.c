#include<stdio.h>
//Melek Sima Özdil 252104020
//formüle göre sayılarla eşkenar üçgen çizme


int ucgen(int n){
    if(n==1)          
     return 1;
    return n+ucgen(n-1);  //üçgen sayı formülü

}

int main(){
  int A;
printf("A girin:");
scanf("%d",&A);
for(int i=1;i<=A;i++){  //kullanıcı A giriyor 1 den A ya kadar üçgen sayıları basıyor
  printf("%d ",ucgen(i));
}

  int n;
  int sayi=1;  //yazılacak sayılar buradan artıyor
    printf("Bir sayi giriniz: ");
    scanf("%d",&n);
  for(int i=1;i<=n;i++){    //satır sayısı kadar döngü
    for(int k=n-i;k>=0;k--){  //üçgenin ortalanması için boşluk bırakıyor
      printf(" ");
    }
    for(int j=1;j<=i;j++){   //her satırda i kadar sayı basıyor
      printf("%d ",sayi);
      sayi++;                //sayıyı arttırıyor
    }
    printf("\n");
  }
    return 0;
}



