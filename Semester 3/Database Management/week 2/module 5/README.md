
1. **Practice Query**: Refers to practicing SQL queries, usually SELECT statements, where you can retrieve and manipulate data in various ways.

2. **Functions**: SQL functions include built-in functions like string, numeric, date, and aggregate functions. Examples are `UPPER()`, `LOWER()`, `ROUND()`, and `NOW()`.

3. **Group Functions**: These functions, also known as aggregate functions, operate on groups of rows and return a single result per group. Examples include `SUM()`, `COUNT()`, `AVG()`, `MAX()`, and `MIN()`.

4. **GROUP BY, HAVING**: The `GROUP BY` clause groups rows that have the same values in specified columns, often used with aggregate functions. The `HAVING` clause filters groups according to a specified condition, similar to the `WHERE` clause but for grouped data.

5. **ALTER TABLE**: This command modifies an existing table structure by adding, modifying, or deleting columns. For instance, `ALTER TABLE table_name ADD column_name datatype;` adds a new column to the table.

### That Module Practice Query

1. **SELECT**: The basic SQL command to retrieve data from a database. 
   ```sql
   SELECT column1, column2 FROM table_name;
   ```

2. **WHERE**: Filters the results based on specific conditions.
   ```sql
   SELECT column1, column2 FROM table_name WHERE condition;
   ```

3. **Arithmetic Operators**: Used to perform mathematical operations in queries.
   - `+` (Addition)
   - `-` (Subtraction)
   - `*` (Multiplication)
   - `/` (Division)
   - `%` (Modulus)
   ```sql
   SELECT column1 + column2 AS result FROM table_name;
   ```

4. **Comparison Operators**: Compare values in SQL queries.
   - `=` (Equal)
   - `<>` or `!=` (Not equal)
   - `>` (Greater than)
   - `<` (Less than)
   - `>=` (Greater than or equal to)
   - `<=` (Less than or equal to)
   ```sql
   SELECT column1 FROM table_name WHERE column1 > 10;
   ```

5. **Logical AND, OR Operators**: Combine multiple conditions.
   - `AND`: Both conditions must be true.
   - `OR`: At least one condition must be true.
   ```sql
   SELECT column1 FROM table_name WHERE condition1 AND condition2;
   ```

6. **DISTINCT**: Removes duplicate rows in the result set.
   ```sql
   SELECT DISTINCT column1 FROM table_name;
   ```

7. **ORDER BY**: Sorts the results in ascending (`ASC`) or descending (`DESC`) order.
   ```sql
   SELECT column1 FROM table_name ORDER BY column1 DESC;
   ```

8. **LIMIT**: Specifies the number of rows to return.
   ```sql
   SELECT column1 FROM table_name LIMIT 5;
   ```

9. **OFFSET**: Skips a specified number of rows before beginning to return rows.
   ```sql
   SELECT column1 FROM table_name LIMIT 5 OFFSET 10;
   ```

10. **LIKE**: Searches for a specified pattern in a column.
    - `%`: Matches any sequence of characters.
    - `_`: Matches a single character.
    ```sql
    SELECT column1 FROM table_name WHERE column1 LIKE 'A%';
    ```

11. **AS**: Renames a column or table in the result set.
    ```sql
    SELECT column1 AS new_name FROM table_name;
    ```

### SQL functions:

1. **UPPER**: Converts a string to uppercase.
   ```sql
   SELECT UPPER('hello');  -- Result: 'HELLO'
   ```

2. **LOWER**: Converts a string to lowercase.
   ```sql
   SELECT LOWER('HELLO');  -- Result: 'hello'
   ```

3. **ABS**: Returns the absolute value of a number.
   ```sql
   SELECT ABS(-5);  -- Result: 5
   ```

4. **DEGREES**: Converts radians to degrees.
   ```sql
   SELECT DEGREES(PI());  -- Result: 180
   ```

5. **RADIANS**: Converts degrees to radians.
   ```sql
   SELECT RADIANS(180);  -- Result: 3.141593 (approximately PI)
   ```

6. **COS**: Returns the cosine of a given angle in radians.
   ```sql
   SELECT COS(PI() / 3);  -- Result: 0.5
   ```

