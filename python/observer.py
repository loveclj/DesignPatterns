__author__ = 'lizhifeng'

class Obersevr:
    def __init__(self, strname, strsub):
        self.name = strname
        self.sub  = strsub

    def update(self):
        pass

class StockOberser(Obersevr):
    def update(self):
        print "%s %s, stop wacthing Stock and go work on" %(self.name, self.sub.action)


class NBAOberser(Obersevr):
    def update(self):
        print "%s %s, stop wacthing NBA and go work on" %(self.name, self.sub.action)

class SecretaryBase:
    def __init__(self):
        self.observer = []

    def attach(self, new_observer):
        pass

    def  notify(self):
        pass

class Sectrary(SecretaryBase):
    def attach(self, new_observer):
        self.observer.append(new_observer)

    def  notify(self):
        for o in self.observer:
            o.update()

if __name__ == "__main__":
    secretory = Sectrary()
    worker1   = StockOberser("jack", secretory)
    worker2   = NBAOberser("tom", secretory)
    secretory.attach(worker1)
    secretory.attach(worker2)

    secretory.action = "Waringn:Boss comes"
    secretory.notify()



