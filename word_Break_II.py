from os import *
from sys import *
from collections import *
from math import *
def result(s, dictionary, mlen, res, l):
    if len(s) == 0:
       l.append(' '.join(res))
       return
    sub = ''
    i = 0
    while(i < len(s) and len(sub)<= mlen):
        sub += s[i]
        i += 1
        if sub in dictionary:
            res.append(sub)
            result(s[i:],dictionary,mlen,res,l)
            res.pop()



def wordBreak(s, dictionary):
    l = []
    mlen = 0
    for i in dictionary:
        if mlen<len(i):
            mlen = len(i)
    result(s, dictionary, mlen, [], l)
    return l