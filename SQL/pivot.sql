CREATE TABLE Pivot (i INT, PRIMARY KEY(i));

-- support table for populating the Pivot table with multiple rows
CREATE TABLE Pivot_Fill(i CHAR(1));

INSERT INTO Pivot_Fill VALUES('0');
INSERT INTO Pivot_Fill VALUES('1');
INSERT INTO Pivot_Fill VALUES('2');
INSERT INTO Pivot_Fill VALUES('3');
INSERT INTO Pivot_Fill VALUES('4');
INSERT INTO Pivot_Fill VALUES('5');
INSERT INTO Pivot_Fill VALUES('6');
INSERT INTO Pivot_Fill VALUES('7');
INSERT INTO Pivot_Fill VALUES('8');
INSERT INTO Pivot_Fill VALUES('9');

-- using 10 rows in the Pivot_Fill table, we can populate the Pivot table with 10, 100, 1000, ... rows
INSERT INTO Pivot
SELECT CONCAT(f1.i, f2.i, f3.i)
FROM Pivot_Fill f1, Pivot_Fill F2, Pivot_Fill f3;

-- Examples of usage:

-- ASCII table of the printable characters
SELECT i Ascii_Code, CHAR(i) Ascii_Char 
FROM Pivot
WHERE i BETWEEN 32 AND 126;

-- calendar for the next week
SELECT 
	DATE_FORMAT(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY), "%M %d, %Y") date, 
	DAYNAME(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY)) day 
FROM Pivot 
WHERE i BETWEEN 0 AND 6;
