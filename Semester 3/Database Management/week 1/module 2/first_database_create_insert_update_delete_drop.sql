-- USE progrominghero;

-- CREATE TABLE Students (
--     Roll CHAR(4) PRIMARY KEY,
--     Name VARCHAR(50),
--     Marks INT
-- );

-- INSERT INTO Student
-- (Roll, Name, Marks) value(1, 'Kawshik', 90);

-- INSERT INTO Student
-- (Roll, Name) value(2, 'Rohan');

-- set SQL_safe_updates = 0;
-- update Student
-- set Name = 'Kawshik Kumar Paul'
-- where Roll = 1;
-- set SQL_safe_updates = 1;

set SQL_safe_updates = 0;
delete from Student
where Roll = 1;
set SQL_safe_updates = 1;