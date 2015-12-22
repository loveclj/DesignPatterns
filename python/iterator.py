#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: iterator.py.py
@time: 15/12/16 下午11:14
"""
class Iterator:
    def next(self):
        pass
    def pre(self):
        pass
    def current(self):
        pass
    def count(self):
        pass
    def isdone(self):
        pass

class Aggregate:
    pass

class ConcreteAggregate(Aggregate):
    def __init__(self):
        self.student = []

class ConreteIterator(Iterator):
    def __init__(self, concreteAggregate):
        self.student =  concreteAggregate.student
        self.id = 0

    def first(self):
        print self.student[0]

    def next(self):
        if self.id < len(self.student) -1:
            self.id += 1
            print self.student[self.id]
        else:
            print "end of list"

    def pre(self):
        if self.id > 0:
            self.id -= 1
            print self.student[self.id]
        else:
            print "first of list"

    def isdone(self):
        if self.id == len(self.student) - 1:
            return True
        else:
            return False

    def count(self):
        return len(self.student)

    def current(self):
        print self.student[self.id]

if __name__ == "__main__":
    concrete = ConcreteAggregate()
    concrete.student.append("jack")
    concrete.student.append("lucy")
    concrete.student.append("mike")
    concrete.student.append("lily")

    iterator = ConreteIterator(concrete)
    iterator.next()
    iterator.next()
    iterator.next()
    iterator.count()
    iterator.next()
    iterator.next()


