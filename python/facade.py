#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: facade.py.py
@time: 15/12/16 下午10:57
"""

class Wash:
    def wash_veg(self):
        print "wash vegetales"

    def wash_meat(self):
        print "wash meat"

class Cook:
    def cook_veg(self):
        print "cook veg"
    def cook_meat(self):
        print "cook meat"

class Deliver:
    def deliver(self):
        print "deliver to client"

class Facade:
    def __init__(self):
        self.cook = Cook()
        self.wash = Wash()
        self.deliver = Deliver()

    def GetMeat(self):
        self.wash.wash_meat()
        self.cook.cook_meat()
        self.deliver.deliver()

    def GetVeg(self):
        self.wash.wash_veg()
        self.cook.cook_veg()
        self.deliver.deliver()

if __name__ == '__main__':

    facade = Facade()

    facade.GetMeat()
    facade.GetVeg()
