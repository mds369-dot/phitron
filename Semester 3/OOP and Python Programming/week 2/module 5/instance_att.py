class Shop:
    shopping_mall = 'Jamuna'
    def __init__(self, buyer):
        self.buyer = buyer
        self.cart = [] # instance attributes

    def add_to_cart(self, item):
        self.cart.append(item)

mehajabeen = Shop('Mez Jab een')
mehajabeen.add_to_cart('shoes')
mehajabeen.add_to_cart('phone')

print(mehajabeen.cart)

nisho = Shop('Nisho night er nisho')
nisho.add_to_cart('hat')
nisho.add_to_cart('watch')
print(nisho.cart)

apurvo = Shop('age purbo chilo')
apurvo.add_to_cart('Churini')
print(apurvo.cart)