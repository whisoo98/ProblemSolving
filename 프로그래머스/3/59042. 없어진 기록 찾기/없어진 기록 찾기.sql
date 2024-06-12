-- 코드를 입력하세요
SELECT OUTS.animal_id, OUTS.name
FROM ANIMAL_OUTS OUTS
WHERE OUTS.animal_id not in (
                            SELECT animal_id
                            FROM ANIMAL_INS)
ORDER BY OUTS.animal_id