7. **ACOS**: Returns the arccosine (inverse cosine) of a number.
   ```sql
   SELECT ACOS(0.5);  -- Result: 1.047198 (in radians)
   ```

8. **SIN**: Returns the sine of a given angle in radians.
   ```sql
   SELECT SIN(PI() / 2);  -- Result: 1
   ```

9. **ASIN**: Returns the arcsine (inverse sine) of a number.
   ```sql
   SELECT ASIN(1);  -- Result: 1.5708 (approximately PI/2 in radians)
   ```

10. **TAN**: Returns the tangent of a given angle in radians.
    ```sql
    SELECT TAN(PI() / 4);  -- Result: 1
    ```

11. **ATAN**: Returns the arctangent (inverse tangent) of a number.
    ```sql
    SELECT ATAN(1);  -- Result: 0.785398 (in radians)
    ```

12. **CEIL**: Rounds a number up to the nearest integer.
    ```sql
    SELECT CEIL(2.3);  -- Result: 3
    ```

13. **FLOOR**: Rounds a number down to the nearest integer.
    ```sql
    SELECT FLOOR(2.9);  -- Result: 2
    ```

14. **DIV**: Performs integer division.
    ```sql
    SELECT 10 DIV 3;  -- Result: 3
    ```

15. **EXP**: Returns *e* raised to the power of a given number.
    ```sql
    SELECT EXP(1);  -- Result: 2.718282 (approx. value of e)
    ```

16. **GREATEST**: Returns the largest value from a list.
    ```sql
    SELECT GREATEST(5, 10, 3);  -- Result: 10
    ```

17. **LEAST**: Returns the smallest value from a list.
    ```sql
    SELECT LEAST(5, 10, 3);  -- Result: 3
    ```

18. **LN**: Returns the natural logarithm of a number.
    ```sql
    SELECT LN(2);  -- Result: 0.693147
    ```

19. **LOG**: Returns the natural logarithm (base *e*) or the logarithm of a number with a specific base.
    ```sql
    SELECT LOG(2);        -- Natural log of 2
    SELECT LOG(10, 100);  -- Log of 100 base 10, Result: 2
    ```

20. **LOG10**: Returns the base-10 logarithm of a number.
    ```sql
    SELECT LOG10(1000);  -- Result: 3
    ```

21. **LOG2**: Returns the base-2 logarithm of a number.
    ```sql
    SELECT LOG2(8);  -- Result: 3
    ```

22. **MOD**: Returns the remainder of division.
    ```sql
    SELECT MOD(10, 3);  -- Result: 1
    ```

23. **PI**: Returns the value of PI.
    ```sql
    SELECT PI();  -- Result: 3.141593
    ```

24. **POW**: Raises a number to the power of another number.
    ```sql
    SELECT POW(2, 3);  -- Result: 8
    ```

25. **RAND**: Generates a random number between 0 and 1.
    ```sql
    SELECT RAND();  -- Result: (random number)
    ```

26. **ROUND**: Rounds a number to the nearest integer or specified number of decimal places.
    ```sql
    SELECT ROUND(2.345, 2);  -- Result: 2.35
    ```

27. **SQRT**: Returns the square root of a number.
    ```sql
    SELECT SQRT(16);  -- Result: 4
    ```

28. **TRUNCATE**: Truncates a number to the specified number of decimal places.
    ```sql
    SELECT TRUNCATE(2.345, 1);  -- Result: 2.3
    ```

### MYSQL **Group Functions**

1. **MAX**: Returns the maximum value from a column.
   ```sql
   SELECT MAX(column_name) FROM table_name;
   ```
   - Example: Find the highest salary in an employee table.
     ```sql
     SELECT MAX(salary) FROM employees;
     ```

2. **MIN**: Returns the minimum value from a column.
   ```sql
   SELECT MIN(column_name) FROM table_name;
   ```
   - Example: Find the lowest salary in an employee table.
     ```sql
     SELECT MIN(salary) FROM employees;
     ```

3. **COUNT**: Returns the number of rows that match a specified condition. `COUNT(*)` counts all rows, while `COUNT(column_name)` counts only non-NULL values.
   ```sql
   SELECT COUNT(column_name) FROM table_name;
   ```
   - Example: Count the number of employees in the employee table.
     ```sql
     SELECT COUNT(*) FROM employees;
     ```

