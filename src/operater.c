#include "BigInteger.h"
#define max(a,b) (a>b?a:b)
void add(BigInteger a, BigInteger b, BigInteger c){
	int i,j;
	int carry = 0;
	for(i = 0; i <= 1000; i++)
	{
		c->digits[i] = 0;
	}
	c->size = 0;

	for(i = 0; i < max(a->size,b->size);i++){
		int temp = a->digits[i] + b->digits[i] + carry;
		carry = temp / 10000;
		temp %= 10000;
		c->digits[c->size++] = temp;
	}
	if(carry != 0)
		c->digits[c->size++] = carry;
}

void substract(BigInteger a, BigInteger b, BigInteger c){
	int i,j,f = 1;//f为取反标记
	int carry = 0;
	BigInteger d;
	switch(cmp(a,b)){
	case -1:
		d = a;
		a = b;
		b = d;
		f = -1;
		break;
	case 0:
		c->digits[0] = 0;
		c->size = 1;
		break;
	case 1:
		break;
	default:
		break;
	}

	for(i = 0; i <= 1000; i++)
	{
		c->digits[i] = 0;
	}
	c->size = 0;

	for(i = 0; i < max(a->size,b->size) - 1;i++){
		int temp;
		if( a->digits[i] - carry >= b->digits[i]){
			temp =  a->digits[i] - b->digits[i] - carry;
			carry = 0;
		}
		else{
			temp =   10000 + a->digits[i] - b->digits[i];
			carry = 1;
		}
		c->digits[c->size++] = temp;
	}

		c->digits[c->size++] = (a->digits[i] - b->digits[i] - carry) * f;
		shrink(c);
}
int8_t cmp(BigInteger a, BigInteger b){
	int size = max(a->size,b->size)-1;
	while(a->digits[size] == b->digits[size]){
		while(size == 0)
			return 0;
			size--;
	}
	return a->digits[size] > b->digits[size] ? 1 : -1;
}
void shrink(BigInteger a){

	while(a->digits[a->size-1] == 0){
		a->size--;
	}
}
