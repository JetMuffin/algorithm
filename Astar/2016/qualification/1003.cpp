#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=26;
char s[50],op[10];
int i,j;
typedef struct Trie_Node
{
    bool isWord;
    struct Trie_Node *next[MAX];
}Trie;

void insert(Trie *root,char *word)
{
    Trie *p=root;
    int i=0;
    int len = strlen(word);
    while(i<len)
    {
        if(p->next[word[i]-'a']==NULL)
        {
           // Trie *temp=(Trie *)malloc(sizeof(Trie));
           Trie *temp=new Trie;
            for(int j=0;j<MAX;j++)
             temp->next[j]=NULL;
            temp->isWord=false;
            p->next[word[i]-'a']=temp;
        }
        p=p->next[word[i]-'a'];
        i++;
    }
    p->isWord=true;
}
bool search(Trie *root,char *word)
{
    Trie *p=root;
    int len = strlen(word);
    for(int i=0;i<len;i++)
    {
        if(p->next[word[i]-'a']==NULL)
          return false;
        p=p->next[word[i]-'a'];
    }
    return true;
}
void delRoot(Trie *root, char *word) {
    Trie *p=root;
    Trie *pre=root;
    int len = strlen(word);
    for(int i=0;i<len;i++)
    {
        if(p->next[word[i]-'a']==NULL)
          return;
        pre=p;
        p=p->next[word[i]-'a'];
    }
    pre->next[word[len-1]-'a'] = NULL;
}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        Trie *root = new Trie;
          for(i=0;i<MAX;i++)
               root->next[i]=NULL;
            root->isWord=false;        
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
                delRoot(root, s);
            }
        }
    }
}