#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
void bakiyekontrol(char*);
void paratransferi(void);
void dispaly(char*);
void kisi(char*);
void giris(void);
void soygiris(void);
void soygiris(void);
void hesap(void);
void hesapyarat(void);
void girissonrası(void);
void cikisi(void);

void gotoxy(int x,int y) {
    COORD c;
    c.X=x;
    c.Y=y;

    SetConsoleCursorPosition(
       GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct pass {
    char username[50];
    int mounth,day,year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char adress[50];
    char typeaccount[20];
};
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};
struct userpass {
    char password[50];
};

int main() {
int i,a,b,choice;
    int passwordlenght;
    gotoxy(20,3);

    printf("BANKA GIRIS SISTEMINE HOSGELDINIZ\n\n");
gotoxy(18,5);
    printf("************************************");
    gotoxy(25,7 );
    printf("Developer - Deniz Gunarslan.");
    gotoxy(20,10 );
    printf("1-----Banka hesabi olustur.");
    gotoxy(20,12 );
    printf("2-----Zaten banka hesabin var mi ? Giris yap.");
    gotoxy(20,14 );
    printf("3-----Cikis\n\n");
    printf("\n\nSECİM YAPİNİZ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            system("cls");
        printf("\n\nKullaniciadi max 50 karakter olmalidir !");
        printf("\n\nSifreniz max 50 karakter olmalidir!");
        hesap();
        break;
        case 2:
            giris();
        break;
        case 3:
            exit(0);
        getch();
    }
}
void  hesap(void) {
    char password[50];
    int passwordlenght,i,seek=0;
    char ch;
    FILE *fp,*fu;
    struct pass u1;
    struct userpass p1;
    struct userpass u2;

    fp = fopen("username.txt","ab");
    system("cls");
    printf("\\n BANKA HESANBI OLUSTUR!!");
    printf("\nADINIZ:");
    scanf("%s",&u1.fname);
    printf("\n\nSOYADINIZ:");
    scanf("%s",&u1.lname);
    printf("\n\nBABA ADI:");
    scanf("%s",&u1.fathname);
    printf("\n\nANNE ADI:");
    scanf("%s",&u1.mothname);
    printf("\n\nADRES GIRINIZ:");
    scanf("%s",&u1.adress);
    printf("\n\nHESAP TIPI:");
    scanf("%s",u1.typeaccount);

    printf("\n\nDOGUM TARİHİ:");
    printf("\nGUN-");
    scanf("%s",&u1.day);
    printf("\nAY-");
    scanf("%s",&u1.mounth);
    printf("\nYIL-");
    scanf("%s",&u1.year);

    printf("\n\nADHAR NUMARASI:");
    scanf("%s",u1.adharnum);
    printf("\n\ncep NUMARASI:");
    scanf("%s",&u1.pnumber);
    printf("\n\nSOYADINIZ:");
    scanf("%s",u1.username);
    printf("\n\nPASSWORD");
    for (i=0; i<50; i++) {
        ch=getch();
        if (ch!=13) {
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }
        else {
            break;
        }
        fwrite(&u1,sizeof(u1),1,fp);
        fclose(fp);
        hesapyarat();

    }
}
    void hesapyarat(void) {
    int i;
    char ch;
    system("cls");
    printf("LUTFEN BEKLEYIN....\n\nVERILERINIZ ISLENİYOR....");
    for (i=0; i<20000000; i++){
        i++;
        i--;
    }
    gotoxy(30,10);
    printf("\nHESAP BASARIYLA OLUSTURULDU....");
    gotoxy(0,20);
printf("GİRİS YAPINIZ:");
    getch();
    giris();
}
void giris(void) {
    system("cls");
    char username[50];
    char password[50];
    int i,j,k;
    char ch;
    FILE *fp,*fu;
    struct pass u1;
    struct userpass u2;
    fp = ("username.txt","rb");
    if (fp == NULL) {
        printf("DOSTA ACIMINDA BIR HATA OLUSTU...");
    }
    gotoxy(34,2);
    printf("HESAP GIRIN");
    gotoxy(7,5);
    printf("********************************************************************");
    gotoxy(35,10);
    printf("===== GIRIS====");
    gotoxy(35,12);
    printf("SOYAD..");
    scanf("%s",username);
    gotoxy(35,14);
    printf("SIFRE....");
    for (i=0; i<50; i++) {
        ch = getch();
        if (ch!=13) {
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }

    else {
        break;
    }
}

        while (fread(&u1,sizeof(u1),1,fp)) {
            if (strcmp(username,u1.username)==0) {
                soygiris();
dispaly(username);
            }
        }
        fclose(fp);
    }
void soygiris(void) {
int i;
    FILE *fp;
    struct pass u1;
    system("cls");
printf("HESAP AYRINTILARI GETIRILIYOR...\n");
    for (i=0; i<20000; i++) {
        i++;
        i--;
    }
    gotoxy(30,10);
    printf("GIRIS YAPILDI....");
    gotoxy(0,20);
    printf("BIR TUSA BASINIZ");
    getch();
}
void dispaly (char username1[]) {
    system("cls");
    FILE *fp;
    int secim,i;
    fp = fopen("username.txt","rb");
    struct pass u1;
    if (fp == NULL) {
        printf("DOSYA ACIMINDA BIR HATA OLUSTU...");
    }
    while (fread(&u1,sizeof(u1),1,fp)) {
        if (strcmp(username1,u1.username==0)) {
gotoxy(30,1);
            printf("HOSGELDİN, %s %s ",u1.fname,u1.lname);
            gotoxy(28,2);
            printf("..........................");
            gotoxy(55,6);
            printf("=====ISTE BILGILERIN=====");
            gotoxy(55,8);
            printf("***************************");
            gotoxy(55,10);
            printf("NAME...%s %s",u1.fname,u1.lname);
            gotoxy(55,12);
            printf("BABA ISMI... %s",u1.fathname);
            gotoxy(55,14);
            printf("ANNE ISMI...%s",u1.mothname);
            gotoxy(55,16);
            printf("ADHAR NUMARASI... %s",u1.adharnum);
            gotoxy(55,18);
            printf("CEP NUMARASI...%s",u1.pnumber);
            gotoxy(55,20);
            printf("DOGUM TARIHI... %s. %s. %s.",u1.day,u1.mounth,u1.year);
            gotoxy(55,22);
            printf("ADRESINIZ... %s",u1.adress);
            gotoxy(55,24);
            printf("HESAP TIPI...%s",u1.typeaccount);

        }
    }
    fclose(fp);
    gotoxy(0,6);
    printf("  HOME  ");
    gotoxy(0,7);
    printf("1-----CEK KONTROLU");
    gotoxy(0,11);
    printf("2-----PARA TRANSFERI");
    gotoxy(0,13);
    printf("3-----OTURUMU KAPAT");
    gotoxy(0,15);
    printf("4-----CIKIS");
    printf(" SECIM YAPINIZ ");
    switch (secim) {
        case 1:
            bakiyekontrol(username1);
        break;
        case 2:
            paratransferi();
        break;
        case 3:
        cikisi();
        giris();
        break;
        case 4:
            exit(0);
        break;

    }
}
void paratransferi (void) {
    int i,j;
    FILE *fm,*fp;
    struct pass u1;
    struct money m1;
    char usernamet[50];
    char usernamep[50];
    system("cls");
    fp = fopen("username.txt","rb");
    fm = fopen("mon.txt","ab");
    gotoxy(33,4);
    printf("====PARA TRANSFERI====");
    gotoxy(33,5);
    printf("=========================");
    gotoxy(33,11);
    printf("KULLANICI ADI.......%s",usernamet);
    scanf("%s",&usernamet);
    gotoxy(33,13);
    printf("ADINIZ.....");
    printf("%s",&usernamep);
    while (fread(&u1,sizeof(u1),1,fp)) {
        if (strcmp(usernamep,u1.username)==0) {
            strcpy(m1.usernameto,u1.username);
            strcpy(m1.userpersonfrom,usernamet);
        }
    }
    gotoxy(33,16);
    printf("TRANSFER EDILECEK MIKTARI GIRINIZ..");
    scanf("%d",&m1.money1);
    fwrite(&m1,sizeof(m1),1,fm);
    gotoxy(0,26);
    printf("----------------------------------------------------------------------------------------------------------------------------------");
    gotoxy(0,28);
    printf("-----------------------------------------------------------------------------------------------------------------------------------");
    gotoxy(0,29);
    printf("Transfer yapiliyor lutfen bekleyiniz...");
    gotoxy(10,27);
    for (i=0; i<70; i++) {
        for (j=0; j<1200000; j++) {
            j++;
            j--;
        }
        printf("*");
    }
    gotoxy(33,40);
    printf("TRANSFER BASARIYLA TAMAMLANDI....");
    getch();
    fclose(fp);
    fclose(fm);
    dispaly(usernamet);
}


void bakiyekontrol (char username2[]) {
    system("cls");
    FILE *fm;
    struct money m1;
    char ch;
    int i = 1,summoney=0;
    fm = fopen("mon.txt","rb");
    int k=5,l=10;
    int m=30,n=10;
    int u=60,v=10;
    gotoxy(30,2);
    printf("===== BAKIYE TABLOSU =====");
    gotoxy(30,3);
    printf("****************************");
    gotoxy(k,l);
    printf("S no.");
    gotoxy(m,n);
    printf("ISLEM KIMLIGI..");
    gotoxy(u,v);
    printf("HESAP");
    while (fread(&m1,sizeof(m1),1,fm)) {
        if (strcmp(username2,m1.usernameto)==0) {
            gotoxy(k,l++);
            printf("%d",i);
            i++;
            gotoxy(m,n++);
            printf("%d",m1.userpersonfrom);
            gotoxy(u,v++);
            printf("%d",m1.money1);
            summoney=summoney+m1.money1;
        }
    }
    gotoxy(80,10);
    printf("TOPLAM BAKIYE");
    gotoxy(30,12);
    printf("%d",summoney);
getch();
    fclose(fm);
    dispaly(username2);
}
void cikisi (void) {
    int i,j;
    system("cls");
    printf("Lutfen bekleyin oturum kapatiliyor");
    for (i=0; i<10; i++) {
        for (j=0; j<25000000; j++) {
            i++;
            i--;

        }
        printf(".");
    }
    gotoxy(30,10);
    printf("Oturum kapatildi..");
    gotoxy(0,20);
    printf("Devam etmek icin bir tusa basiniz..");
    getch();
}