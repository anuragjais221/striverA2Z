import numpy as np

def relu(x):
    x[x<=0] = 0
    return x


def ReLU(W,h,b):
    # W->d1xd2 h->d2x1 b->d1x1 
    x = np.dot(W,h)+b
    o = relu(x)
    return o