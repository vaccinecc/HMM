# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 10:43:11 2018

@author: LGQ
"""
import numpy

def viterbi(obs,states,start_p,trans_p,emit_p):
    """
    :obs: 观察序列
    :states: 隐藏状态
    :start_p:初始状态（隐）
    :trans_p:转移状态(隐)
    :emit_p:发射概率
    """
    V = [{}]    #路径概率表
    for y in states:    
        V[0][y] = start_p[y] * emit_p[y][obs[0]]
    for t in xrange(1,len(obs)):
        V.append({})
        for y in states:
            V[t][y] = max([(V[t-1][y0] * trans_p[y0][y] * emit_p[y][obs[t]]) for y0 in states])
            result = []
    for vector in V:
        temp = {}
        temp[vector.keys()[argmax(vector.values)]] = max(vector.values())
        result.append(temp)
    return result

states = ('Sunny','Cloudy','Rainy')
obs = ('dry','dryish','soggy')
start_p = {'Sunny':0.63,'Cloudy':0.17,'Rainy':0.20}
trans_p ={
        'Sunny' :{'Sunny':0.5 ,'Cloudy':0.375,'Rainy':0.125},
        'Cloudy':{'Sunny':0.25,'Cloudy':0.125,'Rainy':0.625},
        'Rainy' :{'Sunny':0.25,'Cloudy':0.375,'Rainy':0.375}}
emit_p = {
        'Sunny':{'dry':0.60,'dryish':0.20,'soggy':0.05},
        'Cloudy':{'dry':0.25,'dryish':0.25,'soggy':0.25},
        'Rainy':{'dry':0.05,'dryish':0.10,'soggy':0.50},}
print viterbi(obs,states,start_p,trans_p,emit_p)
