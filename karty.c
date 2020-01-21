#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define clear system("@cls||clear");
int sprawdzenie;
int i=0,x;
int bet1plus;
int kasakarty,kasakarty2;
int sumagracza=0,sumakomputera=0;
int bet1=0,bet2=0;
int reka1[5];
int reka2[5];
int kolorkomputera,kolorgracza;
int sprawdz()
{
    if(bet1==bet2)
    {   
        int kolor=reka1[0]%10;
        int kolor2=reka2[0]%10;
        if(kolor==reka1[1] && kolor==reka1[2] && kolor==reka1[3] && kolor==reka1[4])
        {   
            kolorgracza=kolor;
            if(kolor2==reka2[1] && kolor2==reka2[2] && kolor2==reka2[3] && kolor2==reka2[4])
                kolorkomputera=kolor2;
            if(kolor>kolor2)
            {
                kasakarty=kasakarty+bet1+bet2;
                printf("Wygrales!");
                return 1;
                
            }
            else if(kolor2>kolor)
            {
                kasakarty2=kasakarty2+bet1+bet2;
                printf("Przegrales!");
                return 0;
            }
            
            
        }
        else if(kolor==reka2[1] && kolor==reka2[2] && kolor==reka2[3] && kolor==reka2[4])
        {
            kasakarty2=kasakarty2+bet1+bet2;
            printf("Przegrales!");
            return 0;
        }
        sumagracza=0;
        sumakomputera=0;
        for(int i=0;i<5;i++)
        {
            sumagracza+=reka1[i]/10;
        }
        for(int i=0;i<5;i++)
        {
            sumakomputera+=reka2[i]/10;
        }
        
        if(sumagracza>sumakomputera)
        {
            kasakarty=kasakarty+bet1+bet2;
            printf("Wygrales!");
                return 1;
        }
        else if(sumakomputera<sumagracza)
        {
             kasakarty2=kasakarty2+bet1+bet2;
                printf("Przegrales!");
                return 0;
        }
    }
    else
    {
        return 0;
    }
}

