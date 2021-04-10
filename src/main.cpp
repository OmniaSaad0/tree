#include <iostream>
#include "tree.cpp"
using namespace std;

int main()
{

    Tree t;
    int x=5,a=2,s=3,d=4,f=6,g=7,h=8;

    Insert(&t,x);
    Insert(&t,a);
    Insert(&t,h);
    Insert(&t,s);
    Insert(&t,d);
    Insert(&t,g);
    Insert(&t,f);
    cout<<"the size is : "<<Size_(&t)<<endl;

    cout<<"the depth is : "<<Depth(&t)<<endl;

    cout<<"this is preordere layout : \n";
    PreOrder(&t);
    cout<<endl<<"----------------------\n";
    cout<<"this is inordere layout : \n";
    InOrder(&t);
    cout<<endl<<"----------------------\n";
    cout<<"this is postordere layout : \n";
    PreOrder(&t);
    cout<<endl<<"----------------------\n";
    Delete(&t,d);
    cout<<"the size after deleting one element is : "<<Size_(&t)<<endl;
    cout<<"this is inordere layout after deleting one element : \n";
    InOrder(&t);
    cout<<endl<<"----------------------\n";
    cout<<"the depth is : "<<Depth(&t)<<endl;
    Clear(&t);
    if(Empty(&t))
        cout<<"Empty\n";
    else
        cout<<"Not Empty\n";
    return 0;
}

