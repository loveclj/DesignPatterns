#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: composite.py.py
@time: 15/12/22 下午5:25
"""

class Compont:
    def __init__(self, name):
        self.name = name
    def  add(self, com):
        pass
    def display(self, depth):
        pass

class Leaf(Compont):
    def add(self, com):
        print "[Error] leaf can't add anything"
    def display(self, depth):
        for i in range(depth):
            print "-",
        print self.name

class ConcreteCompont(Compont):
    def __init__(self,name):
        self.name = name
        self.comList = []
    def add(self, com):
        self.comList.append(com)
    def display(self, depth):
        line = ""
        print self.name
        for i in range(depth):
            line += "-"
        for com in self.comList:
            print line,
            print com.name




if __name__ == '__main__':
    leafa = Leaf("txt")
    leafb = Leaf("rmvb")
    doca  = ConcreteCompont("foldera")
    doc   = ConcreteCompont("top")
    doc.add(leafa)
    doc.add(leafb)
    doc.add(doca)

    doc.display(2)