//
// Created by Barbara Adamczyk on 07.12.2018.
//

#ifndef LAB6_LISTA_H
#define LAB6_LISTA_H
struct List
{
    unsigned int num;
    struct List *next;
    struct List *prev;
};
typedef struct List List;
List *newElem (unsigned int number);
List *findTail(List *head);
List *findLastByNumber(List *head, unsigned int number1);
void pushBack(List *head, List *elem);
List *findPreviousByKey(List *head, unsigned int number2);
List *removeHead(List *head);
List *removeByNumber(List *head, unsigned int number3);
void printNum(List *element);
void iterateWithFunction(List *head, void(*function)(List *));
void printList(List *head);
#endif //LAB6_LISTA_H
