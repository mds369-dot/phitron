### 1. Creating the `Employee` Table with Constraints

The table includes the following fields with constraints:
- `EmpId`: Primary key for unique identification of employees.
- `EmpName`: Name of the employee, required field.
- `JoiningYear`: Year the employee joined.
- `Birthday`: Date of birth with a constraint to ensure it’s not after the year 2000.
- `Designation`: Job designation/title.
- `Salary`: Employee salary with a non-negative constraint.

Here’s the SQL code to create the `Employee` table with these constraints:

```sql
CREATE TABLE Employee (
    EmpId INT PRIMARY KEY,                            -- Unique identifier for each employee
    EmpName VARCHAR(100) NOT NULL,                    -- Employee name, cannot be NULL
    JoiningYear YEAR NOT NULL,                        -- Year of joining, cannot be NULL
    Birthday DATE CHECK (Birthday <= '2000-12-31'),   -- Birthday must be on or before December 31, 2000
    Designation VARCHAR(50) NOT NULL,                 -- Designation, cannot be NULL
    Salary DECIMAL(10, 2) CHECK (Salary >= 0)         -- Salary with a non-negative constraint
);
```

### 2. Creating a Composite Primary Key Constraint

A **composite primary key** involves combining two or more columns to create a unique key. Here’s an example of how to create a table with a composite primary key.

Let’s say we have a table `ProjectAssignment` where each employee can be assigned multiple projects, and each project can have multiple employees. The combination of `EmpId` and `ProjectId` should be unique, so we can set a composite primary key using both fields.

```sql
CREATE TABLE ProjectAssignment (
    EmpId INT,
    ProjectId INT,
    AssignmentDate DATE,
    PRIMARY KEY (EmpId, ProjectId)   -- Composite primary key using EmpId and ProjectId
);
```

In this example, the combination of `EmpId` and `ProjectId` is unique for each record in the `ProjectAssignment` table.

### 3. Using `LIMIT` for Pagination Without `OFFSET`

In MySQL, the `LIMIT` clause can be used alone to restrict the number of rows returned. However, `LIMIT` with an `OFFSET` is typically used for pagination (e.g., `LIMIT 10 OFFSET 20` returns 10 rows, skipping the first 20). 

To achieve a similar effect using only `LIMIT`, you can use a subquery. Here’s an example:

```sql
SELECT * 
FROM Employee 
ORDER BY EmpId 
LIMIT 10, 10;   -- This skips the first 10 records and returns the next 10
```

When using `LIMIT X, Y` syntax:
- `X` is the number of rows to skip.
- `Y` is the number of rows to retrieve.

Therefore, `LIMIT X, Y` effectively combines the `LIMIT` and `OFFSET` functionality.