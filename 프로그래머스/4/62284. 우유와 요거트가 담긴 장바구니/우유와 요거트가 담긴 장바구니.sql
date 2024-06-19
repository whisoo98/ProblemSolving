-- 코드를 입력하세요
SELECT DISTINCT C.cart_id
FROM(   
    SELECT A.cart_id, (A.name || ' ' || B.name) name
    FROM CART_PRODUCTS A, CART_PRODUCTS B
    WHERE A.cart_id = B.cart_id
    AND A.name != B.name) C
WHERE name LIKE '%Milk%'
AND name LIKE '%Yogurt%'
ORDER BY C.cart_id