#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define clear system("@cls||clear");

int w=0;
int a;
int serce=6;
char nic2=' '; //do towrzenia odstepow tekstu, zeby nie robic stringow

int licz(int w, int a)
{
    if(a==1)
        w=w+5;
    else if(a==2)
        w=w+6;
    return w;
}

void wazprawy()
{
    printf("%30c   __   \n",nic2);
    printf("%30c  {0O}  \n",nic2);
    printf("%30c  \\__/   \n",nic2);
    printf("%30c  /^/  \n",nic2);
    printf("%30c ( (  \n",nic2);
    printf("%30c \\_\\_____  \n",nic2);
    printf("%30c (_______)  \n",nic2);
    printf("%30c(_________()Oo  \n",nic2);
}
void wazlewy()
{
    printf("%30c          __   \n",nic2);
    printf("%30c         {0O}  \n",nic2);
    printf("%30c         \\__/   \n",nic2);
    printf("%30c          \\^\\  \n",nic2);
    printf("%30c           ) )  \n",nic2);
    printf("%30c     _____/_/  \n",nic2);
    printf("%30c    (_______)  \n",nic2);
    printf("%30coO()_________)  \n",nic2);
}
void gora()
{
    printf("%20c",nic2);
    printf("OBRACAJ GRZECHOTNIKIEM NA ZMIANE\n");
    printf("%20c",nic2);
    printf("1 - LEWO            2 - PRAWO\n");
}

void dol()
{
    printf("\n%25c",nic2);
    for(int i=0;i<serce;i++)
    {
        printf("<3 ");    
    }
}
int clicker()
{   
    w=0;
    clear
    gora();
            wazprawy();
            printf("%25c",nic2);
            printf("wynik: %10d\n",w);
            dol();
        w=licz(w,a);
        printf("%50d",w);
        scanf("%d",&a);
        
    while(a!=0 && serce>0) //serce 0 oznacza utrate hp i wyjscie z petli
    {
        
        if(a==1)
            {
                clear
                w=licz(w,a);
                gora();
                wazprawy();
                printf("%25c",nic2);
                printf("wynik: %10d\n",w);
                dol();
                while(a!=2)
                {
                scanf("%d",&a);
                    if(a!=2)
                        serce= serce - 1;
                    else if(a==2)
                    {
                        clear
                        w=licz(w,a);
                        gora();
                        wazlewy();
                        printf("%25c",nic2);
                        printf("wynik: %10d\n",w);
                        dol();
                    }
                }
            }
        else if(a==2)
            {
                clear
                w=licz(w,a);
                gora();
                wazlewy();
                printf("%25c",nic2);
                printf("wynik: %10d\n",w);
                dol();
                while(a!=1)
                {
                scanf("%d",&a);
                    if(a!=1)
                        serce = serce -1;
                    else if(a==1)
                    {   
                        clear
                        w=licz(w,a);
                        gora();
                        wazprawy();
                        printf("%25c",nic2);
                        printf("wynik: %10d\n",w);
                        dol();
                    }
                }
            }
        scanf("%d",&a);
    }
    FILE *plik;
    if((plik = fopen("test.txt","w+")) == NULL)  //dodajemy if, żeby sprawdzić czy się otwiera
    {
        printf("Cos poszlo nie tak");
        exit(1);
    }
    int liczba=w;
    fprintf(plik,"%d",liczba);
    fclose(plik);
    return w;
}