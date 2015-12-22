#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: mediator.py.py
@time: 15/12/22 下午2:06
"""
class Animal:
    def set_status(self, status):
        pass
    def action(self):
        pass

class Lion(Animal):
    def action(self):
        print  self.status
    def set_status(self, status):
        self.status = status

class Rabbit(Animal):
    def action(self):
        print self.status
    def set_status(self, status):
        self.status = status

class Tiger(Animal):
    def action(self):
        print self.status
    def set_status(self, status):
        self.status = status

class Mediator:
    def __init__(self):
        self.aninallist = []
    def addAnimal(self, animal):
        self.aninallist.append(animal)
    def  encounter(self, wonder):
        wonder.action()
        for animal in self.aninallist:
            if animal != wonder:
                animal.action()

if __name__ == '__main__':
    tiger = Tiger()
    lion  = Lion()
    rabbit = Rabbit()
    mediator = Mediator()
    mediator.addAnimal(tiger)
    mediator.addAnimal(rabbit)
    mediator.addAnimal(lion)

    tiger.set_status("tiger,hunter")
    lion.set_status("lion ignore tiger")
    rabbit.set_status("rabbit, run")

    mediator.encounter(tiger)