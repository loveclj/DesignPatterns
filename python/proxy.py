#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: proxy.py.py
@time: 15/12/18 上午8:17
"""
class Abstract:
    def GetName(self):
        pass

class Remote(Abstract):
    def GetName(self):
        print "Remote"

class Proxy(Abstract):
    def __init__(self):
        self.remote = Remote()

    def GetName(self):
        self.remote.GetName()

if __name__ == '__main__':
    proxy = Proxy()
    proxy.GetName()