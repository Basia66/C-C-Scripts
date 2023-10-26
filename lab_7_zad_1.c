#include <stdio.h>
#include <stdlib.h>

struct Drzewo
{
    int klucz;
    struct Drzewo *lewo;
    struct Drzewo *prawo;
};
typedef struct Drzewo Drzewo;

Drzewo *nowyLisc(int klucz)
{
    Drzewo *lisc=(Drzewo*)malloc(sizeof(Drzewo));
    lisc->lewo=NULL;
    lisc->prawo=NULL;
    lisc->klucz=klucz;
    return lisc;
}

Drzewo *wyszukiwanieLiscia(Drzewo *korzen, int klucz)
{
    if (korzen==NULL)
    {
        printf("0");
        return NULL;
    }
    while(korzen->klucz!=klucz)
    {

        if (korzen->klucz > klucz)
        {
            korzen=korzen->lewo;
        }
        else
        {
            korzen=korzen->prawo;
        }
        if (korzen==NULL)
        {
            printf("0");
            return NULL;
        }
    }
    printf("1");
    return korzen;
}
Drzewo *wyszukiwanieRodzica(Drzewo *korzen, int klucz)
{
    Drzewo *rodzic=korzen;
    if (korzen==NULL)
    {
        return NULL;
    }
    while(korzen->klucz!=klucz)
    {

        if (korzen->klucz > klucz)
        {
            rodzic=korzen;
            korzen=korzen->lewo;
        }
        else if (korzen->klucz < klucz)
        {
            rodzic=korzen;
            korzen=korzen->prawo;
        }

    }
    return rodzic;
}

Drzewo *wstawianieDoDrzewa(Drzewo *korzen, int klucz)
{
    if (wyszukiwanieLiscia(korzen,klucz)!=NULL)
    {
        return korzen;
    }
    Drzewo *nowy=nowyLisc(klucz);
        if (korzen==NULL)
        {
            return nowy;
        }

     Drzewo *poprzedni=korzen;
     Drzewo *pomoc=korzen;
        int ok=0;
        while (ok==0)
        {
            if (pomoc->klucz < nowy->klucz)
            {
                poprzedni=pomoc;
                pomoc=pomoc->prawo;
                if (pomoc==NULL)
                {
                    poprzedni->prawo=nowy;
                    ok=1;
                }
                //printf("prawo");
            }

            else
            {
                poprzedni=pomoc;
                pomoc=pomoc->lewo;
                if (pomoc==NULL)
                {
                    poprzedni->lewo=nowy;
                    ok=1;
                }
                //printf("lewo");
            }

        }
     return korzen;
}

void *printInOrder(Drzewo *korzen)
{
    if (korzen->lewo !=NULL) printInOrder(korzen->lewo);
    printf("\n%d\n",korzen->klucz);
    if (korzen->prawo!=NULL) printInOrder(korzen->prawo);
}

void *printPreOrder(Drzewo *korzen)
{
    printf("\n%d\n",korzen->klucz);
    if (korzen->lewo !=NULL) printPreOrder(korzen->lewo);
    if (korzen->prawo!=NULL) printPreOrder(korzen->prawo);
}

void *printPostOrder(Drzewo *korzen)
{
    if (korzen->lewo !=NULL) printPostOrder(korzen->lewo);
    if (korzen->prawo!=NULL) printPostOrder(korzen->prawo);
    printf("\n%d\n",korzen->klucz);
}

