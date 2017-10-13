#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
int Help();
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMDNUM      10
static tDataNode
{ 
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
   // {"help","this is help cmd!",Help,&head[1]},
    //{"version","menu program v1.0",NULL,NULL}
}tDataNode;
tData *FindCmd(tLinkTable head,char cmd)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        if(strcmp(pNode->cmd,cmd)==0)
            return pNode;
        pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
}
int ShowAllCmd(tLinTable*head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        printf("%s - %s\n",tDataNode->cmd,tDataNode->desc);
        pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkNode*)pNode);
    }
    return 0;
}
int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode * pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->data="help";
    pNode->desc="Menu List";
    pNode->handler=Help;
    addLinkTableNode(*ppLinkTable,(*tLinketable *)pNode);
    
}
main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s",cmd);
        tDataNode *p=FindCmd(head,cmd);
        if(p==NULL)
        {
            printf("this is a wrong cnd\n");
            continue;
        }
        printf("%s - %s\n",p->cmd,p->desc);
        if(p->handler !=NULL)
        {
            p->handler();
        }
    }
} 
int Help()
{
    ShowAllCmd(head);
    return 0;
}
