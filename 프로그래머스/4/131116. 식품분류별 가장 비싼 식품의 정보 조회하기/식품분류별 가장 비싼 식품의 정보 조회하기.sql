SELECT A.category, A.max_price, FOOD_PRODUCT.product_name
FROM FOOD_PRODUCT, 
(SELECT category, MAX(price) max_price
FROM FOOD_PRODUCT
WHERE category in ('과자','국','김치','식용유')
GROUP BY category) A
WHERE FOOD_PRODUCT.category = A.category
AND A.max_price = FOOD_PRODUCT.price
ORDER BY max_price DESC