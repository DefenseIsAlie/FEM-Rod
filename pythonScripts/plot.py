import matplotlib.pyplot as plt
import numpy as np
import os
import math

constant = 5000/(70e9 * 12.5e-4)

def variableArea(X):
    return constant*0.5*(math.log(2, math.e) - np.log(1+X/0.5))

f = open("/home/abhishekj/projects/cs601pa2-karthikmurakonda/solution.txt")

X = []
Y = []

n = 0
for line in f:
    if n == 0:
        n+=1
        continue
    x,y = list(map(float, line.strip().split()))
    X.append(x)
    Y.append(y)

X = np.array(X)
Y = np.array(Y)
Analytical_Y = variableArea(X)

#print(Analytical_Y)

N = [2,8,16,32,64,128]



def constantArea(X):
    return constant*(0.5 - X)



for n_ele in N:
    os.system(f"./variable.out {n_ele}")
    f = open("/home/abhishekj/projects/cs601pa2-karthikmurakonda/pythonScripts/file.txt")
    X = []
    Y = []
    n = 0
    for line in f:
        if n == 0:
            n+=1
            continue
        x,y = list(map(float, line.strip().split()))

        X.append(x)
        Y.append(y)

    X = np.array(X)
    Y = np.absolute(np.array(Y))
    
    plt.figure()
    fig, ax = plt.subplots()
    ax.set_xlabel('x')
    ax.set_ylabel('u')

    Analytical_Y = variableArea(X)
    error = np.sum((Y-Analytical_Y)**2)
    ax.set_title(f'Variable Area N = {n_ele} error = {error}')
    ax.plot(X,Y, label=f'Numerical')
    ax.plot(X,Analytical_Y, label=f'Analytical')
    ax.legend() 
    fig.savefig(f'Variable {n_ele}')
    print(X)