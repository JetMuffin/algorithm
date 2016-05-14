#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define MAX 26
using namespace std;
 
char s[100];
char op[100];
int i,j;
typedef struct TrieNode                     
{
    bool isStr;                            
    struct TrieNode *next[MAX];           
}Trie;
 
void insert(Trie *root,const char *s)     
{
    if(root==NULL||*s=='\0')
        return;
    int i;
    Trie *p=root;
    while(*s!='\0')
    {
        if(p->next[*s-'a']==NULL)        
        {
            Trie *temp=(Trie *)malloc(sizeof(Trie));
            for(i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            p->next[*s-'a']=temp;
            p=p->next[*s-'a'];   
        }   
        else
        {
            p=p->next[*s-'a'];
        }
        s++;
    }
    p->isStr=true;                      
}
 
int search(Trie *root,const char *s) 
{
    Trie *p=root;
    while(p!=NULL&&*s!='\0')
    {
        p=p->next[*s-'a'];
        s++;
    }
    return (p!=NULL);      
}
void del(Trie *root)                      
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}

void delNode(Trie *root,const char *s) {
    Trie *p=root;
    Trie *pre=root;
    while(p!=NULL&&*s!='\0')
    {
        pre = p;
        p=p->next[*s-'a'];
        s++;
    }    
    s--;
    pre->next[*s-'a']=NULL;
    del(p);
}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        Trie *root= (Trie *)malloc(sizeof(Trie));
        for(i=0;i<MAX;i++) {
            root->next[i]=NULL;
        }
        root->isStr=false;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            scanf("%s", op);
            scanf("%s", s);
            if(strcmp(op, "insert") == 0) {
                insert(root, s);
            } else if(strcmp(op, "search") == 0){
                bool flag = search(root, s);
                if(flag) {
                    puts("Yes");
                } else {
                    puts("No");
                }
            } else if(strcmp(op, "delete") == 0){
                delNode(root, s);
            }
        }
        // del(root);        
    }
    return 0;
}