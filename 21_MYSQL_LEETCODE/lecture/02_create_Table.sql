-- Create a table named 'employees'
create table employees(
    
    -- Unique identifier for each employee, automatically increments
    employee_id int primary key auto_increment,
    
    -- Employee's first name, cannot be null
    first_name varchar(50) not null,
    
    -- Employee's last name, cannot be null
    last_name varchar(50) not null,
    
    -- Date of hiring, defaults to the current date
    hire_date date default (CURRENT_DATE()),
    
    -- Employee's email, must be unique
    email varchar(100) unique,
    
    -- Employee's phone number, must be unique
    phone_number varchar(100) unique,
    
    -- Employee's salary, must be a positive number (up to 10 digits total, 2 after decimal)
    salary decimal(10,2) check (salary > 0.0),
    
    -- Employment status with allowed values using the enum , defaults to 'active'
    employment_status enum('active', 'on leave', 'terminated') default 'active',
    
    -- Timestamp when the record is created, defaults to current timestamp
    created_at timestamp default CURRENT_TIMESTAMP,
    
    -- Timestamp when the record is last updated, auto-updates on change yahi syntax hota hai 
    updated_at timestamp default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP 
);
