__author__ = 'lizhifeng'

class ProtoType:
    def __init__(self):
        pass

    def clone(self):
        pass

    def display(self):
        print self.name
        print self.age


class ConcreteA(ProtoType):

    def  set_name(self,name):
        self.name = name

    def  set_age(self,age):
        self.age  = age

    def clone(self):
        self.copy = ProtoType()
        self.copy.name = self.name
        self.copy.age  = self.age

    def display(self):
        print self.name
        print self.age

class ConcreteA(ProtoType):

    def  set_name(self,name):
        self.name = name

    def  set_age(self,age):
        self.age  = age

    def clone(self):
        self.copy = ProtoType()
        self.copy.name = self.name
        self.copy.age  = self.age
        return self.copy

    def display(self):
        print self.name
        print self.age


class ConcreteB(ProtoType):

    def  set_name(self,name):
        self.name = name

    def  set_age(self,age):
        self.age  = age

    def clone(self):
        self.copy = ProtoType()
        self.copy.name = self.name
        self.copy.age  = self.age
        return self.copy

    def display(self):
        print self.name
        print self.age

if __name__ == "__main__":
    ca = ConcreteA()
    ca.set_age(10)
    ca.set_name("lucy")

    cp = ca.clone()

    cp.display()