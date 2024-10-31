USE stu_and_lib;
CREATE TABLE students
(
	Roll Char(4),
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(60),
    Address VARCHAR(255),
    Age INT,
    Constraint pk_rule PRIMARY KEY(Roll),
    Constraint unique_rule UNIQUE(Email),
    Constraint checking_rule CHECK(Age > 10)
);

CREATE TABLE Library
(
	BookName VARCHAR(50),
    WhoHired_Roll CHAR(4),
    FOREIGN KEY(WhoHired_Roll) REFERENCES students(Roll)
);
INSERT INTO students(Roll, Name, Email, Address, Age) VALUES('0001', 'Opu', 'opusazi@gmail.com', 'Uttora, Dhaka', 18);
INSERT INTO students(Roll, Name, Email, Address, Age) VALUES('0002', 'Md Opu', 'mdopusazi@gmail.com', 'Uttora, Dhaka', 22);

CREATE TABLE Course
(
	CourseName VARCHAR(10),
    University VARCHAR(10),
    Cradit INT,
    PRIMARY KEY(CourseName, University)
    
);

to show data (SELECT* for all or Only one or other SELECT Email or 'Date Name')--

SELECT *
FROM students;

SELECT Name, Email
FROM students;

