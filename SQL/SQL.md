# SQL

## PIVOT TABLES

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



## REGIONS

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

### List of days having at least two days of the same temperature in succession
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

| DayNo | Temperature |
| --- | --- |
|1|50|
|2|50|
|10|50|
|11|50|
|12|50|
|13|60|
|14|60|


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

### Regions of Sequential Numbers: all
```sql
CREATE TABLE AvailableDays (DayNo INTEGER NOT NULL);
INSERT INTO AvailableDays (DayNo) VALUES 
(1), (2), (3), (6), (7), (8), (9), (11), (13), (14), (15), (17), (18), (20);

SELECT 
	D1.DayNo AS Start, 
	MAX(D2.DayNo) AS Finish,
	MAX(D2.DayNo) - D1.DayNo + 1 AS Size
FROM 
	AvailableDays D1,
	AvailableDays D2 
WHERE
	D1.DayNo < D2.DayNo
	AND (D2.DayNo - D1.DayNo + 1) = 
		(SELECT COUNT(*) FROM AvailableDays D3 WHERE D3.DayNo BETWEEN D1.DayNo AND D2.DayNo)
	AND NOT EXISTS (SELECT * FROM AvailableDays D4 WHERE (D1.DayNo - 1 = D4.DayNo))
GROUP BY D1.DayNo;
```
| Start | Finish | Size |
| ----- | ------ | ---- |
|1|3|3|
|6|9|4|
|13|15|3|
|17|18|2|

### using RANK()
```sql
SELECT 
	MIN(DayNo) AS Start, 
	MAX(DayNo) AS Finish, 
	MAX(DayNo) - MIN(DayNo) + 1 AS Size 
FROM
(SELECT 
	DayNo, 
	RANK() OVER (ORDER BY DayNo) AS DayRank, # not needed, just for the illustration
	DayNo - RANK() OVER (ORDER BY DayNo) AS RankDiff
FROM AvailableDays) AS Ranked
GROUP BY RankDiff
HAVING MIN(DayNo) < MAX(DayNo);
```
Subquery (Ranked):

| DayNo | DayRank | RankDiff |
| ----- | ------- | -------- |
|1|1|0|
|2|2|0|
|3|3|0|
|6|4|2|
|7|5|2|
|8|6|2|
|9|7|2|
|11|8|3|
|13|9|4|
|14|10|4|
|15|11|4|
|17|12|5|
|18|13|5|
|20|14|6|

Entire query:

| Start | Finish | Size |
| ----- | ------ | ---- |
|1|3|3|
|6|9|4|
|13|15|3|
|17|18|2|

### Regions of Sequential Numbers: of Maximum Size
```sql
SELECT 
	D1.DayNo, 
	D2.DayNo,
	D2.DayNo - D1.DayNo + 1 AS Size
FROM 
	AvailableDays D1,
	AvailableDays D2 
WHERE
	D1.DayNo < D2.DayNo
	AND (D2.DayNo - D1.DayNo + 1) = 
		(SELECT COUNT(*) FROM AvailableDays D3 WHERE D3.DayNo BETWEEN D1.DayNo AND D2.DayNo)
	AND NOT EXISTS (SELECT * FROM AvailableDays D4 WHERE 
		(D1.DayNo - 1 = D4.DayNo) OR (D2.DayNo + 1 = D4.DayNo))
ORDER BY Size DESC LIMIT 1;
```
| Start | Finish | Size |
| ----- | ------ | ---- |
|6|9|4|



## WINDOW FUNCTIONS

### Creating
```sql
CREATE TABLE Cities (
    City VARCHAR(24) NOT NULL,
	Continent VARCHAR(16) NOT NULL,
    Population INT NOT NULL,
    CHECK(Continent IN ('Asia', 'Africa',  'North America', 'South America', 'Antarctica', 'Europe', 'Australia'))
);

INSERT INTO Cities (City, Continent, Population) VALUES
    ('Beijing', 'Asia', 18000000),
    ('Shanghai', 'Asia', 24000000),
    ('Mexico City', 'South America', 8000000),
    ('Berlin', 'Europe', 3000000),
    ('Bogota', 'South America', 8000000),
    ('Cairo', 'Africa', 9000000),
    ('Istanbul', 'Asia', 14000000),
    ('Karachi', 'Asia', 18000000),
    ('Kinshasa', 'Africa', 10000000),
    ('Lima', 'South America', 9000000),
    ('London', 'Europe', 8000000),
    ('Los Angeles', 'North America', 3000000),
    ('Melbourne', 'Australia', 4000000),
    ('Moscow', 'Europe', 13000000),
    ('New York City', 'North America', 8000000),
    ('Sao Paulo', 'South America', 12000000),
    ('St Petersburg', 'Europe', 5000000),
    ('Sydney', 'Australia', 5000000);  
```
    
