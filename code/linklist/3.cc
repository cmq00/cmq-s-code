#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
	int data;
	struct Node *next;
}Node;
 
Node *CreatH();			//尾插法建立链表 
Node * CreatH1();		// 头插法建立链表 
void Show(Node *);		//输出链表 
void Ease(Node *);		//链表释放 
 
int main(void)
{
	Node *Head, *Head1;
	Head = CreatH(); 	
	Show(Head);
	Head1 = CreatH1();
	Show(Head1);
	Ease(Head); 
	
	return 0;
}
 
Node *CreatH()	//尾插法 
{
	int x;
	Node *Head;
	Head = (Node *)malloc(sizeof(Node));
	Head->next=NULL;	//初始化 
	Node *r;	//尾指针 
	
        r = Head;       //尾指针始终要指向最后一个结点，即最新创建的那个结点。
	while(scanf("%d", &x)!=EOF){
		Node *p = (Node *)malloc(sizeof(Node));
		p->data = x;
		r->next = p;    //将p连接到链表末尾
		r = p;          //r指向新的链表末尾
	} 
	r->next=NULL;           
	
	return Head;       
}
 
Node * CreatH1()		//头插法建立链表 
{
	int x;
	Node *Head;          //头指针
	Node *p;
	
	Head = (Node *)malloc(sizeof(Node));    //头结点
	Head->next=NULL;
	while(scanf("%d", &x)!=EOF){
		p = (Node *)malloc(sizeof(Node));    
                /*
                      申请新结点
                      一定不能这样写：Node p;
                      不可以直接定义一个结构体，如果这样，建立的链表在代码块结束后就会被释放掉。
                      必须动态分配一块内存，然后定义一个指针指向。
                */
 
		p->data = x;
		p->next = Head->next;    
		Head->next = p;
	}
	
	return Head;
}
 
void Show(Node *Head)        //输出链表
{
	Node *p;
	
	p = Head->next;            //不可以是 P = Head;
	while(p!=NULL){            //     while(p->Head!=NULL)  这样写的话，最后一个结点的数据就无法读取到。   
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\nend\n");
 
	return ;
} 
 
void Ease(Node *Head)        //释放链表，背下来就行。
{
	Node *p;
	while(Head!=NULL){
		p = Head;
		Head = Head->next;
		free(p);
	}
	
	
	return ;
}

