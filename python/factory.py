__author__ = 'lizhifeng'

class Pizza:
    def cook(self):
        pass

    def cut(self):
        pass

    def get(self):
        pass

class CherryPizza(Pizza):
    def cook(self):
        print "cook cherry pizza"

    def cut(self):
        print  "cut cherry pizza"

    def get(self):
        self.cook()
        self.cut()

class ApplePizza(Pizza):
    def cook(self):
        print "cook apple pizza"
    def cut(self):
        print "cut apple pizza"

    def get(self):
        self.cook()
        self.cut()

class PorkPizza(Pizza):
    def cook(self):
        print "cook pork pizza"
    def cut(self):
        print "cut pork pizza"

    def get(self):
        self.cook()
        self.cut()

class BeefPizza(Pizza):
    def cook(self):
        print "cook  beef pizza"
    def cut(self):
        print "cut beef pizza"

    def get(self):
        self.cook()
        self.cut()


class PizzaStor:
    def orderPizza(self, name):
        pass

class MeatPizzaStore(PizzaStor):
    def orderPizza(self, name):
        if( name == "pork"):
            self.pizza = PorkPizza()


        if( name == "beef"):
            self.pizza = BeefPizza()

        return self.pizza

class FruitPizzaStore(PizzaStor):
    def orderPizza(self, name):
        if( name == "cherry"):
            self.pizza = CherryPizza()


        if( name == "apple"):
            self.pizza = ApplePizza()

        return self.pizza

if __name__ == "__main__":

    storeA = FruitPizzaStore()

    pizzaA = storeA.orderPizza("apple")

    pizzaA.get()