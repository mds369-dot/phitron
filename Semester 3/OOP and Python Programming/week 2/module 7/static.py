class Shopping:
    # staic attribute (class attributes)
    
    cart = [] # class attribute # static attribute
    origin = 'china'

    def __init__(self, name, locaiton) -> None:
        self.name = 'Jamu na city'
        self.location = 'Jam er maj khane'

    def purchase(self, item, price, amount):
        remaining = amount - price
        print(f'buying: {item} for price: {price} and remaining: {remaining}')
    @classmethod
    def muliply(self, a, b):
        # print(self.name)
        result = a + b
        print(result)
    @classmethod
    def hudai_dekhi(self, item):
        print('hudai dekhi kintu kinmu just ac er hawa khatas ashi', item)

bashundara = Shopping('basu en dhara', 'not poular location')
# bashundara.purchase('lunghi', 500, 1000)
bashundara.hudai_dekhi('lunghi')

# Shopping.purchase(2, 3, 3)
Shopping.hudai_dekhi('Lunghi')

Shopping.muliply(2, 3)