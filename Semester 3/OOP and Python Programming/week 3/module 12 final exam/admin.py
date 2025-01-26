# admin.py
from customer import Customer
class Admin:
    def __init__(self):
        self.menu = {}
        self.customers = []

    def create_menu(self):
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
        name = input("\nEnter customer name: ")
        email = input("Enter customer email: ")
        address = input("Enter customer address: ")
        customer = Customer(name, email, address)
        self.customers.append(customer)
        print(f"\nCustomer {name} added successfully!")

    def view_customers(self):
        if self.customers:
            print("\n--- Registered Customers ---")
            for customer in self.customers:
                print(f"Name: {customer.name}, Email: {customer.email}, Address: {customer.address}")
        else:
            print("\nNo customers found.")

    def remove_customer(self):
        email = input("\nEnter customer email to remove: ")
        for customer in self.customers:
            if customer.email == email:
                self.customers.remove(customer)
                print(f"\nCustomer with email {email} removed successfully!")
                return
        print("\nCustomer not found.")