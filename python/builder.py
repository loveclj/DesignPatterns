__author__ = 'lizhifeng'


class Actor:
    def __init__(self):
        self.name = ""
        self.sex  = ""
        self.age  = 0

    def set_name(self, name):
        self.name = name

    def set_sex(self,sex):
        self.sex  = sex

    def set_age(self,age):
        self.age  = age

    def show(self):
        print "name :" + self.name
        print "age  :%d"  %self.age
        print "sex  :" + self.sex


class Builder:
    def __init__(self):
        self.actor = Actor()

    def SetName(self):
        pass

    def SetSex(self):
        pass

    def SetAge(self):
        pass

    def GetActor(self):
        pass

class  BuilderA(Builder):
    def SetName(self):
        self.actor.set_name("Lili")

    def SetAge(self):
        self.actor.set_age(17)

    def SetSex(self):
        self.actor.set_sex("female")

    def GetActor(self):
        return  self.actor

class  BuilderB(Builder):
    def SetName(self):
        self.actor.set_name("James")

    def SetAge(self):
        self.actor.set_age(20)

    def SetSex(self):
        self.actor.set_sex("male")

    def GetActor(self):
        return  self.actor


class Director:
    def construct(self, builder):
        builder.SetAge()
        builder.SetName()
        builder.SetSex()

if __name__ == "__main__":
    builderA = BuilderA()
    builderB = BuilderB()
    director = Director()

    director.construct(builderA)
    actor =  builderA.GetActor()
    actor.show()

    director.construct(builderB)
    actor =  builderB.GetActor()
    actor.show()