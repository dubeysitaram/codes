-- 10_SQL Logical Operators.sql
-- Logical operators are used in SQL to filter records based on multiple conditions in the WHERE clause


-- AND → Returns records where both conditions are TRUE
-- OR → Returns records where at least one condition is TRUE
-- NOT → Negates a condition (returns the opposite result)

CREATE DATABASE company_db;
USE company_db;
CREATE TABLE employees (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    age INT,
    department VARCHAR(50),
    salary DECIMAL(10,2),
    city VARCHAR(50)
);


INSERT INTO employees (name, age, department, salary, city) VALUES
('Alice Johnson', 30, 'HR', 50000, 'New York'),
('Bob Smith', 25, 'IT', 70000, 'Los Angeles'),
('Charlie Brown', 35, 'IT', 80000, 'New York'),
('David Wilson', 40, 'Finance', 90000, 'Chicago'),
('Emily Davis', 28, 'HR', 48000, 'San Francisco'),
('Franklin Moore', 32, 'IT', 75000, 'Los Angeles'),
('Grace Adams', 45, 'Finance', 95000, 'Chicago');

select * from employees;

-- Find employees who work in the IT department and earn more than $70,000
select * from employees where department='IT' and salary > 70000;

-- Find employees who work in the HR department OR live in New York
select * from employees where department= 'hr' or city = 'New York'
 
-- Find employees who are NOT in the Finance department
select * from employees where not department= 'Finance'

-- Find employees who are in IT and earn more than $70,000 OR work in Finance
SELECT * FROM employees WHERE (department = 'IT' AND salary > 70000) OR department = 'Finance';

-- Find employees who are NOT in the IT department AND do not live in Chicago
select * from employees where not department = 'IT' and not city = 'Chicago'