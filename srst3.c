// SPDX-License-Identifier: BSD-2-Clause

#include <stdio.h>
#include "srst.h"

int drv3_check(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
	return 3;
}

void drv3_execute(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
}

SRST_DRIVER(drv3) = {
	.name = "driver_3",
	.check = drv3_check,
	.execute = drv3_execute,
};
