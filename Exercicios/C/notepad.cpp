/*.:Notepad:.

Tarefas:

	

*********************************************************************************************************************

bibliotecas:
	
	stdio.h
	time.h
	stdlib.h
	math.h
	ctype.h
	strings.h
	

*********************************************************************************************************************

Codigo em geral:

++c --> pre incremento (incrementa antes de atribuir)

c++ --> pos incremento (incrementa depois de atribuir)
	
% 4d --> 4 espacos entre

%d --> Ler inteiros

%f --> Ler floats

%c --> Ler caracteres

%s --> Ler strings

%x --> endereço de memória

fflush(stdin); --> Versão Windows / limpa a entrada padrão / para retirar o enter (\n) no stdin

__fpurge(stdin); --> Versão Linux / limpa a entrada padrão / para retirar o enter (\n) no stdin

getchar(); --> recebe um caractere / útil para retirar o enter no stdin

gets(string); --> para ler strings sem espaço

puts(string); --> equivalente ao printf / porém mais limitado pois so cospe tudo na tela

toupper(); --> função da biblioteca ctype para converter caracteres para maiúsculas

tolower(); --> função da biblioteca ctype para converter caracteres para minúsculas

strlen(); --> função da biblioteca strings.h para medir o tamanho da string

strcmp(str1, str2); --> comparação de strings

strcasecmp(); --> variação do strcmp(); que considera letras maisculas ou minusculas

pon -> var --> cara apontado por 'pon' campo 'var' (da struct)

(int *)malloc(n * sizeof(int)); --> (tipo a receber vezes o) memory allocation('n' vezes o tamanho do (tipo));

srand(time(NULL)); --> seta a seed do rand no time

Arquivos:
	'r' e 'rb' (binario) - read
	'w' e 'wb' (binario) - write
	'a' e 'ab' (binario) - append

	fread(variavel, sizeof(tipo), quantas vezes, arquivo);
	
	fwrite(variavel, sizeof(tipo), quantas vezes, arquivo);

	rewind(f); --> volta para o inicio do arquivo 'f' | "reinicia" o arquivo

	fopen(nome do arquivo, "operação"); --> operação - r, w, a ou rb, rw, ra ...

	fclose(f); -> 'f' - arquivo

	fseek(f, sizeof(tipo), SEEK_SET); --> 'f' - arquivo | sizeof(int, float ...) | SEEK_SET - começo do arquivo
	fseek(f, -sizeof(tipo), SEEK_END); --> 'f' - arquivo | sizeof(int, float ...) | SEEK_END - final do arquivo
	fseek(f, -sizeof(tipo), SEEK_CUR); --> 'f' - arquivo | sizeof(int, float ...) | SEEK_CUR - posição atual no arquivo

*********************************************************************************************************************

Tabela ACSII:

0 \0    1 ☺     2 ☻     3 ♥     4 ♦     5 ♣     6 ♠     7       8       9               10
        14 ♫    15 ☼    16 ►    17 ◄    18 ↕    19 ‼    20 ¶    21 §    22 ▬    23 ↨    24 ↑    25 ↓    26 →    27 ←
        28 ∟    29 ↔    30 ▲    31 ▼    32      33 !    34 "    35 #    36 $    37 %    38 &    39 '    40 (    41 )
        42 *    43 +    44 ,    45 -    46 .    47 /    48 0    49 1    50 2    51 3    52 4    53 5    54 6    55 7
        56 8    57 9    58 :    59 ;    60 <    61 =    62 >    63 ?    64 @    65 A    66 B    67 C    68 D    69 E
        70 F    71 G    72 H    73 I    74 J    75 K    76 L    77 M    78 N    79 O    80 P    81 Q    82 R    83 S
        84 T    85 U    86 V    87 W    88 X    89 Y    90 Z    91 [    92 \    93 ]    94 ^    95 _    96 `    97 a
        98 b    99 c    100 d   101 e   102 f   103 g   104 h   105 i   106 j   107 k   108 l   109 m   110 n   111 o
        112 p   113 q   114 r   115 s   116 t   117 u   118 v   119 w   120 x   121 y   122 z   123 {   124 |   125 }
        126 ~   127 ⌂   128 Ç   129 ü   130 é   131 â   132 ä   133 à   134 å   135 ç   136 ê   137 ë   138 è   139 ï
        140 î   141 ì   142 Ä   143 Å   144 É   145 æ   146 Æ   147 ô   148 ö   149 ò   150 û   151 ù   152 ÿ   153 Ö
        154 Ü   155 ø   156 £   157 Ø   158 ×   159 ƒ   160 á   161 í   162 ó   163 ú   164 ñ   165 Ñ   166 ª   167 º
        168 ¿   169 ®   170 ¬   171 ½   172 ¼   173 ¡   174 «   175 »   176 ░   177 ▒   178 ▓   179 │   180 ┤   181 Á
        182 Â   183 À   184 ©   185 ╣   186 ║   187 ╗   188 ╝   189 ¢   190 ¥   191 ┐   192 └   193 ┴   194 ┬   195 ├
        196 ─   197 ┼   198 ã   199 Ã   200 ╚   201 ╔   202 ╩   203 ╦   204 ╠   205 ═   206 ╬   207 ¤   208 ð   209 Ð
        210 Ê   211 Ë   212 È   213 ı   214 Í   215 Î   216 Ï   217 ┘   218 ┌   219 █   220 ▄   221 ¦   222 Ì   223 ▀
        224 Ó   225 ß   226 Ô   227 Ò   228 õ   229 Õ   230 µ   231 þ   232 Þ   233 Ú   234 Û   235 Ù   236 ý   237 Ý
        238 ¯   239 ´   240 ­   241 ±   242 ‗   243 ¾   244 ¶   245 §   246 ÷   247 ¸   248 °   249 ¨   250 ·   251 ¹
        252 ³   253 ²   254 ■   255


Gerador da Tabela ASCII:

#include<stdio.h>

int main(){
	
	int i;
	
	for(i=0; i<256; i++){
		printf("%d %c\t", i, i);
	}


hexadecimal:
				10*16³ + 13*16² + 8*16¹ + 12*16° | AD8C
												   3210
												   
*********************************************************************************************************************

Structs:

struct exemplo{
	char char_exemplo[50];
	int int_exemplo;
	char char_exemplo;
};
typedef struct exemplo EXEMPLO; --> a variável pode ser qualquer coisa

typedef struct exemplo{
	char char_exemplo[50];
	int int_exemplo;
	char char_exemplo;
}EXEMPLO;

*/