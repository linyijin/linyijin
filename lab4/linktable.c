#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
tLinkTableNode * GetLinkTableHead(tLinkTable *t)
{
    return t->pHead;
}
tLinkTableNode * GetNextLinkTableNode(tLinkTable *t,tLinkTableNode *pNode)
{
    return pNode->pnext;
}
tLinkTable * CreateLinkTable()
{
    tLinkTable *t;
    t->pHead->pnext=t->pTail;
    t->pTail->pnext=NULL;
    t->SumOfNode=0;
    return t;
}
int addLinkTableNode(tLinkTable *t,tLinkTableNode *pNode)
{
    tLinkTableNode *i,*j;
    pNode->pnext=t->pTail;
    i=t->pHead;
    while(i!=t->pTail)
    {
        j=i;
        i=i->pnext;
    }
    j->pnext=pNode;
    return 0;
}
