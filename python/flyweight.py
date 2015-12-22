#!/usr/bin/env python
# encoding: utf-8

"""
@version: 1.0
@author: lizhifeng
@license: no 
@contact: lizhifeng2009@126.com
@site: 
@software: PyCharm Community Edition
@file: flyweight.py.py
@time: 15/12/22 下午9:50
"""
class WebSite:
    def __init__(self, name):
        pass
    def get_username(self, username):
        pass
class ConcreteWebSite(WebSite):
    def __init__(self, name):
        self.website_name = name
    def get_username(self, username):
        print username

class UnsharedWebSite(WebSite):
    def __init__(self, name):
        self.website_name =  name
    def get_username(self, username):
        print username

class WebsiteFactory:
    def __init__(self):
        self.websites = {}
        self.count    = {}
        self.websites["test"] = ConcreteWebSite("test")
        self.count["test"] = 1

    def get_website(self, name):
        if name not in self.websites.keys():
            self.websites[name] = ConcreteWebSite(name)
            self.count[name]  = 1
        else:
            self.count[name]  += 1

        return  self.websites[name]

    def display(self):
        for key in self.websites.keys():
            print "%s : %d" %(key, self.count[key])

if __name__ == '__main__':
    factory = WebsiteFactory()
    blog1 = factory.get_website("blog")
    blog1.get_username("jay")
    blog2 = factory.get_website("blog")
    blog2.get_username("Jane")
    print blog1 == blog2
    factory.get_website("info")
    factory.get_website("abstract")
    factory.display()