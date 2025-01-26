# main.py
from admin import Admin
from customer import Customer
from restaurant import Restaurant

def main():
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
            if admin_name == "Admin":  # Admin authentication
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