#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: decorator.py.py
@time: 15/12/16 下午11:46
"""
class Compont:
    def display(self):
        print "compont"

class Decorator(Compont):
    def SetCompont(self,co):
        self.compont = co

    def display(self):
        pass

class Window(Decorator):
    def SetCompont(self,co):
        self.compont = co

    def display(self):
        print "Add Window"
        self.compont.display()

class Text(Decorator):
    def SetCompont(self,co):
        self.compont = co

    def display(self):
        print "Add Text"
        self.compont.display()

if __name__ == '__main__':
    compont = Compont()
    text    = Text()
    window  = Window()

    text.SetCompont(compont)
    window.SetCompont(text)
    window.display()