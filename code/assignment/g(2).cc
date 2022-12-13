#include<bits/stdc++.h>
using namespace std;
#define N 50010
 
struct node
{
	int pre;
	int relation;
};
node p[N];
 
int find(int x) //查找根结点
{
	int temp;
	if(x == p[x].pre)
		return x;
	temp = p[x].pre; //路径压缩
	p[x].pre = find(temp);
	p[x].relation = (p[x].relation + p[temp].relation) % 2; //关系域更新

	return p[x].pre; //根结点
}
 
int main()
{

    int t;
    scanf("%d", &t);

    while (t --) {
	
        int sum = 0; //假话数量
	    int n, k;

		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) //初始化
		{
			p[i].pre = i;
			p[i].relation = 0;  /*好人*/
		}

        char ope[7]; int ope_i;
	    int root1, root2;
    	int a, b;

		for(int i = 1; i <= k; ++i)
		{
			scanf("%d%d%s", &a, &b, ope);
			if(a > n || b > n)  
			{
				sum++;
				continue;
			}
            if (ope[0] == 'n') ope_i = 1;
            else ope_i = 0;
			if(ope_i == 1 && a == b) //内鬼， 说自己是内鬼，这是不对的
			{
				sum ++;
				continue;
			}
			root1 = find(a);
			root2 = find(b);
			if(root1 != root2) // 合并
			{
				p[root2].pre = root1;
				p[root2].relation = (2 + ope_i +p[a].relation - p[b].relation) % 2;
			}
			else
			{
				if(ope_i == 1 && p[a].relation != p[b].relation)
				{
					sum++;
					continue;
				}
			}
		}
        if (sum > 0) 
            printf("Yes\n");
        else
            printf("No\n");
    }
	return 0;
}
