class Shop:
    card = []
    def __init__(self, buyer):
        self.buyer = buyer
    
    def add_to_card(self, item):
        self.card.append(item)

mehzbeeen = Shop('Meh Jabeeen')
mehzbeeen.add_to_card('shoes')
mehzbeeen.add_to_card('phone')
print(mehzbeeen.card)

nisho = Shop('Nesho')
nisho.add_to_card('cap')
nisho.add_to_card('watch')
print(nisho.card)