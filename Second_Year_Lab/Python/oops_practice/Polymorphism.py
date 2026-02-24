class Dog:
    def sound(self):
        print("Dog Sound")

class Cat:
    def sound(self):
        print("Cat Sound")

class Cow:
    def sound(self):
        print("Cow sound")

animals=[Dog(), Cat(), Cow()]

for animal in animals:
    animal.sound()
