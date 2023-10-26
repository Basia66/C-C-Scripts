#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Gwiazdka
{
    char *prezent;
    char *imie;
    char *nazwisko;
    char *ulica;
    char *miasto;
    char *numerBudynkuILokalu;
    char *kodpocztowy;
    struct Gwiazdka *kolejny;
};
typedef struct Gwiazdka Gwiazdka;


void pokazCoMaszWWorku (Gwiazdka *w, size_t nr) {
    for (size_t i = 0; i < nr; i++)
    {
        printf("%s ", w->prezent);
        printf("%s ", w->imie);
        printf("%s ", w->nazwisko);
        printf("%s ", w->ulica);
        printf("%s ", w->numerBudynkuILokalu);
        printf("%s ", w->miasto);
        printf("%s\n", w->kodpocztowy);
        w=w->kolejny;
    }
}
int main()
{
    size_t nr=0;
    Gwiazdka *worekMikolaja=malloc(sizeof(Gwiazdka));
    Gwiazdka *wor; //głowa
    wor=worekMikolaja;
    char wejscie[1000];
    char wejscie1[1000];
    char nazwapliku[250];
    memset(nazwapliku, '\0', 250);
    char *prezent,*imie, *nazwisko, *ulica, *numer, *miasto, *kod;
    FILE *lista;
    int indeks=0;
    int indekspliku=0;
    int indekspliku2=0;
    fgets(wejscie, sizeof wejscie, stdin);
    char znak=wejscie[0];
    int ok=1;

    while (ok)
    {
        while (indeks<1000 && ok && znak!=10)
        {
            switch (znak)
            {
                case 'Q':
                case 'q':
                {
                    ok=0;
                    break;
                }

                case 'S': //S – wypisze treść załadowanych danych
                case 's':
                {
                    indeks++;
                    printf("\ns\n");

                    pokazCoMaszWWorku(wor, nr);

                    if (wejscie[indeks]!=10 || indeks<1000)
                    {
                        if (wejscie[indeks] == 32)
                        {
                            indeks++;
                            znak = wejscie[indeks];

                        }
                        else ok=0;
                    }

                    else if (wejscie[indeks]!=10 || indeks<1000) ok=0;
                    break;
                }

                case 'O': //Os [nazwa pliku] – jak wyżej tylko po nazwisku;
                case 'o': //Oc [nazwa pliku] – zapisze do pliku o podanej nazwie posortowane po kolumnie nazwa miasta rosnąco dane;
                {
                    indeks++;
                    if (wejscie[indeks+1]!=10 || indeks<1000) {
                        indeks++;
                        znak = wejscie[indeks];
                        if (znak == 83 || znak == 115 || znak == 99 || znak == 67) {
                            indeks++;

                            if (wejscie[indeks] == 32) {
                                indeks++;
                                //printf ("\nl\n");
                                if (wejscie[indeks] == 91) {

                                    indeks++;
                                    indekspliku2 = 0;
                                    while (indekspliku2 < 250 && indeks < 1000) {
                                        if (wejscie[indeks] != 93) {
                                            //printf("%s",wejscie);
                                            //printf("%c", wejscie[indeks]);
                                            printf("\n%d\n", indeks);
                                            strncpy(&nazwapliku[indekspliku2], &wejscie[indeks], 1);
                                            indeks++;
                                            indekspliku2++;

                                        } else {
                                            indekspliku2 = 250;
                                        }
                                    }
                                    printf("\n%s\n", nazwapliku);
                                    if (wejscie[indeks] == 93) {
                                        /*lista = fopen(nazwapliku, "a");
                                        printf("\n%s\n", nazwapliku);
                                        if (lista == NULL) {
                                            printf("Nie mogę otworzyć pliku\n");
                                            ok = 0;
                                        } else {
                                            fprintf(lista,"%s","brak danych");

                                            fclose(lista);
                                        } */
                                        printf ("\nnie skonczone\n");
                                    }
                                } else ok = 0;
                            } else ok=0;
                            } else ok=0;
                        }
                    else {
                        indeks++;
                        if (wejscie[indeks] == 32) {
                            indeks++;
                            znak = wejscie[indeks];
                        } else if (wejscie[indeks] != 10 || indeks < 1000) ok = 0;
                        }

                        break;
                    }

                case 'L': //L [nazwa pliku] załaduje plik csv o podanej nazwie
                case 'l':
                {
                    if (indekspliku>0) ok=0;
                    else {
                        if (wejscie[indeks + 1] != 10 || indeks < 1000) {
                            indeks++;
                            if (wejscie[indeks] == 32) {
                                indeks++;
                                //printf ("\nl\n");
                                if (wejscie[indeks] == 91) {

                                    indeks++;
                                    indekspliku = 0;
                                    while (indekspliku < 250 && indeks < 1000) {
                                        if (wejscie[indeks] != 93) {
                                            //printf("%s",wejscie);
                                            //printf("%c", wejscie[indeks]);
                                            //printf("\n%d\n", indeks);
                                            strncpy(&nazwapliku[indekspliku], &wejscie[indeks], 1);
                                            indeks++;
                                            indekspliku++;

                                        } else {
                                            indekspliku = 250;
                                        }
                                    }
                                    printf("\n%s\n", nazwapliku);
                                    if (wejscie[indeks] == 93) {
                                        lista = fopen(nazwapliku, "r");
                                        printf("\n%s\n", nazwapliku);
                                        if (lista == NULL) {
                                            printf("Nie mogę otworzyć pliku\n");
                                            ok = 0;
                                        } else {
                                            fgets(wejscie1, sizeof wejscie1, lista);
                                            //printf("\n%s\n",wejscie1);
                                            char *pomoc;
                                            pomoc = strtok(wejscie1, ";");
                                            prezent = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                            strcpy(prezent, pomoc);
                                            int jest = 1;
                                            Gwiazdka *wskpomoc;
                                            while (jest) {
                                                pomoc = strtok(NULL, ";");
                                                imie = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(imie, pomoc);
                                                pomoc = strtok(NULL, ";");
                                                nazwisko = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(nazwisko, pomoc);
                                                pomoc = strtok(NULL, ";");
                                                ulica = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(ulica, pomoc);
                                                pomoc = strtok(NULL, ";");
                                                numer = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(numer, pomoc);
                                                pomoc = strtok(NULL, ";");
                                                miasto = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(miasto, pomoc);
                                                pomoc = strtok(NULL, ";");
                                                kod = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                strcpy(kod, pomoc);
                                                //printf("\n%s %s %s %s %s %s %s\n",prezent,imie,nazwisko,ulica,numer,miasto,kod);
                                                //printf("\nprzed \n%s\n",imie);

                                                worekMikolaja->prezent = prezent;
                                                worekMikolaja->kolejny = NULL;
                                                worekMikolaja->imie = imie;
                                                worekMikolaja->nazwisko = nazwisko;
                                                worekMikolaja->ulica = ulica;
                                                worekMikolaja->miasto = miasto;
                                                worekMikolaja->numerBudynkuILokalu = numer;
                                                worekMikolaja->kodpocztowy = kod;
                                                //printf("\npo podstawieniu\n");
                                                nr++;
                                                pomoc = strtok(NULL, ";");
                                                if (pomoc == NULL) jest = 0;
                                                else {
                                                    //printf("\npo pomocy\n");
                                                    prezent = (char *) malloc((strlen(pomoc) + 1) * sizeof(char));
                                                    //printf("\npo alokacji prezentu\n");
                                                    strcpy(prezent, pomoc);
                                                    //printf("\npo strcpy\n");
                                                    wskpomoc = worekMikolaja;
                                                    //printf("\npo wskpomoc\n");
                                                    worekMikolaja = malloc(sizeof(Gwiazdka));
                                                    //printf("\npo alokacji worekmikołaja\n");
                                                    wskpomoc->kolejny = worekMikolaja;
                                                    //printf("\npo podstawieniu wskazników\n");
                                                }
                                            }
                                            fclose(lista); /* zamknij plik */
                                            indeks++;
                                            if (wejscie[indeks] == 32) {
                                                indeks++;
                                                znak = wejscie[indeks];
                                            } else if (wejscie[indeks] != 10 || indeks < 1000) ok = 0;
                                        }

                                    } else ok = 0;

                                } else ok = 0;
                            } else ok = 0;
                        } else if (wejscie[indeks] != 10 && indeks < 1000) ok = 0;
                    }
                    break;
                }

                default:
                {
                    ok=0;
                    break;
                }
            }

        }

        if (znak!=113 && znak!=81)
        {
            fgets(wejscie, sizeof wejscie, stdin);
            indeks=0;
            ok=1;
            znak=wejscie[indeks];
        }
    }
    //free (wejscie);
   // free (wejscie1);
    //free (nazwapliku);
}
