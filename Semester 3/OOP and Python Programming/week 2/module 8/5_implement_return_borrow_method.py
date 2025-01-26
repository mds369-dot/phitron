class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)

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


book1 = Book(1, "Harun Cachar Nunu Choto er Kahini", "DB Harun")
book1.borrow_book()
book1.borrow_book()
book1.return_book()
book1.borrow_book()
