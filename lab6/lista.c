//
// Created by Barbara Adamczyk on 07.12.2018.
//

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

List *newElem (unsigned int number) //funkcja tworząca nowy element
    {
        List *new =(List *)malloc(sizeof(List));
        new->next = NULL;
        new->prev = NULL;
        new->num = number;
        return new;
    }

List *findTail(List *head) //funkcja szukająca ostatniego elementu
{
    while(head->next)
    {
        head=head->next;
    }
    return head;
}

List *findLastByNumber(List *head, unsigned int number1) //funkcja szukająca ostatniego numeru elementu listy
{
    while(head)
    {
        if (head->num==number1)
            return head;
        head = head->next;
    }
    return NULL;
}

List *findPreviousByNumber(List *head, unsigned int number2) //funkcja szukająca poprzedniego numeru elementu listy
{
    while (head->next)
    {
        if (head->next->num == number2)
            return head;
        head = head->next;
    }
    return NULL;
}

void pushBack(List *head, List *elem) //
{
    List *tail = findTail(head);
    if (tail == NULL)
        return;
    tail->next = elem;
}


List *removeHead(List *head) //
{
    List *newHead = head->next;
    free(head);
    return newHead;
}

List *removeByNumber(List *head, unsigned int number3) //
{
    List *elem = findLastByNumber(head,number3);
    if (elem->num==number3)
    {
        return removeHead(head);
    }
    List *prev = findPreviousByKey(head,number3);
    prev->next= elem->next;
    free(elem);
    return head;
}

void printNum(List *element) // wypisanie numeru elementu listy
{
    printf("%d\n",element->num);
}



void iterateWithFunction(List *head, void(*function)(List *))
{
    while(head)
    {
        function(head);
        head=head->next;
    }
}

void printList(List *head) //wypisanie listy
{
    iterateWithFunction(head, &printNum);
}

//-----------------------------------------------------------------------------------------------
List *newElem (unsigned int number)
{
    List *new =(List *)malloc(sizeof(List));
    new->next = NULL;
    new->prev = NULL;
    new->num = number;
    return new;
}

List *findHead(List *list)
{
    while(list->prev)
        list = list->prev;
    return list;
}

List *findByNumber(List *list, unsigned a)
{
    while (list)
    {
        if (list->num == a)
            return list;
    }
    return NULL;
}

List *addElemToEnd(List *list, unsigned number5)
{
    List *new = newElem(number5);
    findTail(list);
    list->next=new;
    new->prev = list;
    new->next = NULL;
}

List *searchElemByNumber(List *list, unsigned number8) {
    list = findHead(list);

    while (list) {
        if (list->num == number8)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

List *addElemPrevByNumber(List *list, unsigned number6)
{
    List *new = newElem(number6);
    list = findPreviousByKey(list,number6);

    if(list)
    {
        new->next = list;

        if (list->prev)
        {
            list->prev->next = new;
            new->prev = list->prev;
        }

        list->prev = new;
    }
}

List *addElemAfterByNumber(List *list, unsigned number7)
{
    List *new = newElem(number7);
    list = findLastByNumber(list,number7);
    List *next = list->next;
    if (next)
    {
        new->prev=list;
        if (list->next)
        {
            next->prev = new;
            new->next = next;
        }
        list->next = new;
    }
}

void changeElemByNumber(List *list, unsigned number9)
{
   List *e1=searchElemByNumber(list,number9);
   List *e2=searchElemByNumber(list,number9);

   e1->next = e2->prev;
   e2->prev = e1->next;


}

void freeList()
{

}