### 1. Constraints
Constraints are rules enforced on data columns to maintain accuracy and integrity of the data. Common constraints include:

- **PRIMARY KEY**: Ensures each value in a column or a set of columns is unique and not NULL.
- **FOREIGN KEY**: Ensures that a column value matches the primary key in another table.
- **UNIQUE**: Ensures all values in a column are unique.
- **NOT NULL**: Ensures a column cannot have NULL values.
- **CHECK**: Ensures that values meet specific conditions.
- **DEFAULT**: Assigns a default value if none is provided.

```sql
CREATE TABLE Employee (
    EmployeeId INT PRIMARY KEY,
    EmployeeName VARCHAR(50) NOT NULL,
    EmployeeSalary DECIMAL(10, 2) CHECK (EmployeeSalary > 0),
    DepartmentId INT,
    FOREIGN KEY (DepartmentId) REFERENCES Department(DepartmentId)
);
```

### 2. `SELECT` Statement
The `SELECT` statement is used to retrieve data from a database.

```sql
SELECT EmployeeName, EmployeeSalary 
FROM Employee;
```

### 3. `WHERE` Clause
The `WHERE` clause filters records based on a specified condition.

```sql
SELECT EmployeeName, EmployeeSalary 
FROM Employee 
WHERE EmployeeSalary > 50000;
```

### 4. Arithmetic Operators
Used to perform mathematical operations.

- **+** : Addition
- **-** : Subtraction
- **\*** : Multiplication
- **/** : Division
- **%** : Modulus (remainder)

Example:

```sql
SELECT EmployeeName, EmployeeSalary + 5000 AS UpdatedSalary 
FROM Employee;
```

### 5. Comparison Operators
Used to compare two values.

- **=** : Equal
- **<>** or **!=** : Not equal
- **>** : Greater than
- **<** : Less than
- **>=** : Greater than or equal to
- **<=** : Less than or equal to

Example:

```sql
SELECT EmployeeName 
FROM Employee 
WHERE EmployeeSalary >= 60000;
```

### 6. Logical `AND` and `OR` Operators
- **AND**: Returns records if all specified conditions are true.
- **OR**: Returns records if at least one condition is true.

Example:

```sql
SELECT EmployeeName 
FROM Employee 
WHERE EmployeeSalary > 50000 AND DepartmentId = 1;
```

```sql
SELECT EmployeeName 
FROM Employee 
WHERE EmployeeSalary > 70000 OR DepartmentId = 2;
```

### 7. `DISTINCT`, `ORDER BY`, `LIMIT`, and `OFFSET`
- **DISTINCT**: Removes duplicate values from the result set.
- **ORDER BY**: Sorts the result set in ascending (`ASC`) or descending (`DESC`) order.
- **LIMIT**: Limits the number of records returned.
- **OFFSET**: Specifies the number of records to skip before starting to return records.

Example:

```sql
SELECT DISTINCT DepartmentId 
FROM Employee;

SELECT EmployeeName, EmployeeSalary 
FROM Employee 
ORDER BY EmployeeSalary DESC;

SELECT EmployeeName, EmployeeSalary 
FROM Employee 
ORDER BY EmployeeSalary ASC 
LIMIT 5 OFFSET 2;
```

This retrieves distinct department IDs, sorts employees by salary, and retrieves up to 5 records, skipping the first two.