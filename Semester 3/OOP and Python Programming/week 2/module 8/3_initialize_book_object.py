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

book1 = Book(1, "Harun Chacar Nunu Choto ar kahini", "DB Harun")
book2 = Book(2, 'Pita Samu Kahini', "Don Samu")        