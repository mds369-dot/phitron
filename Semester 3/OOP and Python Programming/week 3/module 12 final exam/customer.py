# customer.py
class Customer:
    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
        self.balance = 0
        self.order_history = []

    def view_menu(self, menu):
        print("\n--- Restaurant Menu ---")
        for item, price in menu.items():
            print(f"{item}: ${price:.2f}")

    def place_order(self, menu):
        self.view_menu(menu)
        order = {}
        while True:
            item = input("\nEnter the item you want to order (or 'done' to finish): ")
            if item.lower() == 'done':
                break
            if item in menu:
                quantity = int(input("Enter quantity: "))
                order[item] = quantity
            else:
                print("Item not found in the menu.")

        total_cost = sum(menu[item] * quantity for item, quantity in order.items())
        if total_cost <= self.balance:
            self.balance -= total_cost
            self.order_history.append(order)
            print("\nOrder placed successfully!")
            self.view_order(order, total_cost)
        else:
            print("\nInsufficient balance. Please add funds to your account.")

    def view_order(self, order, total_cost):
        print("\n--- Your Order ---")
        for item, quantity in order.items():
            print(f"{item} x{quantity}")
        print(f"Total cost: ${total_cost:.2f}")
        print(f"Remaining balance: ${self.balance:.2f}")

    def check_balance(self):
        print(f"\nYour current balance is: ${self.balance:.2f}")

    def view_past_orders(self):
        if self.order_history:
            print("\n--- Past Orders ---")
            for i, order in enumerate(self.order_history):
                print(f"\nOrder {i+1}:")
                for item, quantity in order.items():
                    print(f"{item} x{quantity}")
        else:
            print("\nNo past orders found.")

    def add_funds(self):
        amount = float(input("\nEnter the amount to add: $"))
        self.balance += amount
        print(f"\nFunds added successfully! Your new balance is: ${self.balance:.2f}")