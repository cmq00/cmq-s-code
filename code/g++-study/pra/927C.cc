#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		queue<int>q;//队列定义，放在里面是为了每次清空队列
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			q.push(i);//把每个人的编号都按顺序压入队列中
		}
		int p=1,x,k;
		while(q.size()>3)//如果还有超过三个人,继续进行编号和排除等操作
		{
			x=q.size();//目前一共有多少人
			if(p&1)//如果是第奇数次，那么就是从 1 到 2 编号 
			{
				for(i=0;i<x/2;++i)//循环操作
				{
					k=q.front();//<span style="font-family: Arial, Helvetica, sans-serif;">取出编号为 1 的</span>
					q.push(k);//把编号为 1 的放后边，入队
					q.pop();//抛弃编号为 1 （已经放后面了，这个就不需要了）
					q.pop();//现在弹出的编号为 2 ，抛弃...
				}
				if(x&1)
				{
					k=q.front();//如果刚开始的时候为奇数个，那么最后还有一个人没被循环过....
					q.push(k);//放队尾
					q.pop();//抛弃.....
				}
			}
			else//第偶数次，那就是从 1 到 3 编号
			{
				for(i=0;i<x/3;++i)
				{
					k=q.front();q.push(k);//处理编号为 1 ，处理方式和前面一样.....
					q.pop();
					k=q.front();q.push(k);//处理编号为 2 
					q.pop();
					q.pop();//抛弃编号为 3 的
				}
				while(x%3!=0)//这里和前面的道理一样，防止有人未处理完
				{
					--x;
					k=q.front();q.push(k);//处理剩余的那几个....
					q.pop();
				}	
			}
			++p;
		}
		while(q.size()!=1)//输出，这样是为了控制格式...
		{
			printf("%d ",q.front());
			q.pop();
		}
		printf("%d\n",q.front());	
	}
	return 0;
}


