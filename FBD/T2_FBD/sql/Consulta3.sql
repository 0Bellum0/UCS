--Empreendimentos que nao tem planta

SELECT EP.ID
FROM EMPREENDIMENTO_PLANTA EP
EXCEPT
SELECT EPS.EMPREENDIMENTO_PLANTA_ID
FROM EMPREENDIMENTO_PLANTA_POSICAO_SOLAR EPS