# poly --> many (multiple)
# morph --> shape

class Animal:
    def __init__(self, name) -> None:
        self.name = name

    def make_sound(self):
        print('animal making some sound')

class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)      
    def make_sound(self):
        print('meow meow')
class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)
    
    def make_sound(self):
        print('gheu ghew')
class Goat(Animal):
    def __init__(self, name):
        super().__init__(name)
    
    def make_sound(self):
        print('beh beh beh')

don = Cat('Real Don')
don.make_sound()  

shapard = Dog('Local Shaphard')
shapard.make_sound()

mess = Goat('L M')
mess.make_sound()

less = Goat('gora gori')
less.make_sound()

animals = [don, shapard, mess]
for animal in animals:
    animal.make_sound()