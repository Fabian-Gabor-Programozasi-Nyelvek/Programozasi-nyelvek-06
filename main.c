#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define HALLGATOK 10

/*
1. Egy tömb 10 hallgató jegyeit tartalmazza. Készíts programot, ami kiírja, volt-e bukás a csoportban! A leggyorsabb megoldásra törekedj!
2.a Írasd ki, hogy jeles volt-e az osztály (minden jegy ötös), vagy nem!
2.b Írasd ki, hogy hány jeles volt az osztályban!
3. Írasd ki a hallgatók átlagát az előző feladatok tömbjének segítségével!
4. Az elmúlt 30 nap megmértük minden nap a hőmérsékletet. Mely napon volt a legmelegebb és mennyi volt az értéke?
*/

int main()
{
    boolean bukas=false, jeles=true;
    int jegyek[10] = {3,4,2,4,5,1,3,2,2,5};
    int i=0;
    int jeles_szam=0;
    double atlag=0;
    int honap [30], max_homerseklet, max_homerseklet_nap;

    do
        if (jegyek[i++]<=1) bukas = true;
    while ((i<HALLGATOK) && (bukas != true));

    printf(bukas?"volt bukas\n":"nem volt bukas\n");

    do
        if (jegyek[i++]<5) jeles = false;
    while ((i<HALLGATOK) && (jeles != false));

    printf(jeles?"jeles osztaly\n":"nem jeles osztaly\n");


    for (i=0; i<HALLGATOK; i++)
        if (jegyek[i]==5) jeles_szam++;

    printf("Jelesek szama: %d\n", jeles_szam);

    for (i=0; i<HALLGATOK; i++) {
        atlag += jegyek[i];
    }
    atlag = atlag / HALLGATOK;

    printf("Atlag %f\n", atlag);


    for (i=0; i<30; i++)
        honap[i] = rand() % 60 - 30;

    for (i=0; i<30; i++)
        printf("%d ", honap[i]);
    printf("\n");

    max_homerseklet = honap[0];
    max_homerseklet_nap = 0;
    for (i=1; i<30; i++)
        if (max_homerseklet<honap[i]) {
            max_homerseklet = honap[i];
            max_homerseklet_nap = i+1;
        }
    printf("Max homerseklet: %d 'C a %d napon\n", max_homerseklet, max_homerseklet_nap);

    return 0;
}
