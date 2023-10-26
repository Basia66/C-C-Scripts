#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    char p;
    char input[200];
    fgets(input, sizeof input, stdin);
    puts(input);
    List *first = NULL,*num=NULL;


        p = input[0];
        while ()
        {
            switch (p)
            {
                case 'A':
                case 'a':
                {
                    //strtok(input," ");

                    if ()  // jeżeli o a jest 1 liczba
                    {
                        //gdy a 1 	Dodawania elementu na koniec listy.
                        addElemToEnd(first, num);
                    }

                    else //jeżeli po a są 2 liczby
                    {
                        //a 2 3 gdzie 2 to wartość elementu za którym należy dodać element zawierający liczbę 3 i wyświetlać 1 gdy dodano oraz 0 gdy nie dodano.

                        if (addElemAfterByNumber(first, num)!=NULL)
                        {
                            printf ("1"); //dodano
                        }
                        else
                        {
                            printf("0"); //nie dodano
                        }
                    }

                    break;
                }
                case 'F':
                case 'f': //f 1 i wyświetlać 1 gdy znaleziono 0 gdy nie znaleziono elementu
                {

                    if (searchElemByNumber(first, num)!=NULL)
                    {
                        printf ("1");
                    }
                    else
                    {
                        printf("0");
                    }
                    break;
                }
                case 'D':
                case 'd': //d 1, gdzie 1 to wartość elementu, który należy usunąć i wyświetlać 1 gdy usunięto element 0 gdy nie usunięto elementu
                {
                    if (removeByNumber(first,num)!=NULL)
                    {
                        printf ("1");
                    }
                    else
                    {
                        printf("0");
                    }
                    break;
                }
                case 'V':
                case 'v': // v 2 3 gdzie 2 to wartość elementu przed którym należy dodać element zawierający liczbę 3 i wyświetlać 1 gdy dodano oraz 0 gdy nie dodano.
                {

                    if (addElemPrevByNumber(first,num)!=NULL) //
                    {
                        printf ("1");
                    }
                    else
                    {
                        printf("0");
                    }
                    break;
                }
                case 'L': //wyświetlać wartości elementów zgodnie z kolejnością w liście w kolejnych liniach
                case 'l':
                {
                    //printList(first);
                    break;
                }
                case 'S':
                case 's': //s 1 2 gdzie 1 i 2 to wartości elementów, które należy zamienić.
                {
                    //List *e1,*e2;
                    //searchElemByNumber(first, e1);
                    //searchElemByNumber(first, e2);
                    break;
                }
                case 'Q':
                case 'q': //Program ma się zamykać
                {
                    //freeList();
                    return 0;
                }
                default:
                {
                    break;
                }
            }
            fgets(input, sizeof input, stdin);
        }
        //freeList();

    return 0;
}


