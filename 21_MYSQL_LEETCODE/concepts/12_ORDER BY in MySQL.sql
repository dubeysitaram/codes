-- ORDER BY in MySQL: Single, Multiple Field, Function, Field, Case, Null Handling

/*
SQL Sorting and ORDER BY Tutorial
================================
This SQL script demonstrates various techniques for sorting data using ORDER BY
and includes examples ranging from basic to advanced sorting concepts.
*/

-- Section 1: Database and Table Setup
-- ----------------------------------
CREATE DATABASE db12;
USE db12;

-- Create a products table with various data types
CREATE TABLE products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    price DECIMAL(10,2),
    stock_quantity INT,
    last_updated TIMESTAMP
);

-- Insert initial sample data
INSERT INTO products VALUES
(1, 'Laptop Pro', 'Electronics', 1299.99, 50, '2024-01-15 10:00:00'),
(2, 'Desk Chair', 'Furniture', 199.99, 30, '2024-01-16 11:30:00'),
(3, 'Coffee Maker', 'Appliances', 79.99, 100, '2024-01-14 09:15:00'),
(4, 'Gaming Mouse', 'Electronics', 59.99, 200, '2024-01-17 14:20:00'),
(5, 'Bookshelf', 'Furniture', 149.99, 25, '2024-01-13 16:45:00');

-- Section 2: Basic Sorting Operations
-- ---------------------------------
-- Display all records (unsorted)
SELECT * FROM products;

-- Sort by price in ascending order (ASC is optional as it's the default)
SELECT * 
FROM products

-- Sort by last updated timestamp
SELECT * FROM products ORDER BY last_updated;

-- Section 3: Advanced Sorting Techniques
-- ------------------------------------
-- Multiple column sorting (sort by category descending, then price descending)
SELECT * FROM products ORDER BY category DESC, price DESC;

-- Sort using column position (4 represents the price column)
SELECT * FROM products ORDER BY 4;

-- Combining WHERE clause with ORDER BY
SELECT * FROM products 
WHERE category = 'Electronics' 
ORDER BY price;

-- Case-sensitive sorting using BINARY
SELECT * FROM products ORDER BY BINARY category;

-- Section 4: Function-Based Sorting
-- -------------------------------
-- Sort by product name length
SELECT * 
FROM products 
ORDER BY LENGTH(product_name);

-- Sort by day of the month from timestamp
SELECT * 
FROM products 
ORDER BY DAY(last_updated);

-- Using LIMIT with ORDER BY to find highest stock quantity
SELECT * 
FROM products 
ORDER BY stock_quantity DESC 
LIMIT 1;

-- Section 5: Custom Sorting Orders
-- -----------------------------
-- Default category sorting
SELECT * FROM products ORDER BY category;

-- Custom category order using FIELD function
SELECT * FROM products 
ORDER BY FIELD(category, 'Electronics','Appliances','Furniture'), price DESC;

-- Section 6: Complex Sorting with Conditions
-- ---------------------------------------
-- Simple conditional sorting for low stock and high price items
SELECT *, 
    stock_quantity <= 50 AND price >= 200 AS priority_flag
FROM products 
ORDER BY (stock_quantity <= 50 AND price >= 200) DESC;

-- Advanced priority-based sorting using CASE
SELECT *,
    CASE
        WHEN stock_quantity <= 50 AND price >= 200 THEN 1
        WHEN stock_quantity <= 50 THEN 2
        ELSE 3
    END AS priority 
FROM products 
ORDER BY priority;

-- Section 7: Handling NULL Values
-- ----------------------------
-- Add records with NULL values for demonstration
INSERT INTO products VALUES
(6, 'Desk Lamp', 'Furniture', NULL, 45, '2024-01-18 13:25:00'),
(7, 'Keyboard', 'Electronics', 89.99, NULL, '2024-01-19 15:10:00');

-- Basic NULL handling in ORDER BY
SELECT * FROM products ORDER BY price;

-- Explicit NULL handling
SELECT *, 
    price IS NULL
FROM products 
ORDER BY price IS NULL;

-- Section 8: Working with Calculated Columns
-- --------------------------------------
-- Sort by total value (price * quantity)
SELECT *, 
    price * stock_quantity AS total_value 
FROM products 
ORDER BY total_value DESC;

-- Section 9: Query Performance Analysis
-- ---------------------------------
-- Examine query execution plan for multi-column sort
EXPLAIN SELECT * FROM products
ORDER BY category, price;

-- Compare with primary key sort performance
EXPLAIN SELECT * FROM products 
ORDER BY product_id;