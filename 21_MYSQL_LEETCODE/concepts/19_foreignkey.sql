-- Foreign Keys in SQL: Database Relationships
-- =============================================

-- INTRODUCTION TO FOREIGN KEYS
-- A foreign key is a column or set of columns in one table that refers to the primary key in another table. 
-- It creates a link between the two tables, establishing a parent-child relationship.
-- Parent table: Contains the primary key that is referenced
-- Child table: Contains the foreign key that references the primary key of the parent table
-- Purpose of Foreign Keys: Referential Integrity, Data Validation, Structured Relationships

-- TYPES OF TABLE RELATIONSHIPS
-- ============================

-- 1. One-to-One (1:1): Each record in Table A relates to exactly one record in Table B
CREATE TABLE employee_details (
    employee_id INT NOT NULL,
    passport_number VARCHAR(20),
    marital_status VARCHAR(20),
    emergency_contact VARCHAR(100),
    PRIMARY KEY (employee_id),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
);

-- 2. One-to-Many (1:N): Each record in Table A relates to multiple records in Table B
CREATE TABLE employees (
    employee_id INT NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    department_id INT,
    PRIMARY KEY (employee_id),
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);
-- Here, multiple employee records can reference the same department_id

-- 3. Many-to-Many (N:M): Multiple records in Table A relate to multiple records in Table B 
-- Create Students table
CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL
);

-- Create Courses table
CREATE TABLE Courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL,
    instructor VARCHAR(100) NOT NULL
);

-- Create Enrollments junction table with foreign keys
CREATE TABLE Enrollments (
    enroll_id INT PRIMARY KEY,
    student_id INT NOT NULL,
    course_id INT NOT NULL,
    grade VARCHAR(5),
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

-- PRACTICAL IMPLEMENTATION
-- ========================

-- Create a database
CREATE DATABASE company_db;
USE company_db;

-- Create the parent table (departments)
CREATE TABLE departments (
    department_id INT NOT NULL,
    department_name VARCHAR(100) NOT NULL,
    location VARCHAR(100),
    PRIMARY KEY (department_id)
);

-- Create the child table with a foreign key (employees)
CREATE TABLE employees (
    employee_id INT NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100),
    hire_date DATE,
    salary DECIMAL(10,2),
    department_id INT,
    PRIMARY KEY (employee_id),
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

-- INSERT SAMPLE DATA
-- =================

-- Insert department data
INSERT INTO departments (department_id, department_name, location)
VALUES 
    (1, 'Human Resources', 'Floor 1'),
    (2, 'Marketing', 'Floor 2'),
    (3, 'Engineering', 'Floor 3'),
    (4, 'Finance', 'Floor 1');

-- Insert employee data
INSERT INTO employees (employee_id, first_name, last_name, email, hire_date, salary, department_id)
VALUES
    (101, 'John', 'Smith', 'john.smith@company.com', '2018-06-20', 55000.00, 1),
    (102, 'Sarah', 'Johnson', 'sarah.johnson@company.com', '2019-03-15', 62000.00, 2),
    (103, 'Michael', 'Williams', 'michael.williams@company.com', '2020-01-10', 75000.00, 3),
    (104, 'Emily', 'Brown', 'emily.brown@company.com', '2019-11-05', 68000.00, 3),
    (105, 'David', 'Jones', 'david.jones@company.com', '2021-02-28', 58000.00, 4),
    (106, 'Jessica', 'Davis', 'jessica.davis@company.com', '2020-07-16', 61000.00, 2),
    (107, 'Robert', 'Miller', 'robert.miller@company.com', '2018-09-12', 72000.00, 3);

-- View employee data
SELECT * FROM employees;

-- DEMONSTRATING FOREIGN KEY CONSTRAINT
-- ====================================

-- Attempt to insert an employee with non-existent department_id (this will fail)
INSERT INTO employees (employee_id, first_name, last_name, email, hire_date, salary, department_id)
VALUES
    (145, 'John', 'Smith', 'john.smith@company.com', '2018-06-20', 55000.00, 69);
-- Error: Cannot add or update a child row: a foreign key constraint fails

-- Insert an employee with NULL department_id (allowed if the foreign key allows NULL)
INSERT INTO employees (employee_id, first_name, last_name, email, hire_date, salary, department_id)
VALUES 
    (108, 'Thomas', 'Wilson', 'thomas.wilson@company.com', '2022-04-10', 65000.00, NULL);

-- ADDING AND REMOVING FOREIGN KEYS
-- ===============================

-- Create a projects table
CREATE TABLE projects (
    project_id INT NOT NULL,
    project_name VARCHAR(100) NOT NULL,
    start_date DATE,
    end_date DATE,
    manager_id INT,
    PRIMARY KEY (project_id)
);

-- Add a foreign key constraint after table creation
ALTER TABLE projects
ADD FOREIGN KEY (manager_id) REFERENCES employees(employee_id);

-- View the table structure including the foreign key
SHOW CREATE TABLE projects;

-- Remove a foreign key constraint
ALTER TABLE projects DROP FOREIGN KEY projects_ibfk_1;

-- Verify the foreign key was removed
SHOW CREATE TABLE projects;

-- EXERCISE: IMPLEMENTING EMPLOYEE SKILLS TABLE
-- ===========================================

-- Create a table for employee skills with a foreign key to employees
CREATE TABLE employee_skills (
    skill_id INT NOT NULL,
    employee_id INT NOT NULL,
    skill_name VARCHAR(50) NOT NULL,
    proficiency_level ENUM('Beginner', 'Intermediate', 'Advanced', 'Expert') NOT NULL,
    PRIMARY KEY (skill_id),
    CONSTRAINT fk_employee_skill FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
);

-- Insert some skills
INSERT INTO employee_skills (skill_id, employee_id, skill_name, proficiency_level)
VALUES
    (1, 103, 'Python', 'Expert'),
    (2, 103, 'SQL', 'Advanced'),
    (3, 104, 'Java', 'Intermediate'),
    (4, 107, 'C++', 'Advanced'),
    (5, 107, 'SQL', 'Expert'),
    (6, 102, 'Graphic Design', 'Advanced');