#!/usr/bin/env python
# coding=utf-8

class State:
    def get_state(self):
        pass

class Happy(State):
    def get_state(self):
        print "I am happy"

class Sad(State):
    def get_state(self):
        print "I am sad"

class Person:
    def __init__(self):
        self.state = State()
    def set_state(self, state):
        self.state = state

    def get_person_state(self):
        self.state.get_state()



if __name__ == "__main__":
    happy = Happy()
    sad   = Sad()
    p     = Person()

    p.set_state(happy)
    p.get_person_state()

    p.set_state(sad)
    p.get_person_state()
