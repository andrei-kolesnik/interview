## Rank

### Creating
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
    
### Single column - Using the built-in function (8.0+)
SELECT
	City, 
    Continent,
    Population,
    RANK() OVER (ORDER BY Population DESC) AS Rank,
    DENSE_RANK() OVER (ORDER BY Population DESC) AS DenseRank
FROM Cities;
    
### Single column - Simulating (pre-8.0)
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

### Multiple columns - Using the built-in function (8.0+)
SELECT
	City, 
    Continent,
    Population,
    RANK() OVER (PARTITION BY Continent ORDER BY Population DESC) AS Rank,
    DENSE_RANK() OVER (PARTITION BY Continent ORDER BY Population DESC) AS DenseRank
FROM Cities;

### Multiple columns - Simulating (pre-8.0)
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
