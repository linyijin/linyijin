#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
int Help();
int Quit();
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMDNUM      10
typedef struct DataNode
{ 
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
   
}tDataNode;
tDataNode *FindCmd(tLinkTable * head,char * cmd)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        if(strcmp(pNode->cmd,cmd)==0)
            return pNode;
        pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
}
int ShowAllCmd(tLinkTable*head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        printf("%s - %s\n",pNode->cmd,pNode->desc);
        pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}
int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode * pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="Menu List";
    pNode->handler=Help;
    addLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v1.0";
    pNode->handler=NULL;
    addLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="quit from menu";
    pNode->handler=Quit;
    addLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0; 
}
tLinkTable * head=NULL;
main()
{
    InitMenuData(&head);
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
int Quit()
{
    exit(0);
}
