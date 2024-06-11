-- 코드를 입력하세요
SELECT B.id, B.name, B.host_id
FROM (
    SELECT host_id
    FROM PLACES
    GROUP BY host_id
    HAVING count(1) > 1
) A, PLACES B
WHERE A.host_id= B.host_id
ORDER BY B.id