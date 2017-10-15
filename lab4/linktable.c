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
    tLinkTable *t=malloc(sizeof(tLinkTable));
    t->pHead=t->pTail=NULL;
    t->SumOfNode=0;
    return t;
}
int DelLinkTable(tLinkTable * t)
{
     free(t);
    return 0;
}

int addLinkTableNode(tLinkTable *t,tLinkTableNode *pNode)
{
    if(t->pHead==NULL)
    {
        t->pHead=pNode;
        t->pTail=pNode;
    }
    else
    {
        t->pTail->pnext=pNode;
        t->pTail=pNode;
    }
    t->SumOfNode++;
    t->pTail->pnext=NULL;
}
