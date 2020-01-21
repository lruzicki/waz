#include <stdio.h>
#include <stdlib.h>
#include "clicker.h"
#include "clicker.c"
#include "karty.h"
#include "karty.c"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define clear system("@cls||clear");

int przyciskmenu=0,przyciskmenu2=0; //wybor menu
int dlugosczycia; //długość życia węża
int hajs;
char nic=' ';
struct autor
{
    char *imie;
    int wiek;
    float wzrost;
};
char menu[4]="MENU";
int main()
{   
    struct autor Lukasz;
    Lukasz.imie="Lukasz";
    Lukasz.wiek=19;
    Lukasz.wzrost=1.83;
    clear
    printf("   ---_ ......._-_--. \n");      
    printf("  (|\\ /      / /| \\  \\ \n");
    printf("  /  /     .'  -=-'   `. ");
            for(int i=0;i<4;i++)
            {
                if(i==0)
                    printf("%20c",menu[i]);
                else
                    printf("%c",menu[i]);
            }
    printf("\n");
    printf(" /  /    .'             ) \n");
    printf("_/  /   .'        _.)   / ");
            printf("%15c",nic);
                    printf("1. Graj\n");
    printf("/ o   o        _.-' /  .' \n");
    printf("\\          _.-'    / .'*| ");
            printf("%15c",nic);
                    printf("2. TABELA WYNIKOW\n");
    printf("\\______.-'//    .'.' \\*| \n");
    printf("\\|  \\ | //   .'.' _ |*| ");
            printf("%15c",nic);
                    printf("  3. WYJDZ\n");
    printf(" `   \\|//  .'.'_ _ _|*| \n");
    printf("  .  .// .'.' | _ _ \\*| \n");
    printf("  \\`-|\\_/ /   \\ \\ _ _ \\*\\ \n");
    printf("   `/'\\__/      \\ _ _ \\*\\ \n");
    printf("  /^|            \\ _ _ \\* \n");
    printf(" '  `             \\ _ _ \\  \n");
    printf("                   \\_ ");
    printf("%30cAutor: %s lat %d, wzrost %.2f\n",nic,Lukasz.imie,Lukasz.wiek,Lukasz.wzrost);
    scanf("%d",&przyciskmenu);

    while(przyciskmenu>=0 && przyciskmenu<6)
    {
        switch (przyciskmenu)
        {
        case 1: // MENU Z GRAMI
            clear
                printf("   ---_ ......._-_--. \n");      
            printf("  (|\\ /      / /| \\  \\ \n");
            printf("  /  /     .'  -=-'   `. ");
                    printf("%19c",nic);
                            printf("Wybierz gre w jaka chcesz zagrac! \n");            printf(" /  /    .'             ) \n");
            printf("_/  /   .'        _.)   / ");
                    printf("%15c",nic);
                            printf("  1. Clicker\n");
            printf("/ o   o        _.-' /  .' \n");
            printf("\\          _.-'    / .'*| \n");
            printf("\\______.-'//    .'.' \\*| \n");
            printf("\\|  \\ | //   .'.' _ |*| \n");
            printf(" `   \\|//  .'.'_ _ _|*| \n");
            printf("  .  .// .'.' | _ _ \\*| \n");
            printf("  \\`-|\\_/ /   \\ \\ _ _ \\*\\ \n");
            printf("   `/'\\__/      \\ _ _ \\*\\ ");
                    printf("%15c",nic);
                            printf("  5. Cofnij do menu glownego\n");
            printf("  /^|            \\ _ _ \\* \n");
            printf(" '  `             \\ _ _ \\  \n");
            printf("                   \\_ \n");
            przyciskmenu=5;
            przyciskmenu2=1; // WARUNEK POWSTANIA NOWEGO SWITCHA
            break;
        case 2:
            clear
            printf("%19c",nic);
            FILE *plik2;
                    if((plik2 = fopen("wynik.txt","r")) == NULL)  //dodajemy if, żeby sprawdzić czy się otwiera
                    {
                        printf("Cos poszlo nie tak");
                        exit(1);
                    }
                    int liczba;
                    fscanf(plik2,"%d",&liczba);
                    printf("OSTATNI WYNIK TO: %d",liczba);

                    fclose(plik2);                    
        case 3:
            return 0;
        default:
            scanf("%d",&przyciskmenu);
            break;
        }
        if(przyciskmenu2==1)
        {
            przyciskmenu2=0;
                while (przyciskmenu2>=0 && przyciskmenu2<5)
                {
                switch (przyciskmenu2)
                {
                case 1:
                    clear
                    printf("Grasz w Clickera!");
                    hajs=clicker();
                    serce=6;
                    printf("Twoja gotowka to: %d\n",hajs);
                    karty();
                    przyciskmenu2=5;
                    break;
                default:
                    scanf("%d",&przyciskmenu2);
                    break;
                }
            }
        }
        clear
    printf("   ---_ ......._-_--. \n");      
    printf("  (|\\ /      / /| \\  \\ \n");
    printf("  /  /     .'  -=-'   `. ");
            for(int i=0;i<4;i++)
            {
                if(i==0)
                    printf("%20c",menu[i]);
                else
                    printf("%c",menu[i]);
            }
    printf("\n");
    printf(" /  /    .'             ) \n");
    printf("_/  /   .'        _.)   / ");
            printf("%15c",nic);
                    printf("1. Graj\n");
    printf("/ o   o        _.-' /  .' \n");
    printf("\\          _.-'    / .'*| ");
            printf("%15c",nic);
                    printf("2. TABELA WYNIKOW\n");
    printf("\\______.-'//    .'.' \\*| \n");
    printf("\\|  \\ | //   .'.' _ |*| ");
            printf("%15c",nic);
                    printf("  3. WYJDZ\n");
    printf(" `   \\|//  .'.'_ _ _|*| \n");
    printf("  .  .// .'.' | _ _ \\*| \n");
    printf("  \\`-|\\_/ /   \\ \\ _ _ \\*\\ \n");
    printf("   `/'\\__/      \\ _ _ \\*\\ \n");
    printf("  /^|            \\ _ _ \\* \n");
    printf(" '  `             \\ _ _ \\  \n");
    printf("                   \\_ ");
    printf("%30cAutor: %s lat %d, wzrost %.2f\n",nic,Lukasz.imie,Lukasz.wiek,Lukasz.wzrost);
    }
    return 0;
}