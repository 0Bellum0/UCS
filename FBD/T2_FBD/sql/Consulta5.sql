--Users que nao sao corretores

SELECT U.ID
FROM USERS U
EXCEPT
SELECT C.USER_ID
FROM CORRETOR C