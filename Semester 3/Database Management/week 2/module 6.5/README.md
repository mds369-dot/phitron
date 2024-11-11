To answer these questions with SQL, let's assume we have a table `Employees` with the following structure:

| Column         | Type       |
|----------------|------------|
| EmployeeID     | INT        |
| Name           | VARCHAR    |
| Salary         | DECIMAL    |
| HireDate       | DATE       |

We’ll answer each question step-by-step and provide the solution for questions 1 and 2 using a Common Table Expression (CTE).

### Question 1: Determine the third highest salary and which employee receives it

To find the third highest salary, we can use a CTE to rank salaries in descending order.

```sql
WITH RankedSalaries AS (
    SELECT Name, Salary, 
           DENSE_RANK() OVER (ORDER BY Salary DESC) AS SalaryRank
    FROM Employees
)
SELECT Name, Salary
FROM RankedSalaries
WHERE SalaryRank = 3;
```

This query ranks each employee's salary in descending order. The `DENSE_RANK()` function is used to handle duplicate salaries. By filtering `WHERE SalaryRank = 3`, we get the employee(s) with the third highest salary.

### Question 2: Determine the third lowest salary and which employee receives it

To find the third lowest salary, use the same approach but rank salaries in ascending order.

```sql
WITH RankedSalaries AS (
    SELECT Name, Salary, 
           DENSE_RANK() OVER (ORDER BY Salary ASC) AS SalaryRank
    FROM Employees
)
SELECT Name, Salary
FROM RankedSalaries
WHERE SalaryRank = 3;
```

Here, the CTE ranks the employees based on ascending salary, and `WHERE SalaryRank = 3` selects the third lowest salary.

### Question 3: Which employee has been hired after Steven?

To find the employee hired immediately after a specific employee like "Steven," you can use the `HireDate` field to locate employees hired after Steven's `HireDate` and limit the result to the earliest one:

```sql
SELECT Name, HireDate
FROM Employees
WHERE HireDate > (SELECT HireDate FROM Employees WHERE Name = 'Steven')
ORDER BY HireDate
LIMIT 1;
```

This query finds all employees hired after Steven, orders them by `HireDate`, and limits the output to the first result, which represents the employee hired immediately after Steven.