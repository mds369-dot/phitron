Let's go through each question and its solution step-by-step.

### Answer 1: Create Tables

**a.** Create a `Student` table:
```sql
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

```

**b.** Create a `Library` table:
```sql
CREATE TABLE Library
(
	BookID CHAR(4) PRIMARY KEY,
    BookName VARCHAR(100),
    Author VARCHAR(100),
    WhoHired CHAR(4),
    FOREIGN KEY(WhoHired) REFERENCES Student(StudentID)
);
```

**c.** Create a `Fees` table:
```sql
CREATE TABLE Fee
(
	FeeID CHAR(4) PRIMARY KEY,
    WhoGive CHAR(4),
    Amount DECIMAL(10,2) NOT NULL,
    DueDate DATE,
    PaidDate DATE,
    FOREIGN KEY(WhoGive) REFERENCES Student(StudentID)
);
```

### Answer 2: Add Proper Constraints

Add the following constraints:
1. `StudentID` in the `Student` table should be unique and the primary key.
2. `BookID` in the `Library` table should be unique and the primary key.
3. `FeeID` in the `Fees` table should be unique and the primary key.
4. Add a foreign key constraint to ensure `StudentID` in the `Fees` table references `StudentID` in the `Student` table.

### Answer  3: Differences Between Data and Information

**Date :** Date is raw, unprocessed facts without context.

**Information:**  Information is date that has been processed or organized to have meaning and context, making it useful for decision-making.

### Answer 4: Enabling Update and Delete Queries in MySQL

In MySQL, `UPDATE` and `DELETE` queries may not execute if the table is locked or the user lacks the necessary permissions. To ensure `UPDATE` and `DELETE` queries work, make sure the table is not locked and that you have the appropriate privileges.

To enable these features, you can set up foreign key constraints with cascading updates and deletes if required. Here's how to enable foreign key constraints:

```sql
SET FOREIGN_KEY_CHECKS = 0;
SET FOREIGN_KEY_CHECKS = 1;
SET SQL_SAFE_UPDATES = 0;
SET SQL_SAFE_UPDATES = 1;
```

If the queries were failing due to foreign key checks, the above command will ensure that foreign key checks are enabled.

### Answering Queries Using the `Employee` Table

Given the `Employee` table data in your image, here are the solutions to the questions.

### Answer 5: Query to Show Distinct Department Names

```sql
SELECT DISTINCT Department FROM Employee;
```

### Answer 6: Query to Show the Last Names of Employees Sorted by Descending Ages

```sql
SELECT LastName FROM Employee ORDER BY Age DESC;
```

### Answer 7: Query to Show the Last Name of Employees Whose Age is Greater Than 30 and Works in the Marketing Department

```sql
SELECT LastName FROM Employee 
WHERE Age > 30 AND Department = 'Marketing';
```

### Answer 8: Query to Select All Employees

```sql
SELECT * FROM Employee;
```

### Answer 9: Query to Get Employees Whose Names Include 'son'

```sql
SELECT * FROM Employee 
WHERE FirstName LIKE '%son%' OR LastName LIKE '%son%';
```

### Answer 10: Query to Get Employees in the Engineering Department

```sql
SELECT * FROM Employee 
WHERE Department = 'Engineering';
``` 

Let me know if you need further clarification on any of these answers!