## Regions

### Creating
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

### List of days having at least two days of the same temperature in succession
SELECT 
	DISTINCT w1.DayNo, w1.Temperature
FROM
	DailyWeather w1,
	DailyWeather w2
WHERE
	w1.Temperature = w2.Temperature
	AND abs(w1.DayNo - w2.DayNo) = 1
ORDER BY 
	w1.DayNo;

### All size-2 regions
SELECT 
	w1.DayNo AS 'Start', 
	w2.DayNo AS 'Finish', 
	w1.Temperature
FROM 
	DailyWeather w1,
	DailyWeather w2
WHERE 
	w1.DayNo = w2.DayNo - 1
	AND w1.Temperature = w2.Temperature
ORDER BY w1.DayNo;

### All regions and their sizes
SELECT 
	w1.DayNo AS 'Start', 
	w2.DayNo AS 'Finish', 
	w2.DayNo - w1.DayNo + 1 as 'Size',
	w1.Temperature
FROM 
	DailyWeather w1,
	DailyWeather w2
WHERE 
	w1.DayNo < w2.DayNo
	AND w1.Temperature = w2.Temperature
	AND NOT EXISTS (
		SELECT 1 
		FROM DailyWeather w3
		WHERE
			(w3.Temperature != w1.Temperature AND w3.DayNo BETWEEN w1.DayNo AND w2.DayNo)
			OR (w3.Temperature = w1.Temperature AND w3.DayNo = w1.DayNo - 1)
			OR (w3.Temperature = w2.Temperature AND w3.DayNo = w2.DayNo + 1)
	)
ORDER BY 
	w1.DayNo,
	w2.DayNo;
    
### Regions of Sequential Numbers: all
CREATE TABLE AvailableDays (DayNo INTEGER NOT NULL);
INSERT INTO AvailableDays (DayNo) VALUES 
(1),
(2),
(3),
(6),
(7),
(8),
(9),
(11),
(13),
(14),
(15),
(17),
(18),
(20);

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

### Regions of Sequential Numbers: of Maximum Size
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

### using RANK()
SELECT 
	MIN(DayNo) AS Start, 
    MAX(DayNo) AS Finish, 
    MAX(DayNo) - MIN(DayNo) + 1 AS Size 
FROM
(SELECT 
	DayNo, 
    RANK() OVER (ORDER BY DayNo) AS DayRank, 
    DayNo - RANK() OVER (ORDER BY DayNo) AS RankDiff
FROM AvailableDays) AS Ranked
GROUP BY RankDiff
HAVING MIN(DayNo) < MAX(DayNo);
