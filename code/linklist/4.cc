#include<bits/stdc++.h>
using namespace std;
int a[10010]={1,3,5,7,9};

struct node{
    int data;
    struct node *next;
};

void createlistF(node *&L, int a[], int n){
	node *s;
	L=(node*)malloc(sizeof(node));
	L->next=NULL;
	for(int i=0;i<n;++i){
		s=(node*)malloc(sizeof(node));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}

int main(){
    node *L;
    int t,c=5;
    while(~scanf("%d",&t)){
        a[c]=t;
        sort(a,a+c+1);
        reverse(a,a+c+1);
        createlistF(L,a,c+1);
        node *temp=L;
        while(temp->next){
            temp=temp->next;
            printf("%d ",temp->data);
        }
        puts("");
        c++;
    }
    return 0;
}