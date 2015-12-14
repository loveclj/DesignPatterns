__author__ = 'lizhifeng'

class Strategy:
    def __init__(self):
        self.element = 0

    def set_element(self, value):
        self.element = value

    def get_result(self):
        pass

class StrategyA(Strategy):
    def get_result(self, value):
        self.set_element(value)
        return (self.element * self.element)

class StrategyB(Strategy):
    def get_result(self,value):
        self.set_element(value)
        return (self.element * 2)

class Result:
    def print_result(self,value):
        result = self.strategy.get_result(value)
        print result


if __name__ == "__main__":
    rlt = Result()
    strategyA = StrategyA()
    strategyB = StrategyB()

    rlt.strategy = strategyA

    rlt.print_result(2)

































