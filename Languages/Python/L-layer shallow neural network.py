'''
L-layer neural network
using built-in functions only for pre-processing
for predicting output of mnist datatset(http://yann.lecun.com/exdb/mnist/).
The dataset consists of 60,000 training
and 10,000 testing images and labels each of 28x28 pixels resolution.
'''

'''
packages:
numpy -> vectorized calculations
pandas -> reading csv data file
matplotlib -> plot the cost function
'''
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


#sigmoid function
def sigmoid(x):
    return 1/(1+np.exp(-x))

#differential sigmoid function
def dsigmoid(x):
    return x*(1-x)

#relu function
def ReLU(x):
    return x * (x > 0)

#differential relu
def dReLU(x):
    return 1. * (x > 0)

#load the dataset
dataset = pd.read_csv('mnist_trainc.csv')

#lables
y_train = dataset.iloc[:,0].values
y_train = np.array(y_train, ndmin=2)
y_train = y_train.T

#features
x_train = dataset.iloc[:,1:].values

#scaling all features
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
x_train = sc_X.fit_transform(x_train)

#convert labels from 0/1 to column vectors
from sklearn import preprocessing
lb = preprocessing.LabelBinarizer()
lb.fit([0,1,2,3,4,5,6,7,8,9])
lb.classes_
y_ttrain = y_train
y_train = lb.transform(y_train)

'''change this to increase or decrease number 
of nodes and layers of the neural-net'''
layer_dims = [x_train.shape[1], 800, 900, 600, 10]

#initialising parameters
parameters = {}

for l in range(1, len(layer_dims)):
    
    parameters["w"+str(l)] = np.random.randn(layer_dims[l-1], layer_dims[l])
    
    parameters["b"+str(l)] = np.zeros((layer_dims[l],1))

#change this as per requirement by trail and error
learning_rate = 0.0001
num_iterations = 20

cost_list = []

m = x_train.shape[0]
    
for i in range(num_iterations):
    #feedforward network
    
    #for ReLU layers
        
    
    cache = {}
    
    cache["a0"] = x_train.T
    
    
    for l in range(1, len(layer_dims)-1):
        
        a_prev =  cache["a"+str(l-1)]
        
        cache["z"+str(l)] = np.dot(parameters["w"+str(l)].T, a_prev) + parameters["b"+str(l)]
        
        cache["a"+str(l)] = ReLU(cache["z"+str(l)])
        
    cache["z"+str(len(layer_dims)-1)] = np.dot(parameters["w"+str(len(layer_dims)-1)].T, cache["a"+str(len(layer_dims)-2)]) + parameters["b"+str(len(layer_dims)-1)]
    cache["a"+str(len(layer_dims)-1)] = sigmoid(cache["z"+str(len(layer_dims)-1)])
    
   # cost = (-1/m)*(np.dot(y_train, np.log(cache["a"+str(len(layer_dims)-1)]))+np.dot((1-y_train), np.log(1-cache["a"+str(len(layer_dims)-1)])))
    
    
    #backpropogation
    grads = {}
    
    
    
    #for last layer
    dz = cache["a"+str(len(layer_dims)-1)] - y_train.T
    grads["dw"+str(len(layer_dims)-1)] = (1/m)*np.dot(dz, cache["a"+str(len(layer_dims)-2)].T)
    grads["db"+str(len(layer_dims)-1)] = (1/m)*np.sum(dz, axis = 1, keepdims = True)
    da = np.dot(parameters["w"+str(len(layer_dims)-1)], dz)
    
    
    #for L-1 layers
    for l in reversed(range(1, len(layer_dims)-1)):
        
        dz = np.multiply(da, dReLU(cache["z"+str(l)]))
        
        grads["dw"+str(l)] = (1/m)*np.dot(dz, cache["a"+str(l-1)].T)
        grads["db"+str(l)] = (1/m)*np.sum(dz, axis = 1, keepdims = True)
        
        da = np.dot(parameters["w"+str(l)], dz)
        
        
    #update parameters
    
    for l in range(1,len(layer_dims)):
        
        parameters["w"+str(l)] = parameters["w"+str(l)] - learning_rate*grads["dw"+str(l)].T
        
        parameters["b"+str(l)] = parameters["b"+str(l)] - learning_rate*grads["db"+str(l)]
        
       
    cost = np.sum(grads["db"+str(len(layer_dims)-1)]**2)
    
    cost_list.append(cost)
    
    if i%2==0:
        print("iteration ",i," cost ", cost)
        '''print("x_train", x_train.shape)
        print("y_train", y_train.shape)
        print("w2", parameters["w2"].shape)
        print("b1", parameters["b1"].shape)
        print("dw2", grads["dw2"].shape)
        print("db1", grads["db1"].shape)'''
        
        
