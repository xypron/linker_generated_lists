// SPDX-License-Identifier: BSD-2-Clause

#include <stdio.h>
#include "srst.h"

int drv2_check(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
	return 2;
}

void drv2_execute(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
}

SRST_DRIVER(drv2) = {
	.name = "driver_2",
	.check = drv2_check,
	.execute = drv2_execute,
};
