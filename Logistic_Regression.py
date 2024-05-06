import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split




x = pd.read_excel('data-2019-7.xlsx',usecols=['Line Current [A] DEV1'])
y = pd.read_excel('data-2020-7.xlsx',usecols=['Line Current [A] DEV1']) 
x=np.array(x)
y=np.array(y)
x=x[:len(y)]

path=r"D:\深度学习\logistic-regression.txt"
data=np.loadtxt(path)
data=pd.DataFrame(data,columns=["parameter1","parameter2","result"])


# 数据集划分
X=data.drop(columns=["result"])
y=data["result"]
train_X,valid_X,train_y,valid_y=train_test_split(X,y,test_size=0.2)



# 数据载入（转换为numpy）(提取X与y)
train_X=np.array(train_X)
train_y=np.array(train_y)
train_y=train_y.reshape(80,1)

valid_X=np.array(valid_X)
valid_y=np.array(valid_y)
valid_y=valid_y.reshape(20,1)


#初始化参数
w = np.zeros((2,1))
b=0
learning_rate=0.01
num_iters=100



#sigmoid
def sigmoid(z):
    y=1/(1+np.exp(-z))
    return y
#线性估计
def linear(X,w,b):
    y=np.dot(X,w)+b
    return y
#计算代价函数
def costfunc(y,X,w,b):
    y_pre=linear(X, w,b)
    m=len(y)
    h=sigmoid(y_pre)
    g=(-1/m) * np.sum(y * np.log(h) + (1 - y) * np.log(1 - h))
    return g
#梯度下降
def gradient_decent(w,alpha,y,X,num_iters,b):
    #m:size of sample
    m=len(y)
    #visualize costfunction
    cost_history=[]

    for i in range(num_iters):
        #每个权重都需进行梯度下降
        w1=w[0]
        w2=w[1]
        #计算梯度
        y_pre=linear(X, w, b)
        h=sigmoid(y_pre)
        p=h-y
        w1_gradient=1/m*np.sum(np.dot(p.T,X[:,0]))
        w2_gradient=1/m*np.sum(np.dot(p.T,X[:,1]))
        b_gradient=np.sum(p)/m
        
        #迭代
        w1=w1-alpha*w1_gradient
        w2=w2-alpha*w2_gradient
        b=b-alpha*b_gradient
        #计算历史代价函数
        cost=costfunc(y, X, w,b)
        cost_history.append(cost)
        #更新权重参数
        w=[w1,w2]
        if i % 1000 == 0:
            print(w,b)
    
    return w,b,cost_history
w,b,cost_history=gradient_decent(w, learning_rate, train_y, train_X, num_iters, b)
w1=w[0]
w2=w[1]

#绘制图像
# 创造画布(fig)与坐标轴(ax)
fig, ax = plt.subplots(figsize=(12,8))

# 自规定 将结果为1的分为positive类 ， 将结果为0的分为negative类，以用于数据的逻辑回归分类
positive = data[data['result'].isin([1.])]
negative = data[data['result'].isin([0.])]

# 设置散点图
ax.scatter(positive['parameter1'], positive['parameter2'], s=50, c='b', marker='o', label='positive')
ax.scatter(negative['parameter1'], negative['parameter2'], s=50, c='r', marker='x', label='negative')

# 设置图例 
ax.legend()

# 设置横纵坐标标签
ax.set_xlabel('parameter1')
ax.set_ylabel('parameter2')


#设定x
x = np.arange(-3,3,0.1)
#设定y
y=-w1*x/w2-b/w2
#画图
plt.plot(x,y)
plt.show()
#检验精度
x=valid_X
y=valid_y
def mymodel(x,w,b):
    return sigmoid(linear(x, w,b))
y_pre_eval = mymodel(x,w,b)
y_pre_preocess=(y_pre_eval>=0.5)
correct=(y_pre_preocess==y)
print(f'acc:{correct.sum()/len(y)}')