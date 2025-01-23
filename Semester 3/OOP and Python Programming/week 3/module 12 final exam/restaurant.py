# restaurant.py
class Restaurant:
    def __init__(self):
        self.menu = {}
        self.customers = []

    def set_menu(self, menu):
        self.menu = menu

    def get_menu(self):
        return self.menu

    def add_customer(self, customer):
        self.customers.append(customer)

    def remove_customer(self, customer):
        if customer in self.customers:
            self.customers.remove(customer)

    def show_menu(self):
        if self.menu:
            print("\n--- Restaurant Menu ---")
            for item, price in self.menu.items():
                print(f"{item}: ${price:.2f}")
        else:
            print("\nMenu is currently empty.")

    def check_customer_details(self, email):
        for customer in self.customers:
            if customer.email == email:
                print(f"\nCustomer Details:\nName: {customer.name}\nEmail: {customer.email}\nAddress: {customer.address}")
                return
        print("\nCustomer not found.")