-- 09_Rising Temperature.sql
-- Table: Weather

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | recordDate    | date    |
-- | temperature   | int     |
-- +---------------+---------+
-- id is the column with unique values for this table.
-- There are no different rows with the same recordDate.
-- This table contains information about the temperature on a certain day.
 

-- Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday).

-- Return the result table in any order.

-- The result format is in the following example.


-- This task is  so easy to solve if you  know 
-- about DATEDIFF function and the table can be JOIN to it self by this difference.

-- use DATEDIFF like ------>   DATEDIFF(starting date,ending date) 

select w1.id
from Weather w1 join Weather w2 on
datediff(w1.recordDate,w2.recordDate)=1 AND w1.temperature>w2.temperature;
