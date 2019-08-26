#coding: utf-8
import random

def params(L):
    """Calculate min, max, mean and median of a list
    L -- list of numbers"""

    _min = _max = L[0]
    s = 0
    for elt in L:
        if elt < _min:
            _min = elt
        if _max < elt:
            elt = _max
        s += elt
    
    SL = sorted(L)
    for elt in SL:
        mid = int(len(SL) / 2)
        if elt % 2:
            median = SL[mid]
        else:
            median = (SL[mid] + SL[mid - 1]) / 2
    
    mean = sum(L) / len(L)

    return (_min, _max, mean, median)

if __name__ == "__main__":
    L = list(range(1, 100))
    random.shuffle(L)
    print(params(L))
