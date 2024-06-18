SELECT FOOD.product_id, FOOD.product_name, ORDERS.amount * FOOD.price AS TOTAL_SALES
FROM 
(SELECT product_id, SUM(amount) amount
FROM FOOD_ORDER
WHERE TO_CHAR(produce_date,'YYYY-MM') = '2022-05'
GROUP BY product_id) ORDERS, FOOD_PRODUCT FOOD
WHERE FOOD.product_id = orders.product_id
ORDER BY total_sales DESC, FOOD.product_id ASC