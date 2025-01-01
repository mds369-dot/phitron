"""
class Book:
    def __init__(self, book_id, title, author):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.availability = True

"""


class Book:
    def __init__(self, book_id, title, author):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.availability = True

class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)