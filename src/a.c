#include <stdio.h>
#include <stdlib.h>
#include "BigInteger.h"

int main(){
	BigInteger ai = bigInteger("221222");
	BigInteger bi = bigInteger("222222");
	BigInteger ci = bigInteger("0");
	substract(ai, bi, ci);
	output(ci);
	printf("%d",cmp(ai, bi));
	free(ai);
	free(bi);
	free(ci);
	return 0;
}
