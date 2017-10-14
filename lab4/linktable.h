#ifndef _LINK_TABLE_H
#define _LINK_TABLE_H
#include<pthread.h>
#define SUCESS 0
#define FAILURE (-1)
typedef struct LinkTableNode{
    struct LinkTableNode * pnext;
}tLinkTableNode;
typedef struct LinkTable{
    struct LinkTableNode * pHead;
    struct LinkTableNode * pTail;
    int    SumOfNode;
    pthread_mutex_t mutex;//muilt process
}tLinkTable;
tLinkTable * CreateLinkTable();
int DelLinkTable(tLinkTable *t);
int addLinkTableNode(tLinkTable *t,tLinkTableNode *pNode);
int DelLinkTableNode(tLinkTable *t,tLinkTableNode *PNode);
tLinkTableNode * GetLinkTableHead(tLinkTable *t);
tLinkTableNode * GetNextLinkTableNode(tLinkTable *t,tLinkTableNode *pNode);
#endif
