#!/usr/bin/env python
# coding=utf-8

class BackUp:
    def __init__(self):
        self.magic = 0
        self.health = 0

class Hero:
    def __init__(self):
        self.magic = 100
        self.health = 100

    def hurt(self, damage):
        self.health -= damage

    def magic_attack(self, magic):
        self.magic -= magic

    def healthup(self, health):
        self.health += health

    def magicup(self, magic):
        self.magic += magic

    def save(self):
        backup = BackUp()
        backup.health = self.health
        backup.magic  = self.magic
        return backup

    def load(self, backup):
        self.magic = backup.magic
        self.health = backup.health

    def show_status(self):
        print "magic : %d" %self.magic
        print "health: %d" %self.health

class Caretaker:
    def __init__(self):
        backup = BackUp()

if __name__ == "__main__":
    hero = Hero()
    caretaker = Caretaker()

    hero.hurt(10)
    hero.magic_attack(20)
    hero.show_status()

    caretaker.backup = hero.save()

    hero.healthup(5)
    hero.magicup(2)

    hero.show_status()

    hero.load(caretaker.backup)

    hero.show_status()





