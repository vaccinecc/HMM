# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 10:19:20 2018

@author: LGQ
"""

import numpy
startP = mat([0.63,0.17,0.20]) #初始化概率
stateP = mat([[0.5,0.375,0.125],[0.25,0.125,0.625],[0.25,0.375,0.375]])#状态转移矩阵
emitP  = mat([[0.6,0.2,0.05],[0.25,0.25,0.25],[0.05,0.10,0.5]]) #发射概率

#计算干旱概率
state1Emit = multiply (startP,emitP[:,0].T) 
print state1Emit
print "argmax:",state1Emit.argmax()
#计算干燥的概率
state2Emit = stateP * state1Emit.T
state2Emit = multiply(state2Emit,emitP[:,1])
print state2Emit.T
print "argmax:",state2Emit.argmax()
#计算潮湿的概率
state3Emit = stateP * state2Emit
state3Emit = multiply(state3Emit,emitP[:,2])
print state3Emit.T
print "argmax:",state3Emit.argmax()
