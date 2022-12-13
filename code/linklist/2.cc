#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int num;
    struct Node *next;
};


void Ease(Node *Head) 
{
	Node *p;
	while(Head!=NULL){
		p = Head;
		Head = Head->next;
		free(p);
	}
}

int main()
{
     
    int n;Node *p,*head,*q;
    while(~scanf("%d",&n)){
        head = (struct Node *)malloc(sizeof(struct Node));
        head->next = NULL;
        while(n--){           
            int x;
            scanf("%d",&x);
            p = (struct Node *)malloc(sizeof(struct Node));    
            p->num = x;
            //cout << p->num << endl;
            p->next = head->next;
            head->next = p;
        }      
        Node *pp;
        pp = head->next;
        while(pp != NULL){
            printf("%d ",pp->num);
            pp = pp->next;
        }
        printf("\n");
        //Ease(head);
    }
    return 0;
}