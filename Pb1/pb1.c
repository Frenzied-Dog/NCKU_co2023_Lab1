#include "common.h"
#include "user.h"

int main(void) {
	puts("2");
	for (int i=3; i<100; i++) {
		int isPrime=1;
		for (int j=2; j<=divide(i, 2); j++) {
			if (mod(i,j) == 0) {
				isPrime=0;
				break;
			}
		}

		if (isPrime) {
			putc(' ');
			putint(i);
		}
	}
	putc('\n');
	exit();
}