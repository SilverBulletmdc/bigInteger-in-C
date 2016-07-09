#include "BigInteger.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *构造函数
 */
BigInteger init(){
	BigInteger bi = (BigInteger)malloc(sizeof(_BigInteger));
	int i;
	bi->size = 0;
	for(i = 0; i <= 1000; i++)
		bi->digits[i] = 0;
	return bi;
}
BigInteger bigInteger(char str[]){
	BigInteger bi = init();
	set(str, bi);
	return bi;
}
void set(char str[], BigInteger bi){
	bi->size = 0;
	int i,j,t,c;
	for(i = 0; i <= 1000; i++)
		bi->digits[i] = 0;
	int L = strlen(str);

	/**
	 * 注：此处是用数组低位保存数据低位
	 */
	for(i = L -1, j = 0, t = 0, c = 1; i >= 0; i--){
		t += (str[i] - '0') * c;
		j++;
		c *= 10;
		if(j == 4 || i == 0){
			bi->digits[bi->size++] = t;
			j = 0;
			t = 0;
			c = 1;
		}

	}

}
void output(BigInteger bi){
	int i;
	printf("%d",bi->digits[bi->size-1]);
	for(i = bi->size-2; i >= 0; i-- )
		printf("%04d", bi->digits[i]);
	printf("\n");
}
