# SQL

## Pivot Tables

### Creating
```sql
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
```

### Examples of usage:

#### ASCII table of the printable characters
```sql
SELECT i Ascii_Code, CHAR(i) Ascii_Char 
FROM Pivot
WHERE i BETWEEN 32 AND 126;
```
```text
Ascii_Code	Ascii_Char
32			 
33			!
34			"
35			#
36			$
37			%
38			&
39			'
40			(
41			)
...
```

#### Calendar for the next week
```sql
SELECT 
	DATE_FORMAT(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY), "%M %d, %Y") date, 
	DAYNAME(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY)) day 
FROM Pivot 
WHERE i BETWEEN 0 AND 6;
```
```text
date 				day
August 25, 2019		Sunday
August 26, 2019		Monday
August 27, 2019		Tuesday
August 28, 2019		Wednesday
August 29, 2019		Thursday
August 30, 2019		Friday
August 31, 2019		Saturday
```