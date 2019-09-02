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

### ASCII table of the printable characters
```sql
SELECT i Ascii_Code, CHAR(i) Ascii_Char 
FROM Pivot
WHERE i BETWEEN 32 AND 126;
```
| Ascii_Code | Ascii_Char |
| ---------- | ---------- |
|32| |
|33|!|
|34|"|
|35|#|
|36|$|
|37|%|
|38|&|
|39|'|
|40|(|
|41|)|
...

### Calendar for the next week
```sql
SELECT 
	DATE_FORMAT(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY), "%M %d, %Y") date, 
	DAYNAME(DATE_ADD(CURRENT_TIMESTAMP, INTERVAL i DAY)) day 
FROM Pivot 
WHERE i BETWEEN 0 AND 6;
```
| date | day |
| ---- | --- |
|August 25, 2019|Sunday|
|August 26, 2019|Monday|
|August 27, 2019|Tuesday|
|August 28, 2019|Wednesday|
|August 29, 2019|Thursday|
|August 30, 2019|Friday|
|August 31, 2019|Saturday|

## Regions

### Creating

```sql
CREATE TABLE DailyWeather (
	DayNo INTEGER NOT NULL UNIQUE,
	Temperature INTEGER NOT NULL);
    
INSERT INTO DailyWeather (`DayNo`, `Temperature`) VALUES
( 1, 50),
( 2, 50),
( 3, 51),
( 4, 52),
( 5, 53),
( 6, 50),
( 7, 53),
( 8, 58),
( 9, 59),
(10, 50),
(11, 50),
(12, 50),
(13, 60),
(14, 60);
```

### list of days having at least two days of the same temperature in succession
```sql
SELECT 
	DISTINCT w1.DayNo
FROM
	DailyWeather w1,
    DailyWeather w2
WHERE
	w1.Temperature = w2.Temperature AND
    abs(w1.DayNo - w2.DayNo) = 1
ORDER BY 
	w1.DayNo;
```

| | DayNo |
| --- | --- |
| |1|
| |2|
| |10|
| |11|
| |12|
| |13|
| |14|


### All size-2 regions
```sql
SELECT 
	w1.DayNo AS 'Start', 
	w2.DayNo AS 'Finish', 
    w1.Temperature
FROM 
	DailyWeather w1,
	DailyWeather w2
WHERE 
	w1.DayNo = w2.DayNo - 1 AND
    w1.Temperature = w2.Temperature
ORDER BY w1.DayNo;
```
| Start | Finish | Temperature |
| ----- | ------ | ----------- |
|1|2|50|
|10|11|50|
|11|12|50|
|13|14|60|

### All regions and their sizes
```sql
SELECT 
	w1.DayNo AS 'Start', 
	w2.DayNo AS 'Finish', 
    w2.DayNo - w1.DayNo + 1 as 'Size',
    w1.Temperature
FROM 
	DailyWeather w1,
	DailyWeather w2
WHERE 
	w1.DayNo < w2.DayNo AND
    w1.Temperature = w2.Temperature AND
    NOT EXISTS (
		SELECT 1 
        FROM DailyWeather w3
        WHERE
			(w3.Temperature != w1.Temperature AND w3.DayNo BETWEEN w1.DayNo AND w2.DayNo) OR
            (w3.Temperature = w1.Temperature AND w3.DayNo = w1.DayNo - 1) OR
            (w3.Temperature = w2.Temperature AND w3.DayNo = w2.DayNo + 1)
    )
ORDER BY 
	w1.DayNo,
    w2.DayNo;
```
| Start | Finish | Size | Temperature |
| ----- | ------ | ---- | ----------- |
|1|2|2|50|
|10|12|3|50|
|13|14|2|60|
