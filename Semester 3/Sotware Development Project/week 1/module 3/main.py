class Customer:
    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
        self.balance = 0
        self.order_history = []

    def view_menu(self, menu):
        """Displays the restaurant's menu to the customer."""
        print("\n--- Restaurant Menu ---")
        for item, price in menu.items():
            print(f"{item}: ${price:.2f}")

    def place_order(self, menu):
        """Allows the customer to place an order from the menu."""
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
        """Displays the details of the current order."""
        print("\n--- Your Order ---")
        for item, quantity in order.items():
            print(f"{item} x{quantity}")
        print(f"Total cost: ${total_cost:.2f}")
        print(f"Remaining balance: ${self.balance:.2f}")

    def check_balance(self):
        """Displays the customer's current balance."""
        print(f"\nYour current balance is: ${self.balance:.2f}")

    def view_past_orders(self):
        """Displays a list of the customer's past orders."""
        if self.order_history:
            print("\n--- Past Orders ---")
            for i, order in enumerate(self.order_history):
                print(f"\nOrder {i+1}:")
                for item, quantity in order.items():
                    print(f"{item} x{quantity}")
        else:
            print("\nNo past orders found.")

    def add_funds(self):
        """Allows the customer to add funds to their balance."""
        amount = float(input("\nEnter the amount to add: $"))
        self.balance += amount
        print(f"\nFunds added successfully! Your new balance is: ${self.balance:.2f}")


class Admin:
    def __init__(self):
        self.menu = {}
        self.customers = []

    def create_menu(self):
        """Allows the admin to create the initial menu."""
        while True:
            item = input("\nEnter item name (or 'done' to finish): ")
            if item.lower() == 'done':
                break
            try:
                price = float(input("Enter item price: $"))
                self.menu[item] = price
            except ValueError:
                print("Invalid price. Please enter a numeric value.")

    def manage_menu(self):
        """Allows the admin to add, remove, or modify items in the menu."""
        while True:
            print("\n--- Menu Management ---")
            print("1. Add item")
            print("2. Remove item")
            print("3. Modify item price")
            print("4. Back")
            choice = input("\nEnter your choice: ")

            if choice == '1':
                item = input("Enter item name: ")
                try:
                    price = float(input("Enter item price: $"))
                    self.menu[item] = price
                    print(f"{item} added to the menu.")
                except ValueError:
                    print("Invalid price. Please enter a numeric value.")
            elif choice == '2':
                item = input("Enter item name to remove: ")
                if item in self.menu:
                    del self.menu[item]
                    print(f"{item} removed from the menu.")
                else:
                    print("Item not found in the menu.")
            elif choice == '3':
                item = input("Enter item name to modify: ")
                if item in self.menu:
                    try:
                        new_price = float(input("Enter new price: $"))
                        self.menu[item] = new_price
                        print(f"Price for {item} updated.")
                    except ValueError:
                        print("Invalid price. Please enter a numeric value.")
                else:
                    print("Item not found in the menu.")
            elif choice == '4':
                break
            else:
                print("Invalid choice.")

    def add_customer(self):
        """Allows the admin to add a new customer account."""
        name = input("\nEnter customer name: ")
        email = input("Enter customer email: ")
        address = input("Enter customer address: ")
        customer = Customer(name, email, address)
        self.customers.append(customer)
        print(f"\nCustomer {name} added successfully!")

    def view_customers(self):
        """Displays a list of all registered customers."""
        if self.customers:
            print("\n--- Registered Customers ---")
            for customer in self.customers:
                print(f"Name: {customer.name}, Email: {customer.email}, Address: {customer.address}")
        else:
            print("\nNo customers found.")

    def remove_customer(self):
        """Allows the admin to remove a customer account."""
        email = input("\nEnter customer email to remove: ")
        for customer in self.customers:
            if customer.email == email:
                self.customers.remove(customer)
                print(f"\nCustomer with email {email} removed successfully!")
                return
        print("\nCustomer not found.")


class Restaurant:
    def __init__(self):
        self.menu = {}
        self.customers = []

    def set_menu(self, menu):
        """Sets the restaurant's menu."""
        self.menu = menu

    def get_menu(self):
        """Returns the restaurant's menu."""
        return self.menu

    def add_customer(self, customer):
        """Adds a customer to the restaurant's customer list."""
        self.customers.append(customer)

    def remove_customer(self, customer):
        """Removes a customer from the restaurant's customer list."""
        if customer in self.customers:
            self.customers.remove(customer)

    def show_menu(self):
        """Displays the restaurant's menu."""
        if self.menu:
            print("\n--- Restaurant Menu ---")
            for item, price in self.menu.items():
                print(f"{item}: ${price:.2f}")
        else:
            print("\nMenu is currently empty.")

    def check_customer_details(self, email):
        """Displays the details of a customer based on their email."""
        for customer in self.customers:
            if customer.email == email:
                print(f"\nCustomer Details:\nName: {customer.name}\nEmail: {customer.email}\nAddress: {customer.address}")
                return
        print("\nCustomer not found.")


def main():
    """Main function to run the restaurant management system."""
    restaurant = Restaurant()
    admin = Admin()

    while True:
        print("\n--- Restaurant Management System ---")
        print("1. Admin Login")
        print("2. Customer Login")
        print("3. Exit")
        choice = input("Select an option: ")

        if choice == '1':
            admin_name = input("Enter Admin Name: ")
            if admin_name == "Admin":  # Basic admin authentication
                print(f"\nWelcome Admin {admin_name}")

                while True:
                    print("\n--- Admin Menu ---")
                    print("1. Create Customer Account")
                    print("2. Remove Customer Account")
                    print("3. View All Customers")
                    print("4. Manage Restaurant Menu")
                    print("5. Exit")
                    admin_choice = input("Select an option: ")

                    if admin_choice == '1':
                        admin.add_customer()
                    elif admin_choice == '2':
                        admin.remove_customer()
                    elif admin_choice == '3':
                        admin.view_customers()
                    elif admin_choice == '4':
                        if not admin.menu:
                            admin.create_menu()
                            restaurant.set_menu(admin.menu)
                        else:
                            admin.manage_menu()
                    elif admin_choice == '5':
                        break
                    else:
                        print("Invalid choice.")

            else:
                print("Invalid Admin Name.")

        elif choice == '2':
            customer_name = input("Enter Customer Username: ")
            customer = None
            for c in admin.customers:
                if c.name == customer_name:
                    customer = c
                    break

            if customer:
                print(f"\n--- {customer_name}'s Menu ---")
                while True:
                    print("\n1. View Restaurant Menu")
                    print("2. View Balance")
                    print("3. Add Balance")
                    print("4. Place Order")
                    print("5. View Past Orders")
                    print("6. Exit")
                    customer_choice = input("Select an option: ")

                    if customer_choice == '1':
                        customer.view_menu(restaurant.get_menu())
                    elif customer_choice == '2':
                        customer.check_balance()
                    elif customer_choice == '3':
                        customer.add_funds()
                    elif customer_choice == '4':
                        customer.place_order(restaurant.get_menu())
                    elif customer_choice == '5':
                        customer.view_past_orders()
                    elif customer_choice == '6':
                        break
                    else:
                        print("Invalid choice.")
            else:
                print("Customer not found.")

        elif choice == '3':
            print("Exiting the system...")
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()