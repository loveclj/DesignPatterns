#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: bridge.py.py
@time: 15/12/22 下午3:20
"""

class Machine:
    def action(self):
        pass

class Computer(Machine):
    def action(self):
        print "this is a computer"

class Phone(Machine):
    def action(self):
        print "tis is a phone"

class Person:
    def __init__(self, machine):
        pass
    def useMachine(self):
        pass
class Man(Person):
    def __init__(self, machine):
        self.machine =  machine
    def useMachine(self):
        self.machine.action()
        print "i am  a man, i use it"

class Woman(Person):
    def __init__(self, machine):
        self.machine =  machine
    def useMachine(self):
        self.machine.action()
        print "i am a woman, i use it"

if __name__ == '__main__':
    computer = Computer()
    phone    = Phone()
    man      = Man(computer)
    woman    = Woman(phone)

    man.useMachine()
    woman.useMachine()