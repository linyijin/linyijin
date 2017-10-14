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
