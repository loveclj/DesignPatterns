__author__ = 'lizhifeng'

class MangerAbstr:
    def  set_name(self, name):
        pass
    def  response(self, message):
        pass

class ViceManger(MangerAbstr):
    def set_name(self, name):
        self.name = name

    def set_boss(self, boss):
        self.boss = boss

    def response(self, message):
        print "vice manger pass " + message +" to manager"
        self.boss.response(message)


class Manger(MangerAbstr):
    def set_name(self, name):
        self.name = name

    def set_boss(self, boss):
        self.boss = boss

    def response(self, message):
        print "manger print message:"
        print message


if __name__ == "__main__":

    boss = Manger()
    vice = ViceManger()

    vice.set_boss(boss)

    vice.response("hello")