
class Book:
    def __init__(self, book_id, title, author):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.availability = True
        Library.entry_book(self)

    def borrow_book(self):
        if self.availability:
            self.availability = False
            print(f"{self.title} has been brrowed. ")
        else:
            print(f"{self.title} is not available for borrowing. ")
    
    def return_book(self):
        if not self.availability:
            self.availability = True
            print(f"{self.title} has been returned.")
        else:
            print(f"{self.title} was not borrowed")
    
    def view_book_info(self):
        print("Book er tottho: ")
        print(f"  Book ID: {self.book_id}")
        print(f"  Title: {self.title}")
        print(f"  Author: {self.author}")
        print(f"  Availability: {'Available' if self.availability else 'Borrowed'}")

class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)

    @classmethod
    def view_all_books(cls):
        if not cls.book_list:
            print("No books in the library yet.")
        else:
            for book in cls.book_list:
                book.view_book_info()
                print("---")

while True:
    print("\nLibrary Menu:")
    print("1. View All Books")
    print("2. Borrow Book")
    print("3. Return Book")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        Library.view_all_books()
    elif choice == '2':
        book_id = int(input("Enter the book ID to borrow: "))
        for book in Library.book_list:
            if book.book_id == book_id:
                book.borrow_book()
                break
        else:
            print("Book not found.")
    elif choice == '3':
        book_id = int(input("Enter the book ID to return: "))
        for book in Library.book_list:
            if book.book_id == book_id:
                book.return_book()
                break
        else:
            print("Book not found.")
    elif choice == '4':
        print("Exiting the library system.")
        break
    else:
        print("Invalid choice. Please try again.")

