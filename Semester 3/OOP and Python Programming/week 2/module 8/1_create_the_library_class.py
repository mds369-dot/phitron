class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)
    
    
class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author

