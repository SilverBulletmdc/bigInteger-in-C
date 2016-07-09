#ifndef _BIG_INTEGER_H_
#define _BIG_INTEGER_H_
typedef char int8_t;
typedef struct {
	int digits[1001];
	int size;
} _BigInteger,*BigInteger;
/**
 * 产生一个初始值为0的大数
 */
BigInteger init();
/**
 * 根据字符串重置一个大数
 */
void set(char str[], BigInteger bi);
/**
 * 打印这个大数
 */
void output(BigInteger bi);
/**
 * 将a和b相加赋给c
 */
void add(BigInteger a, BigInteger b, BigInteger c);
/**
 * 将a-b赋给c
 */
void substract(BigInteger a, BigInteger b, BigInteger c);
/**
 * a < b 返回-1
 * a = b 返回 0
 * a > b 返回1
 */
int8_t cmp(BigInteger a, BigInteger b);
/**
 * 根据字符串生成一个大数
 */
BigInteger bigInteger(char str[]);
void shrink(BigInteger a);
#endif
