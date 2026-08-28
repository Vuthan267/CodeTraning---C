#include <stdio.h>

#include  "rodcutting.h"
#include "fibonacci.h"
#include  "climbstairs.h"
#include "coinchange.h"
#include "mincostpath.h"
#include "decode.h"

int main() {
	char digits[] = "130";
	printf("%d", countDecodeWays(digits, 3));

	return 0;
}
