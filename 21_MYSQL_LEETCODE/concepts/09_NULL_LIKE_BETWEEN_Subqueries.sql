-- Master Where Clause in SQL: NULL, LIKE, BETWEEN, Subqueries | Complete Filtering Guide 2025


CREATE DATABASE bookstore;

USE bookstore;
CREATE TABLE books (
    book_id INT PRIMARY KEY,
    title VARCHAR(100),
    author VARCHAR(50),
    price DECIMAL(10,2),
    publication_date DATE,
    category VARCHAR(30),
    in_stock INT
);

INSERT INTO books VALUES
(1, 'The MySQL Guide', 'John Smith', 29.99, '2023-01-15', 'Technology', 50),
(2, 'Data Science Basics', 'Sarah Johnson', 34.99, '2023-03-20', 'Technology', 30),
(3, 'Mystery at Midnight', 'Michael Brown', 19.99, '2023-02-10', 'Mystery', 100),
(4, 'Cooking Essentials', 'Lisa Anderson', 24.99, '2023-04-05', 'Cooking', 75);

INSERT INTO books VALUES
(5, 'Cook Book', null, 24.99, '2023-04-05', 'Cooking', 75);

INSERT INTO books VALUES
(6, 'Mini Cook Book', 'Gohn Smith', 24.99, '2023-04-05', 'Cooking', 75);

select * from books where category='Technology' ;

SELECT title, price FROM books WHERE price < 30.00;

SELECT title, publication_date FROM books 
WHERE publication_date >= '2023-03-01';

-- Logical Operators
-- AND
select * from books where category = 'Technology' and price < 30;
-- OR

select * from books where category = 'Technology' or price < 30;

-- COMBINATION OF AND OR 
select * from books where (category = 'Technology' or category = 'Mystery') and price < 25; 

-- NOT
select * from books where not category = 'Technology';

-- Finding NULL values

select * from books where author is null;
select * from books where author is not null;

-- Pattern matching

select * from books where title like '%SqL%';
select * from books where title like 'the%';
select * from books where title like binary '%SQL%';
select * from books where author like '_ohn%';

-- RANGE OPERATORS 

select * from books where price between 20 and 30;

select * from books where category in ('Technology', 'MysterY', 'Science');

SELECT * FROM books 
WHERE price BETWEEN 20.00 AND 40.00  AND publication_date >= '2023-01-01';
    
-- SUBQUERIES

select * from books where price > ( select avg(price) from books );

select * from books where category in (
select category from books where in_stock > 20
);


 -- Find all books published in 2023 that cost less than the average book price
 
SELECT title, price, publication_date
FROM books
WHERE YEAR(publication_date) = 2023
AND price < (SELECT AVG(price) FROM books);

 -- List all technology books with "data" in the title that have more than 50 copies in stock
 
SELECT title, category, in_stock
FROM books
WHERE category = 'Technology'
AND title LIKE '%data%'
AND in_stock > 50;

 -- Find books that are either in the Technology category with price > $30 or in the Mystery category with price < $20
 
SELECT title, category, price
FROM books
WHERE (category = 'Technology' AND price > 30.00)
OR (category = 'Mystery' AND price < 20.00);

 -- List all books where the author's name contains either 'son' or 'th' and were published after March 2023

SELECT title, author, publication_date
FROM books
WHERE (author LIKE '%son%' OR author LIKE '%th%')
AND publication_date > '2023-03-31';
