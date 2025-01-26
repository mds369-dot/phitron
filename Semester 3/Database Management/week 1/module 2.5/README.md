### 1. Difference between Data and Information
- **Data**: Raw, unorganized facts and figures without any context. Data does not have any specific meaning until processed. For example, a list of numbers, such as `25, 34, 45, 50`, is just data.
- **Information**: Processed data that has meaning and context. Information is useful and aids in decision-making. For instance, if the numbers above represent ages, they convey meaningful information about people's ages.

### 2. Primary Key, Composite Primary Key, and Foreign Key
- **Primary Key**: A unique identifier for each record in a table. It must be unique and cannot be NULL. For example, in a `Student` table, `StudentID` can be the primary key, as each student will have a unique ID.
  
- **Composite Primary Key**: A primary key made up of two or more columns to uniquely identify records. For instance, in a `CourseRegistration` table, a composite primary key could be `StudentID` and `CourseID`, as both fields together uniquely identify each course registration.

- **Foreign Key**: A column or a set of columns in one table that references the primary key in another table, creating a link between the two tables. For example, if a `Department` table has `DepartmentID` as the primary key, an `Employee` table can have `DepartmentID` as a foreign key to indicate which department each employee belongs to.

### 3. Five Numeric Data Types in MySQL
1. **INT**: Used for integers.
2. **FLOAT**: Used for floating-point numbers with precision.
3. **DOUBLE**: Used for double-precision floating-point numbers.
4. **DECIMAL(M, D)**: Used for fixed-point numbers, where `M` is the maximum number of digits, and `D` is the number of digits after the decimal point.
5. **BIGINT**: Used for very large integers.

### 4. Create a Table Named `Employee`

#### a. Create Table
```sql
CREATE TABLE Employee (
    EmployeeId INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    EmployeeSalary DECIMAL(10, 2),
    JoiningDate DATE
);
```

#### b. Insert 2 Employee Data
```sql
INSERT INTO Employee (EmployeeId, EmployeeName, EmployeeSalary, JoiningDate) 
VALUES (1, 'John Doe', 50000.00, '2023-06-15');

INSERT INTO Employee (EmployeeId, EmployeeName, EmployeeSalary, JoiningDate) 
VALUES (2, 'Md OPU', 60000.00, '2023-07-28');
```

#### c. Delete 1 Employee Data
```sql
DELETE FROM Employee 
WHERE EmployeeId = 1;
```

This script creates an `Employee` table, inserts two records, and then deletes one record based on the `EmployeeId`.