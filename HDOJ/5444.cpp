/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14809881
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
 using namespace std;
 bool first;
  
 struct BST{
      int data;
      BST *leftchild;
      BST *rightchild;
 };
 
void Build(BST *&root,int x){
     if(root==NULL){
         root=(BST *)malloc(sizeof(BST));
         root->data=x;
         root->leftchild=root->rightchild=NULL;
     }else {
         if(x<root->data){
             Build(root->leftchild,x);
         }else 
             Build(root->rightchild,x);
     }
 }
 
 void Search(int v,BST *root){
    if(root == NULL){
        return;
    }else if(root->data > v){
        printf("E");
        Search(v, root->leftchild);
    }else if(root->data <v){
        printf("W");
        Search(v, root->rightchild);
    }else{
        return;
    }
 }
 
 int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        BST *root=NULL;
        int n;
        scanf("%d",&n);
         for(int i=1;i<=n;i++){
             int x;
             scanf("%d",&x);
             Build(root,x);
         }
        int q;
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            int t;
            scanf("%d",&t);
            Search(t,root);
            printf("\n");
        }
    }
}