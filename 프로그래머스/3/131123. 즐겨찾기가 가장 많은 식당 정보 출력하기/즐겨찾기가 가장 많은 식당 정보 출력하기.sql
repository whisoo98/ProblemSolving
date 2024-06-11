-- 코드를 입력하세요
SELECT B.food_type, B.rest_id, B.rest_name, B.favorites
from(SELECT FOOD_TYPE, MAX(FAVORITES) favorites
FROM REST_INFO
GROUP BY FOOD_TYPE) A, REST_INFO B
where B.food_type = A.food_type
AND B.favorites = A.favorites
ORDER BY FOOD_TYPE DESC