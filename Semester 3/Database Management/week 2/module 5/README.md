
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