### Single column - Using the built-in function (8.0+)
```sql
SELECT
	City, 
    Continent,
    Population,
    RANK() OVER (ORDER BY Population DESC) AS Rank,
    DENSE_RANK() OVER (ORDER BY Population DESC) AS DenseRank
FROM Cities LIMIT 5;
```
    
### Single column - Simulating (pre-8.0)
```sql
SELECT City, Population, Count, Rank, DenseRank
FROM
(
	SELECT 
		City, 
		Population,                 
		@count := @count + 1 as Count,
		@rank := IF(Population = @prev_pop, @rank, @count) as Rank,
		@dense_rank := @dense_rank + IF(Population = @prev_pop, 0, 1) AS DenseRank,                
		@prev_pop := Population 
	FROM 
		Cities,
		(SELECT @count := 0, @rank := 0, @dense_rank := 0, @prev_pop := 0) AS R
	ORDER BY Population DESC
) CitiesRanked
ORDER BY Rank;
```

| City | Continent | Population | Rank | DenseRank |
| ---- | --------- | ---------- | ---- | --------- |
|Shanghai|Asia|24000000|1|1|
|Beijing|Asia|18000000|2|2|
|Karachi|Asia|18000000|2|2|
|Istanbul|Asia|14000000|4|3|
|Moscow|Europe|13000000|5|4|
|Sao Paulo|South America|12000000|6|5|
|Kinshasa|Africa|10000000|7|6|
|Cairo|Africa|9000000|8|7|
|Lima|South America|9000000|8|7|
|Bogota|South America|8000000|10|8|
|Mexico City|South America|8000000|10|8|
|London|Europe|8000000|10|8|
|New York City|North America|8000000|10|8|
|St Petersburg|Europe|5000000|14|9|
|Sydney|Australia|5000000|14|9|
|Melbourne|Australia|4000000|16|10|
|Berlin|Europe|3000000|17|11|
|Los Angeles|North America|3000000|17|11|


### Multiple columns - Using the built-in function (8.0+)
```sql
SELECT
	City, 
	Continent,
	Population,
	RANK() OVER (PARTITION BY Continent ORDER BY Population DESC) AS Rank,
	DENSE_RANK() OVER (PARTITION BY Continent ORDER BY Population DESC) AS DenseRank
FROM Cities;
```

### Multiple columns - Simulating (pre-8.0)
```sql
SELECT Continent, City, Population, Rank, DenseRank
FROM
(
	SELECT 
		Continent,
		City, 
		Population,                 
		@count := IF(Continent = @prev_cont, @count + 1, 1) as Count,
		@rank := IF(Continent = @prev_cont, IF(Population = @prev_pop, @rank, @count), 1) as Rank,
		@dense_rank := IF(Continent = @prev_cont, @dense_rank + IF(Population = @prev_pop, 0, 1), 1) AS DenseRank,
		@prev_pop := Population,
        @prev_cont := Continent AS PrevCont
	FROM 
		Cities,
		(SELECT @count := 0, @rank := 0, @dense_rank := 0, @prev_pop := 0, @prev_cont = '') AS R
	ORDER BY Continent, Population DESC
) CitiesRanked
ORDER BY Continent, Rank;
```

| City | Continent | Population | Rank | DenseRank |
| ---- | --------- | ---------- | ---- | --------- |
|Kinshasa|Africa|10000000|1|1|
|Cairo|Africa|9000000|2|2|
|Shanghai|Asia|24000000|1|1|
|Beijing|Asia|18000000|2|2|
|Karachi|Asia|18000000|2|2|
|Istanbul|Asia|14000000|4|3|
|Sydney|Australia|5000000|1|1|
|Melbourne|Australia|4000000|2|2|
|Moscow|Europe|13000000|1|1|
|London|Europe|8000000|2|2|
|St Petersburg|Europe|5000000|3|3|
|Berlin|Europe|3000000|4|4|
|New York City|North America|8000000|1|1|
|Los Angeles|North America|3000000|2|2|
|Sao Paulo|South America|12000000|1|1|
|Lima|South America|9000000|2|2|
|Bogota|South America|8000000|3|3|
|Mexico City|South America|8000000|3|3|
