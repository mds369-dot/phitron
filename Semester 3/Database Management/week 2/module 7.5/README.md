

Questions

1. Show the employee names and corresponding job_titles without using JOIN query
    
2. Do the question no 1 using JOIN query
    
3. Show the name of the employee and the job_title who receives the maximum salary
    
4. Show the list of employee name and corresponding manager names.
    

Here are the SQL queries for each of your questions:

1. **Show the employee names and corresponding job_titles without using JOIN query:**
   This can be done using a subquery or by simply selecting from the relevant tables independently. Assuming you have `employees` and `jobs` tables:

   ```sql
   SELECT name, job_title
   FROM employees, jobs
   WHERE employees.job_id = jobs.job_id;
   ```

   Alternatively, if the `job_title` is part of the `employees` table:

   ```sql
   SELECT name, job_title
   FROM employees;
   ```

2. **Do the question no 1 using JOIN query:**

   ```sql
   SELECT e.name, j.job_title
   FROM employees e
   JOIN jobs j
   ON e.job_id = j.job_id;
   ```

3. **Show the name of the employee and the job_title who receives the maximum salary:**
   Assuming there is a `salary` column in the `employees` table:

   ```sql
   SELECT name, job_title
   FROM employees
   WHERE salary = (SELECT MAX(salary) FROM employees);
   ```

4. **Show the list of employee name and corresponding manager names:**
   Assuming the `employees` table has a `manager_id` column that refers to the `employee_id` of the manager:

   ```sql
   SELECT e.name AS employee_name, m.name AS manager_name
   FROM employees e
   LEFT JOIN employees m
   ON e.manager_id = m.employee_id;
   ```