Drzewo *usuwanieZDrzewa(Drzewo *korzen, int klucz)
{
    if (korzen==NULL)
    {
        printf("0");
        return NULL;
    }
    Drzewo *usuwany=wyszukiwanieLiscia(korzen,klucz);
    Drzewo *ojciec=wyszukiwanieRodzica(korzen,klucz);
    if (usuwany==NULL)
    {
        printf("0");
        return korzen;
    }
    if (usuwany->prawo==NULL && usuwany->lewo==NULL && usuwany==ojciec)
    {
        free(usuwany);
        printf("\n1\n");
        return NULL; //puste drzewo, bo usuwamy ojca(korzen)
    }
    if (usuwany->prawo==NULL && usuwany->lewo==NULL) //jest to lisc
    {
        if (usuwany->klucz > ojciec->klucz)
        {
            ojciec->prawo=NULL;
            free(usuwany);
            printf("\n1\n");
            return korzen;
        }
        else
        {
            ojciec->lewo=NULL;
            free(usuwany);
            printf("\n1\n");
            return korzen;
        }
    }
    else if (usuwany->prawo==NULL && usuwany->lewo!=NULL)
    {
        if (ojciec->klucz > usuwany->klucz)
        {
            ojciec->lewo=usuwany->lewo;
        }
        else ojciec->prawo=usuwany->lewo;
        free(usuwany);
        printf("\n1\n");
        return korzen;
    }
    else if (usuwany->prawo!=NULL && usuwany->lewo==NULL)
    {
        if (ojciec->klucz > usuwany->klucz)
        {
            ojciec->lewo=usuwany->prawo;
        }
        else ojciec->prawo=usuwany->prawo;
        free(usuwany);
        printf("\n1\n");
        return korzen;
    }
    else //oba nie są null
    {
            if (usuwany==ojciec && ojciec->prawo->lewo==NULL)
            {
                korzen=ojciec->prawo;
                ojciec->prawo->lewo=ojciec->lewo;
                free(usuwany);
                printf("\n1\n");
                return korzen;
            }
            else if (usuwany==ojciec && ojciec->prawo->lewo!=NULL)
            {
                ojciec=ojciec->prawo;
                while(ojciec->lewo!=NULL)
                {
                    ojciec=ojciec->lewo;
                }
                wyszukiwanieRodzica(korzen,ojciec->klucz)->lewo=NULL;
                usuwany->klucz=ojciec->klucz;
                free(ojciec);
                printf("\n1\n");
                return korzen;
            }
            else if (usuwany!=ojciec && usuwany->prawo->lewo==NULL)
            {
                usuwany->klucz=usuwany->prawo->klucz;
                Drzewo *pomoc=usuwany->prawo;
                usuwany->prawo=usuwany->prawo->prawo;
                free(pomoc);
                printf("\n1\n");
                return korzen;
            }
            else
            {
                ojciec=usuwany->prawo;
                while(ojciec->lewo!=NULL)
                {
                    ojciec=ojciec->lewo;
                }
                wyszukiwanieRodzica(korzen,ojciec->klucz)->lewo=NULL;
                usuwany->klucz=ojciec->klucz;
                free(ojciec);
                printf("\n1\n");
                return korzen;
            }

    }
}



int main()
{
    char wejscie[300];
    int indeks=0;
    Drzewo *korzen = NULL;
    int klucz;
    fgets(wejscie, sizeof wejscie, stdin);
    char znak=wejscie[0];
    int ok = 1;

    while (ok)
    {
        while (indeks<300 && znak!=10 && ok ) {
            switch (znak) {
                case 'Q':
                case 'q': {
                    ok=0;
                    break;
                }
                case 'a':
                case 'f':
                case 'd':
                case 'A':
                case 'F':
                case 'D':
                    {
                        //printf("\nadf\n");
                        if (wejscie[indeks + 1] != 10 && indeks < 300) {
                            if (wejscie[indeks + 1] == 32) {
                                if (wejscie[indeks + 2] != 10 && indeks < 300) {
                                    klucz = (unsigned int) atoi(&wejscie[indeks + 2]);
                                    //printf ("%d",klucz);
                                    indeks = indeks + 2;
                                    while (wejscie[indeks] >= 48 && wejscie[indeks] <= 57) indeks++;
                                    if (znak == 97 || znak == 65) korzen = wstawianieDoDrzewa(korzen, klucz);
                                    if (znak == 102 || znak == 70) korzen = wyszukiwanieLiscia(korzen, klucz);
                                    if (znak == 100 || znak == 68) korzen = usuwanieZDrzewa(korzen,klucz);
                                }
                            } else ok = 0;
                        }
                        if (wejscie[indeks] == 32)
                        {
                            indeks++;
                            znak = wejscie[indeks];
                            //printf("\nkolejny znak = %c\n", znak);
                        }
                        else if (wejscie[indeks]!=10 && indeks<300) ok=0;
                        break;
                    }
                case 'i':
                case 'p':
                case 'v':
                case 'I':
                case 'P':
                case 'V':
                    {
                        //printf("\nipv\n");
                        if (wejscie[indeks + 1] != 10 && indeks < 300) indeks++;
                           if (znak == 105 || znak == 73) printInOrder(korzen);
                            if (znak == 80 || znak == 112) printPreOrder(korzen);
                            if (znak == 118 || znak == 86) printPostOrder(korzen);
                            if (wejscie[indeks] == 32)
                            {
                                if (wejscie[indeks + 1] != 10 && indeks < 300)
                                {
                                    indeks++;
                                    znak = wejscie[indeks];
                                    //printf("\nkolejny znak = %c\n", znak);
                                }

                            }
                            else if (wejscie[indeks]!=10 && indeks<300) ok=0;

                        break;
                    }

                default: {
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
            //printf("\nkolejny znak\n = %c",znak);
            //printf("\nost_ok=%d\n",ok);
        }
    }
}