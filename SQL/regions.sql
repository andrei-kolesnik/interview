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

### Examples of usage:

#### list of days having at least two days of the same temperature in succession
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

#### all size-2 regions
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

#### all regions and their sizes
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