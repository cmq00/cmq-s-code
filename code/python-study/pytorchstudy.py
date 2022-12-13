
 33 #逐元素操作
 34 abs/sqrt/div(除法)/exp(指数)/fmod（求余
Tensor
#resize 
修改tensor的尺寸，可以超过原尺寸

#索引
a = t.rand(3,4)
a[0] 第0行
a[:,0]  第0列
a[0][2] = a[0,2]
a[:2]   前2行
a[:2,0:2]   前2行，第1，2列

a > 1   #返回一个ByteTensor
masked_select(a > 1)

#常用选择函数
index_select(input,dim,index)   #在指定维度上dim选取，例如选取某些行，列
masked_select(input,mask)   
###gather()
dim = 1 #跨域列维度对行维度进行映射[0,1],[2,0]括号里表示列，一行一行看
dim = 0 #                                     括号里表示行，一列一列看
gather逆操作#scatter

#高级索引
x[[1,2],[1,2],[2,0]]    #x[1,1,2] x[2,2,0]
x[[2,1,0],[0],[1]]  #x[2,0,1],x[1,0,1],x[0,0,1]
x[[0,2]]    #x[0],x[2]

'''
#Tensor类型
转换#type(new_typ)

#逐元素操作
abs/sqrt/div(除法)/exp(指数)/fmod（求余)/log/pow
cos/sin/asin/atan2/cosh
ceil/round/floor(下取整)/trunc(只保留整数部分
clamp(input,min,max) 超过min max部分拦截
sigmod/tanh 激活函数


#归并操作
mean/sum/median/mode 均值/和/中位数/众数
norm/dist   范数/距离
std/var 标准差/方差
cumsum/cumprod  累加/累乘
a.cumsum    沿着行累加

#比较函数
gt/lt/le/eq/ne  大于/小于/大于等于...不等
topk    最大的k个数
sort    排序
max/min 比较两个tensor的最大指和最小值

#线性代数
trace   对角线元素和
diag    对角线元素
triu/tril   上三角/下三角
mm/bmm  矩阵乘法
addmm/addbmm/addmv  矩阵运算
t   转置
dot/cross   内积/外积
invers  逆矩阵
svd 奇异值分解



