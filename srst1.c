// SPDX-License-Identifier: BSD-2-Clause

#include <stdio.h>
#include "srst.h"

int drv1_check(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
	return 1;
}

void drv1_execute(unsigned int type, unsigned int reason)
{
	printf("%s: type %u, reason %u\n", __func__, type, reason);
}

SRST_DRIVER(drv1) = {
	.name = "driver_1",
	.check = drv1_check,
	.execute = drv1_execute,
};
