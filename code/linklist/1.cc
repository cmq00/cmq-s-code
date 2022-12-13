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
    Node *s,*head,*r;
    
    int n;
    while(~scanf("%d",&n)){head = (struct Node *)malloc(sizeof(struct Node));
    r = head;
        while(n--){
            int x;
            scanf("%d",&x);
            s = (struct Node *)malloc(sizeof(struct Node));
            s->num = x; 
            r->next = s;
            r = s;
        }
        s->next = NULL;

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