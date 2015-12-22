#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: interpreter.py.py
@time: 15/12/22 下午6:01
"""
class Context:
    def __init__(self):
        self.vale = 0
    def get(self):
        print "value is: %d" %self.vale

class AbstrExpression:
    def interpreter(self, context):
        pass
class AddExpression(AbstrExpression):
    def interpreter(self, context):
        context.vale += 1
class SubExpression(AbstrExpression):
    def interpreter(self, context):
        context.vale -= 1

if __name__ == '__main__':
    expressionList = []
    add1 = AddExpression()
    add2 = AddExpression()
    add3 = AddExpression()
    sub1 = SubExpression()
    sub2 = SubExpression()

    expressionList.append(add1)
    expressionList.append(add2)
    expressionList.append(sub1)
    expressionList.append(add3)
    expressionList.append(sub2)
    
    context = Context()
    for expression in expressionList:
        expression.interpreter(context)
        context.get()

