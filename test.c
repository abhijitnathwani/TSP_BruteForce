#include <stdio.h>
int i;
void b()
{
	printf("%d\n",i++);
}
void c()
{
	b(),b(),b(),b(),b(),b();
}
void a()
{
	c(),c(),c(),c(),c(),c();
}
void main()
{
	i=1;
	a(),a(),a(),a(),a();
}