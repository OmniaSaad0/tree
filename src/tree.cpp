#include<iostream>
#include "../include/tree.h"
using namespace std;
void InsertNode(Node **pn,int &temp)
{
    if(!(*pn))
    {
        (*pn)=new Node;
        (*pn)->data=temp;
        (*pn)->left=NULL;
        (*pn)->right=NULL;

    }
    else if((*pn)->data>temp)
    {
        InsertNode(&(*pn)->left,temp);
    }
    else
    {
        InsertNode(&(*pn)->right,temp);
    }
}

void Insert(Tree *pt,int &temp)
{
    InsertNode(&pt->root,temp);
    (pt->Size)++;
}


bool FindNode(Node **pn,int temp)
{
    Node *TempNode=*pn;
    bool found=0;
    while(TempNode && !(found =(TempNode->data==temp)))
    {
        if(TempNode->data<temp)
            TempNode=TempNode->right;
        else
            TempNode=TempNode->left;
    }
    if(found)
        return 1;
    return 0;
}
bool Find(Tree *pt,int temp)
{
    return FindNode(&pt->root,temp);
}

void DeleteNodeTree(Node **pn)
{
    Node *tempptr=*pn,*parrent;
    if(!(*pn)->left)
        *pn=(*pn)->right;
    else if(!(*pn)->right)
        *pn=(*pn)->left;
    else
    {
        tempptr=(*pn)->left;
        if(!(tempptr->right))
        {
            (*pn)->data=tempptr->data;
            (*pn)->left=tempptr->left;
        }
        else
        {
            parrent=tempptr;
            tempptr=tempptr->right;
            while(tempptr->right)
            {
                parrent=tempptr;
                tempptr=tempptr->right;
            }
            (*pn)->data=tempptr->data;
            parrent->right=tempptr->left;
        }
    }
    delete tempptr;

}

bool DeleteNode (Node **pn,int temp)
{
    bool found =0;
    Node *current=*pn,*parent=NULL;
    while(current && !(found=(current->data==temp)))
    {
        parent=current;
        if(current->data > temp)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }

    }
    if(found)
    {
        if(!parent)
            DeleteNodeTree(pn);
        else if(parent->data > temp)
            DeleteNodeTree(&(parent->left));
        else
            DeleteNodeTree(&(parent->right));

        return 1;
    }
    return 0;

}
bool Delete (Tree *pt,int temp)
{
    (pt->Size)--;
    return DeleteNode(&pt->root,temp);
}

bool Empty(Tree *pt)
{
    return !(pt->Size);
}
bool Full (Tree *pt)
{
    return 0;
}
int Size_(Tree *pt)
{
    return (pt->Size);
}

void InOrderNode(Node **pn)
{
    if(*pn)
    {
        InOrderNode(&(*pn)->left);
        cout<<(*pn)->data<<' ';
        InOrderNode(&(*pn)->right);
    }
}

void InOrder(Tree *pt)
{
    InOrderNode(&(pt->root));
}

void ClearNode(Node **pn)
{
    if(!(*pn))
    {
        ClearNode(&(*pn)->left);
        ClearNode(&(*pn)->right);
        delete (*pn);
    }
}



void PreOrderNode(Node **pn)
{
    if((*pn))

    {
        cout<<((*pn)->data)<<' ';
        PreOrderNode(&(*pn)->left);
        PreOrderNode(&(*pn)->right);
    }
}
void PreOrder (Tree *pt)
{
    PreOrderNode(&(pt->root));
}

void PostOrderNode(Node **pn)
{
    if((*pn))

    {
        PostOrderNode(&(*pn)->left);
        PostOrderNode(&(*pn)->right);
        cout<<((*pn)->data)<<' ';
    }
}
void PostOrder (Tree *pt)
{
    PostOrderNode(&(pt->root));
}

void Clear(Tree *pt)
{
    ClearNode(&(pt->root));
    pt->Size=0;
}

int DepthNode(Node **pn)
{

    if(!(*pn))
        return -1;
    else
    {

      int x= DepthNode(&(*pn)->left);
      int y= DepthNode(&(*pn)->right);

      return (x>y)?x+1:y+1;
    }
    //return dep;
}

int Depth(Tree *pt)
{

   return DepthNode(&(pt->root));

}
