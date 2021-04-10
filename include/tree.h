struct Node
{
    int data;
    Node *left=NULL,*right=NULL;

};
struct Tree
{
    Node * root=NULL;
    int Size=0;
};
void InsertNode(Node **pn,int &temp);
void Insert(Tree *pt,int &temp);
bool FindNode(Node **pn,int temp);
bool Find(Tree *pt,int temp);
void DeleteNodeTree(Node **pn);
bool DeleteNode (Node **pn,int temp);
bool Delete (Tree *pt,int temp);
bool Empty(Tree *pt);
bool Full (Tree *pt);
int Size_(Tree *pt);
void InOrderNode(Node **pn);
void InOrder(Tree *pt);
void ClearNode(Node **pn);
void PreOrderNode(Node **pn);
void PostOrderNode(Node **pn);
void PostOrder (Tree *pt);
void PreOrder (Tree *pt);
void Clear(Tree *pt);
int DepthNode(Node **pn);
int Depth(Tree *pt);

