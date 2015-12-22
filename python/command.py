#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: command.py.py
@time: 15/12/22 下午1:27
"""

class Brucer:
    def makeMutton(self):
        print "cook mutton"
    def makeChicken(self):
        print "cook chicken"

class Command:
    def make(self):
        pass

class OrderChicken(Command):
    def __init__(self, brucer):
        self.brucer = brucer
    def make(self):
        self.brucer.makeChicken()

class OrderMutton(Command):
    def __init__(self, brucer):
        self.brucer = brucer
    def make(self):
        self.brucer.makeMutton()

class Waiter:
    def __init__(self):
        self.orderlist = []
    def addorder(self, order):
        self.orderlist.append(order)
    def notify(self):
        for order in self.orderlist:
            order.make()

if __name__ == '__main__':
    waiter = Waiter()
    brucer = Brucer()
    orderChicken = OrderChicken(brucer)
    orderMutton  = OrderMutton(brucer)
    waiter.addorder(orderChicken)
    waiter.addorder(orderMutton)
    waiter.notify()