#training accuracy
        
print("testing: training accuracy")
    
correct = 0
length = x_train.shape[0]

cache = {}
    
cache["a0"] = x_train.T


for l in range(1, len(layer_dims)-1):
    
    a_prev =  cache["a"+str(l-1)]
    
    cache["z"+str(l)] = np.dot(parameters["w"+str(l)].T, a_prev) + parameters["b"+str(l)]
    
    cache["a"+str(l)] = ReLU(cache["z"+str(l)])
    
cache["z"+str(len(layer_dims)-1)] = np.dot(parameters["w"+str(len(layer_dims)-1)].T, cache["a"+str(len(layer_dims)-2)]) + parameters["b"+str(len(layer_dims)-1)]
cache["a"+str(len(layer_dims)-1)] = sigmoid(cache["z"+str(len(layer_dims)-1)])
    
cache["a"+str(len(layer_dims)-1)] = cache["a"+str(len(layer_dims)-1)].T

for j in range(x_train.shape[0]):
    h = cache["a"+str(len(layer_dims)-1)][j]
    max = h[0]
    hypo = 0
    for i in range(10):
        if h[i]>max:
            #print(h[i])
            max = h[i]
            hypo = i
        
    if hypo == y_ttrain[j]:
        correct += 1
    
print(" accuracy: ", correct/length)
    


#load the dataset
dataset2 = pd.read_csv('mnist_testc.csv')


#lables
y_test = dataset2.iloc[:,0].values
y_test = np.array(y_test, ndmin=2)
y_test = y_test.T

#features
x_test = dataset2.iloc[:,1:].values

#scaling all features
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
x_test = sc_X.fit_transform(x_test)

from sklearn import preprocessing
lb = preprocessing.LabelBinarizer()
lb.fit([0,1,2,3,4,5,6,7,8,9])
lb.classes_
y_ttest = y_test
y_test = lb.transform(y_test)
    

print("testing: testing accuracy")
    
correct = 0
length = x_test.shape[0]

cache = {}
    
cache["a0"] = x_test.T


for l in range(1, len(layer_dims)-1):
    
    a_prev =  cache["a"+str(l-1)]
    
    cache["z"+str(l)] = np.dot(parameters["w"+str(l)].T, a_prev) + parameters["b"+str(l)]
    
    cache["a"+str(l)] = ReLU(cache["z"+str(l)])
    
cache["z"+str(len(layer_dims)-1)] = np.dot(parameters["w"+str(len(layer_dims)-1)].T, cache["a"+str(len(layer_dims)-2)]) + parameters["b"+str(len(layer_dims)-1)]
cache["a"+str(len(layer_dims)-1)] = sigmoid(cache["z"+str(len(layer_dims)-1)])
    
cache["a"+str(len(layer_dims)-1)] = cache["a"+str(len(layer_dims)-1)].T

for j in range(x_test.shape[0]):
    h = cache["a"+str(len(layer_dims)-1)][j]
    max = h[0]
    for i in range(10):
        if h[i]>max:
            #print(h[i])
            max = h[i]
            hypo = i
        
    if hypo == y_ttest[j]:
        correct += 1
    
print(" accuracy: ", correct/length)

    
c_list = np.array(cost_list)

plt.plot(c_list.T)

print("for learning rate: ", learning_rate)
plt.show

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