int karty()
{
    FILE *plik;
    if((plik = fopen("test.txt","r")) == NULL)  //dodajemy if, żeby sprawdzić czy się otwiera
    {
        printf("Cos poszlo nie tak");
        exit(1);
    }
    fscanf(plik,"%d",&kasakarty);
    fclose(plik);
    // TUTAJ WCZYTAŁEM WYNIK Z WĘŻA
    int zmienna;
    int talia[53];
    talia[0]=0;
    for(int i=1;i<53;i++)
    {
        if(i<=13)
            talia[i]=(9+i)*10+1;
        else if(i>=14 && i<27)
        {
            zmienna=i-13;
            talia[i]=(9+zmienna)*10+2;
        }
        else if(i>=27 && i<40)
        {
            zmienna=i-26;
            talia[i]=(9+zmienna)*10+3;
        }
        else
        {
            zmienna=i-39;
            talia[i]=(9+zmienna)*10+4;
        } 
    }
    // LOSUJEMY RANDA, PATRZYMY CZY TABLICA NIE JEST PUSTA(talia[x]==0). JAK DOBIERAMY REKE TO reka1/2=talia[i] => talia[i]=0 
    // LOSUJEMY
    srand( time( NULL ) );
    while(i<5)
    {
        x= rand () % 53;
        if(talia[x]!=0)
        {
            reka1[i]=talia[x];
            talia[x]=0;
            i++;
        }
    }
        
    for(int j=0;j<5;j++)
        printf("Karta %d: %d\n ",j+1,reka1[j]);
    i=0;
    while(i<5)
    {
        x= rand () % 53;
        if(talia[x]!=0)
        {
            reka2[i]=talia[x];
            talia[x]=0;
            i++;
        }
    }
    // teraz lecimy hajs komputera

    printf("Twoje srodki to: %d\n",kasakarty);
    int kasakarty2=kasakarty;

    int wybor;
    
    while(kasakarty2>0 && kasakarty>0)
    {
            // tutaj wyswietla reke gracza
        clear
        for(int j=0;j<5;j++)
        {
            printf("Karta %d: %d  ",j+1,(reka1[j])/10-9);
            if(reka1[j]%10==1)
                printf("~#\n");
            else if(reka1[j]%10==1)
                printf("@\n");
            else if(reka1[j]%10==1)
                printf("<3\n");
            else
                printf("<>\n");
        }
        printf("\n1. Sprawdzenie\n");
        printf("2. Podbicie\n");
        printf("3. Pass\n");
        printf("Bet gracza: %d\n Bet komputera: %d\n Portfel: %d\n Portfel przeciwnika: %d\n",bet1,bet2,kasakarty,kasakarty2);

        // WYŚWIETLIĆ TUTAJ OPCJE MENU
        scanf("%d",&wybor);
            switch (wybor)
            {
            case 1:
                if(bet1==bet2)
                {
                   sprawdzenie=sprawdz();
                   if(sprawdzenie==1)
                        kasakarty=kasakarty+bet1+bet2;
                    else
                    {
                        kasakarty2=kasakarty2+bet1+bet2;
                    }
                    
                   
                   bet1=0;
                   bet2=0;
                   while(i<5)
                    {
                        x= rand () % 53;
                        if(talia[x]!=0)
                        {
                            reka1[i]=talia[x];
                            talia[x]=0;
                            i++;
                        }
                    }
                    while(i<5)
                        {
                            x= rand () % 53;
                            if(talia[x]!=0)
                            {
                                reka2[i]=talia[x];
                                talia[x]=0;
                                i++;
                            }
                        }

                    break;
                }
                else
                    clear
                    printf("Bety nie sa rowne");
                    break;
            case 2:
                printf("Napisz o ile chce podbic stawke: ");
                scanf("%d",&bet1plus);
                while(bet1plus>kasakarty)
                    {
                        scanf("%d",&bet1plus);
                    }
                kasakarty=kasakarty-bet1plus;
                bet1=bet1+bet1plus;
                bet2=bet1;
                kasakarty2=kasakarty2-bet2;
                if(kasakarty2==0 || kasakarty==0)
                {
                    sprawdzenie=sprawdz();
                   if(sprawdzenie==1)
                        kasakarty=kasakarty+bet1+bet2;
                    else
                    {
                        kasakarty2=kasakarty2+bet1+bet2;
                    }
                    
                   
                   bet1=0;
                   bet2=0;
                   while(i<5)
                    {
                        x= rand () % 53;
                        if(talia[x]!=0)
                        {
                            reka1[i]=talia[x];
                            talia[x]=0;
                            i++;
                        }
                    }
                    while(i<5)
                        {
                            x= rand () % 53;
                            if(talia[x]!=0)
                            {
                                reka2[i]=talia[x];
                                talia[x]=0;
                                i++;
                            }
                        }
                clear
                }
                break;
            case 3:
                kasakarty2=kasakarty2+bet1+bet2;
                bet1=0;
                bet2=0;
                while(i<5)
                    {
                        x= rand () % 53;
                        if(talia[x]!=0)
                        {
                            reka1[i]=talia[x];
                            talia[x]=0;
                            i++;
                        }
                    }
                    while(i<5)
                        {
                            x= rand () % 53;
                            if(talia[x]!=0)
                            {
                                reka2[i]=talia[x];
                                talia[x]=0;
                                i++;
                            }
                        }
                clear
                break;
            default:
                break;
            }
    }

    FILE *plik1;
    if((plik1 = fopen("wynik.txt","w")) == NULL)  //dodajemy if, żeby sprawdzić czy się otwiera
    {
        printf("Cos poszlo nie tak");
        exit(1);
    }
    int liczba=kasakarty;
    fprintf(plik1,"%d",liczba);
    fclose(plik1);

    printf("Dziekuje za gre, twoj wynik to %d\n", kasakarty);
    int wyjscie;
    printf("Wprowadz dowolna liczbe, aby wrocic do menu.");
    scanf("%d",&wyjscie);
    switch (wyjscie)
    {
    case 1:
        break;
    
    default:
        break;
    }
    return 0;
}