#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: simpleFactory.py.py
@time: 15/12/13 下午1:57
"""

class Operator:
    def __init__(self):
        self.left  = 0
        self.right = 0
    def compute(self):
        pass

class Sum(Operator):
    def compute(self):
        try:
            return (self.left + self.right)
        except:
            print "[ERROR] check input value"
            return 0

class Sub(Operator):
    def compute(self):
        try:
            return (self.left - self.right)
        except:
            print "[ERROR] check input value"
            return 0

class OperatorFactory:
    def get_operator(self, ch):
        if ch == '+':
            return Sum()

        if ch == '-':
            return Sub()

if __name__ == '__main__':
    factory = OperatorFactory()
    add = factory.get_operator('+')

    add.right = 1
    add.left  = 2

    print add.compute()