-- 코드를 입력하세요
SELECT OUTS.animal_id, OUTS.animal_type, OUTS.name
FROM ANIMAL_INS INS, ANIMAL_OUTS OUTS
WHERE INS.animal_id = OUTS.animal_id
AND INS.sex_upon_intake LIKE 'Intact%'
AND (OUTS.sex_upon_outcome LIKE 'Spayed%' OR OUTS.sex_upon_outcome LIKE 'Neutered%')