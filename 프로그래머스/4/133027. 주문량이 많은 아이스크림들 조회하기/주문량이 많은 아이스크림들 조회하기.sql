SELECT flavor
FROM (
    SELECT HALF.flavor , HALF.total_order + JULY.total_order total
    FROM 
        (SELECT flavor, total_order
        FROM FIRST_HALF) HALF
        FULL OUTER JOIN
        (SELECT flavor, SUM(total_order) total_order
        FROM JULY
        GROUP BY flavor) JULY
    ON HALF.flavor = JULY.flavor
    ORDER BY total DESC
)
WHERE ROWNUM <4