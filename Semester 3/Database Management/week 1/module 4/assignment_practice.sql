CREATE DATABASE STUDENT_INFO;
Use student_info;
CREATE TABLE Student
(
	StudentID CHAR(4) PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50),
    EMail VARCHAR(60),
    Age INT,
    Class VARCHAR(20),
    CONSTRAINT ch_mail UNIQUE(EMail),
    CONSTRAINT ck_age CHECK(Age <10)
);

CREATE TABLE Library
(
	BookID CHAR(4) PRIMARY KEY,
    BookName VARCHAR(100),
    Author VARCHAR(100),
    WhoHired CHAR(4),
    FOREIGN KEY(WhoHired) REFERENCES Student(StudentID)
);

CREATE TABLE Fee
(
	FeeID CHAR(4) PRIMARY KEY,
    WhoGive CHAR(4),
    Amount DECIMAL(10,2) NOT NULL,
    DueDate DATE,
    PaidDate DATE,
    FOREIGN KEY(WhoGive) REFERENCES Student(StudentID)
);