4. **SUM**: Calculates the total sum of a numeric column.
   ```sql
   SELECT SUM(column_name) FROM table_name;
   ```
   - Example: Calculate the total sales in a sales table.
     ```sql
     SELECT SUM(sales_amount) FROM sales;
     ```

5. **AVG**: Calculates the average value of a numeric column.
   ```sql
   SELECT AVG(column_name) FROM table_name;
   ```
   - Example: Find the average salary in the employee table.
     ```sql
     SELECT AVG(salary) FROM employees;
     ```

These functions are often used with the `GROUP BY` clause to perform calculations on grouped data. For instance:

```sql
SELECT department_id, AVG(salary)
FROM employees
GROUP BY department_id;
```

### Group By, Having

### 1. Department-Wise Aggregation
Let's say you have an `employees` table with columns `employee_id`, `department_id`, and `salary`. You might want to find the total or average salary in each department.

- **Example**: Calculate the total salary for each department.
   ```sql
   SELECT department_id, SUM(salary) AS total_salary
   FROM employees
   GROUP BY department_id;
   ```

- **Using `HAVING`**: To find departments where the total salary is above a certain threshold (e.g., 100,000).
   ```sql
   SELECT department_id, SUM(salary) AS total_salary
   FROM employees
   GROUP BY department_id
   HAVING total_salary > 100000;
   ```

### 2. Country-Wise Aggregation
Assume you have a `customers` table with columns `customer_id`, `country`, and `sales`. You might want to find the total sales by country.

- **Example**: Calculate the total sales for each country.
   ```sql
   SELECT country, SUM(sales) AS total_sales
   FROM customers
   GROUP BY country;
   ```

- **Using `HAVING`**: To find countries with total sales above a certain threshold (e.g., 500,000).
   ```sql
   SELECT country, SUM(sales) AS total_sales
   FROM customers
   GROUP BY country
   HAVING total_sales > 500000;
   ```

### ALTER TABLE

#### DATABASE: Modifying Data
1. **UPDATE**: Modifies existing records in a table.
   ```sql
   UPDATE table_name
   SET column1 = value1, column2 = value2
   WHERE condition;
   ```
   - **Example**: Update the salary of an employee with `employee_id = 1`.
     ```sql
     UPDATE employees
     SET salary = 50000
     WHERE employee_id = 1;
     ```

2. **DELETE**: Removes records from a table.
   ```sql
   DELETE FROM table_name WHERE condition;
   ```
   - **Example**: Delete an employee record where `employee_id = 1`.
     ```sql
     DELETE FROM employees
     WHERE employee_id = 1;
     ```
   - **Note**: Omitting `WHERE` will delete all records from the table:
     ```sql
     DELETE FROM table_name;
     ```

#### STRUCTURE: Modifying Table Structure
3. **ALTER**: Used to modify the structure of an existing table, such as adding, modifying, or dropping columns.
   - **Add a Column**:
     ```sql
     ALTER TABLE table_name
     ADD column_name datatype;
     ```
     - Example: Add a `phone` column to the `employees` table.
       ```sql
       ALTER TABLE employees
       ADD phone VARCHAR(15);
       ```

   - **Modify a Column**:
     ```sql
     ALTER TABLE table_name
     MODIFY column_name new_datatype;
     ```
     - Example: Change the data type of the `phone` column in the `employees` table.
       ```sql
       ALTER TABLE employees
       MODIFY phone CHAR(10);
       ```

   - **Drop a Column**:
     ```sql
     ALTER TABLE table_name
     DROP COLUMN column_name;
     ```
     - Example: Remove the `phone` column from the `employees` table.
       ```sql
       ALTER TABLE employees
       DROP COLUMN phone;
       ```

4. **DROP**: Used to delete an entire table or database.
   - **Drop a Table**:
     ```sql
     DROP TABLE table_name;
     ```
     - Example: Delete the `employees` table.
       ```sql
       DROP TABLE employees;
       ```

   - **Drop a Database**:
     ```sql
     DROP DATABASE database_name;
     ```
     - Example: Delete a database named `company`.
       ```sql
       DROP DATABASE company;
       ```

