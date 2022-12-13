#include <bits/stdc++.h>

using namespace std;
const int inf = -0x3f3f3f;
struct Node
{
    int dat;
    struct Node *next;
};

int main()
{
    Node *s,*head,*r;
    int n;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->dat = inf;
        r = head;
        for(int i = 0;i <= 4;++i){
            s = (struct Node *)malloc(sizeof(struct Node));
            s->dat = 2 * i + 1;
            r->next = s;
            r = s;
        }
        s->next = NULL;
    while(cin >> n){
        Node *p,*q,*ppp;
        p = head;
        if(n <= s->dat){
            while(p){
                ppp = p->next;
                if( (p->dat < n && n <= ppp->dat)){
                    q = (struct Node *)malloc(sizeof(struct Node));
                    q->dat = n;
                    q->next = p->next;
                    p->next = q;
                    break;
                }
                p = ppp;
            }
        }
        if(n > s->dat){
            q = (struct Node *)malloc(sizeof(struct Node));
            q->dat = n;
            q->next = s->next;
            s->next = q;
            s = q;
        }

       /* else if (n > 9){
            q = (struct Node *)malloc(sizeof(struct Node));
            q->dat = n;
            q->next = s->next;
            s->next = q;
            s = q;
        }*/
        /*else if(n <= 1) {
            q = (struct Node *)malloc(sizeof(struct Node));
            q->dat = n;
            q->next = head->next;
            head->next = q;
        }*/
       
        Node *pp;
        pp = head->next;
        while(pp != NULL){
            printf("%d ",pp->dat);
            pp = pp->next;
        }
        printf("\n");
    }
    return 0;
    
}