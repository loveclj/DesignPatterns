#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: visitor.pu.py
@time: 15/12/12 下午11:24
"""

class Person:
    def accpect(self, vistor):
        pass

class Man(Person):
    def accpect(self, vistor):
        vistor.get_man_status(self)

    def get_class_name(self):
        print "I'm a man"



class Woman(Person):
    def accpect(self, vistor):
        vistor.get_woman_status(self)
    def get_class_name(self):
        print "I'm a woman"

class Status:
    def get_man_status(self, man):
        pass
    def get_woman_status(self, woman):
        pass

class Happy(Status):
    def get_man_status(self, man):
        man.get_class_name()
    def get_woman_status(self, woman):
        woman.get_class_name()

if __name__ == '__main__':
    happy = Happy()
    man   = Man()
    woman = Woman()

    man.accpect(happy)
    woman.accpect(happy)