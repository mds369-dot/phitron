A **subquery** (also known as an inner query or nested query) is a query within another SQL query. It’s enclosed in parentheses and used to retrieve data that will be processed in the main (outer) query. Subqueries can be used to perform operations like filtering, calculations, or comparisons based on a subset of data.

### Types of Subqueries
1. **Single-row subquery**: Returns only one row, used with operators like `=`, `>`, `<`, etc.
2. **Multiple-row subquery**: Returns multiple rows, used with operators like `IN`, `ANY`, `ALL`, etc.
3. **Correlated subquery**: A subquery that depends on the outer query for its values and is re-executed for each row processed by the outer query.

### Example Scenarios

#### 1. Subquery in the `WHERE` clause
Find employees who earn more than the average salary.
```sql
SELECT employee_id, name
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);
```
In this example, the subquery `(SELECT AVG(salary) FROM employees)` calculates the average salary, and the outer query retrieves employees with a salary above this value.

#### 2. Subquery in the `FROM` clause
Retrieve departments with their average salaries by treating the subquery as a derived table.
```sql
SELECT department_id, AVG(salary) AS average_salary
FROM (SELECT department_id, salary FROM employees) AS dept_salaries
GROUP BY department_id;
```

#### 3. Correlated Subquery
Find employees whose salary is higher than the average salary in their department.
```sql
SELECT employee_id, name, salary
FROM employees e1
WHERE salary > (SELECT AVG(salary) FROM employees e2 WHERE e1.department_id = e2.department_id);
```
Here, the subquery depends on each row of the outer query (`e1`), as it compares each employee's salary to the average salary within their department.

### Common Uses of Subqueries
- **Filtering results** based on data from another table or condition.
- **Calculating aggregated data** like averages, sums, or counts for comparison.
- **Creating temporary tables** for the purpose of the main query.
