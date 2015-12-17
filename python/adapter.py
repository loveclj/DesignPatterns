#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: adapter.py.py
@time: 15/12/16 下午11:15
"""
class Target:
    def  PrintAnimalName(self):
        print "dog, pig, cat"

class Adaptee:
    def PrintFishName(self):
        print "shark， tropical fish"

class Adapter(Target):
    def __init__(self):
        self.adaptee = Adaptee()
    def PrintAnimalName(self):
        self.adaptee.PrintFishName()

if __name__ == '__main__':
    adapter = Adapter()
    adapter.PrintAnimalName()

    target = Target()
    target.PrintAnimalName()