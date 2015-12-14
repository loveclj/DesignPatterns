__author__ = 'lizhifeng'

class Paper:
    def __init__(self):
        self.answerA = ""
        self.answerB = ""
    def questionA(self):
        print "Who is Mao"

    def questionB(self):
        print "Which is big, cat or dog?"



class PaperA(Paper):
    def __init__(self):
        self.answerA = "chairman mao"
        self.answerB = "dog"
    def answerQuestionA(self):
        self.questionA()
        print self.answerA

    def answerQuestionB(self):
        self.questionB()
        print self.answerB

    def answer(self):
        self.answerQuestionA()
        self.answerQuestionB()


class PaperB(Paper):
    def __init__(self):
        self.answerA = "i don't know"
        self.answerB = "cat"
    def answerQuestionA(self):
        self.questionA()
        print self.answerA

    def answerQuestionB(self):
        self.questionB()
        print self.answerB


    def answer(self):
        self.answerQuestionA()
        self.answerQuestionB()


if __name__ == "__main__":
    studentA = PaperA()
    studentB = PaperB()
    studentA.answer()
    studentB.answer()