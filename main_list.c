#include <stdio.h>
#include <stdlib.h>

struct List
{
    int numer;
    struct List *next;
    struct List *prev;
};
typedef struct List List;

List *newElement(int number) //tworzy nowy element i zwraca wskaznik na niego
{
    List *new=(List*)malloc(sizeof(List));
    new->next=NULL;
    new->prev=NULL;
    new->numer=number;
    return new;
}

List *findTail(List *wsk) //wsk to głowa; szuka ogona listy
{
    if (wsk==NULL)
    {
        return NULL;
    }
    while(wsk->next!=NULL)
    {
        wsk=wsk->next;
    }
    return wsk;
}


List *addToEnd(List *wsk, int number) //wsk to głowa; dodaje element number na koniec listy
{
    List *tail=findTail(wsk); //ogon listy
    List *new=newElement(number);
    if (wsk==NULL)
    {
        return new;
    }
    else
    {
        tail->next=new;
        new->prev=tail;
    }
    return wsk;
}


List *searchByNumber(List *wsk, int number) // wyszukuje element po number; wsk to głowa
{
    if (wsk==NULL)
    {
        return NULL;
    }
    unsigned ok=0;
    while (wsk!=NULL && ok==0)
    {
        if (wsk->numer==number)
        {
            printf("1");
            ok=1;
        }
        wsk=wsk->next;
    }
    if (ok==0)
    {
        printf ("0");
    }
    return wsk;
}

List *addPrevByNumber(List *wsk, int number1,int number2) // dodaje element number2 przed element number1
{
    List *new=newElement(number2);
    List *jump=searchByNumber(wsk,number1);

    if (wsk==NULL)	//pusta lista, dodanie elementu
    {
        wsk=new;
        return wsk;
    }

    else //dodawanie przed w innym miejscu
    {
        if (jump!=NULL && jump->prev!=NULL)
        {
            jump->prev->next=new;
            new->prev=jump->prev;
            new->next=jump;
            jump->prev=new;
            printf("1");
            return new;
        }
        else if (jump!=NULL && jump->prev==NULL)
        {
            new->next=jump;
            jump->prev=new;
            printf("1");
            return new;
        }
        else
        {
            printf("0");
            return NULL;
        }

    }
}
List *addAfterByNumber(List *wsk, int number1, int number2) // dodaje element number2 za element number1
{
    List *new=newElement(number2);
    List *jump=searchByNumber(wsk,number1);

    if (wsk==NULL)	//dodawanie na początek
    {
        wsk=new;
        return wsk;
    }
    else //dodawanie za w innym miejscu
    {
        if (jump!=NULL && jump->next!=NULL)
        {
            jump->next->prev=new;
            new->next=jump->next;
            jump->next=new;
            new->prev=jump;
            printf("1");
            return new;
        }
        else if (jump!=NULL && jump->next==NULL)
        {
            jump->next=new;
            new->prev=jump;
            printf("1");
            return new;
        }
        else
        {
            printf("0");
            return NULL;
        }

    }
}

List *deleteByWsk(List *wsk, List *elem) { //usuwa element na który wskazuje elem,wsk to głowa

    if (elem->prev == NULL) {
        wsk = elem->next;
        elem->next->prev = NULL;
        elem->next = NULL;
        free(elem);
        return wsk;
    } else if (elem->next == NULL) {
        elem->prev->next = NULL;
        elem->prev = NULL;
        free(elem);
        return wsk;
    } else {
        elem->next->prev = elem->prev;
        elem->prev->next = elem->next;
        elem->next = NULL;
        elem->prev = NULL;
        free(elem);
        return wsk;
    }
}

List *deleteByNumber(List *wsk, int number) { //usuwa elementów o konkretnej wartości
    List *elem = searchByNumber(wsk, number);
    if (elem == NULL) {
        printf("0");
        return NULL;
    }
    if (elem->prev == NULL) {
        wsk = elem->next;
        elem->next->prev = NULL;
        elem->next = NULL;
        free(elem);
        printf("1");
        return wsk;
    } else if (elem->next == NULL) {
        elem->prev->next = NULL;
        elem->prev = NULL;
        free(elem);
        printf("1");
        return wsk;
    } else {
        elem->next->prev = elem->prev;
        elem->prev->next = elem->next;
        elem->next = NULL;
        elem->prev = NULL;
        free(elem);
        printf("1");
        return wsk;
    }
}
void *changeElements(List *wsk, int number1, int number2) //zamienia elementy poprzez wstawienie nowych i usunięcie starych
{
    List *e1=searchByNumber(wsk,number1);
    List *e2=searchByNumber(wsk,number2);

    if (e1!=NULL && e2!=NULL)
    {
        addPrevByNumber(wsk,number1,number2);
        addPrevByNumber(wsk,number2,number1);
        deleteByWsk(wsk,e1);
        deleteByWsk(wsk,e2);
        free(e1);
        free(e2);
    }
}

void printList(List *wsk) //drukuje liste
{
    if (wsk==NULL)
    {
        printf("pusta lista");
    }
    while(wsk!=NULL)
    {
        printf("%d \t",wsk->numer);
        wsk=wsk->next;
    }
}


int main() {
    char znak;
    char input[200];
    List *i = NULL;
    List *glowa = NULL;
    scanf ("%s",input);
    znak=input[0];

    while (znak)
    {
        switch(znak)
        {
            case 'q':
            {
                free(i);
                return 0;
            }
            case 'a':
            {
                printf("znak a\n");
                //addToEnd()
                //addAfterByNumber()

                break;
            }
            case 'v':
            {
                printf("znak v\n");
                //addPrevByNumber()

                break;
            }
            case 'f':
            {
                printf("znak f\n");
                //searchByNumber()

                break;
            }
            case 's':
            {
                printf("znak s\n");
                //changeElements()

                break;
            }
            case 'l':
            {
                //printList()
                break;
            }
            case 'd':
            {
                printf("znak d\n");
                //deleteByNumber()

                break;
            }
            default:
            {
                break;
            }
        }
        scanf ("%c",&znak);
    }
    free(i);
}