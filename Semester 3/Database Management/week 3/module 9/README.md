### Primary Key and Foreign Key Constraint
**Primary Key**:
- A **Primary Key** is a constraint in a relational database that uniquely identifies each record in a table.
- A table can only have one Primary Key, but it may consist of single or multiple columns (composite key).
- It enforces **uniqueness** and **NOT NULL** constraints automatically.
  
  **Example**:
  ```sql
  CREATE TABLE Students (
      StudentID INT PRIMARY KEY,
      Name VARCHAR(100),
      Age INT
  );
  ```

**Foreign Key**:
- A **Foreign Key** is a field (or collection of fields) in one table that refers to the Primary Key in another table.
- It establishes a relationship between two tables, enforcing **referential integrity**.

  **Example**:
  ```sql
  CREATE TABLE Enrollments (
      EnrollmentID INT PRIMARY KEY,
      StudentID INT,
      CourseID INT,
      FOREIGN KEY (StudentID) REFERENCES Students(StudentID)
  );
  ```

---

### Foreign Key ON DELETE Operations
When a referenced record is deleted, the **ON DELETE** clause specifies what happens to the related records in the referencing table.

- **CASCADE**: Deletes the related rows in the child table automatically.
  ```sql
  FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE CASCADE
  ```

- **SET NULL**: Sets the Foreign Key column in the child table to `NULL`.
  ```sql
  FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE SET NULL
  ```

- **SET DEFAULT**: Sets the Foreign Key column in the child table to its default value.
  ```sql
  FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE SET DEFAULT
  ```

- **NO ACTION** (default): Prevents deletion of the referenced record if related records exist.
  ```sql
  FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE NO ACTION
  ```

- **RESTRICT**: Similar to `NO ACTION`, but it checks immediately for referential integrity.
  ```sql
  FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE RESTRICT
  ```

---

### Set Operations
Set operations combine the results of two or more queries into a single result. The queries must have the same number of columns and compatible data types.

1. **UNION**: Combines results of two queries, removing duplicates.
   ```sql
   SELECT Name FROM Students
   UNION
   SELECT Name FROM Teachers;
   ```

2. **UNION ALL**: Combines results without removing duplicates.
   ```sql
   SELECT Name FROM Students
   UNION ALL
   SELECT Name FROM Teachers;
   ```

3. **INTERSECT**: Returns rows common to both queries.
   ```sql
   SELECT Name FROM Students
   INTERSECT
   SELECT Name FROM Teachers;
   ```

4. **EXCEPT** (or MINUS in some databases): Returns rows in the first query but not in the second.
   ```sql
   SELECT Name FROM Students
   EXCEPT
   SELECT Name FROM Teachers;
   ``` 

