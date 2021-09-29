// SPDX-License-Identifier: BSD-2-Clause

#ifndef _SRST_H
#define _SRST_H 1

#include "list.h"

struct srst_ops {
	char name[32];
	int (*check)(unsigned int type, unsigned int reason);
	void (*execute)(unsigned int type, unsigned int reason);
};

#define SRST_DRIVER(name) \
list_entry(struct srst_ops, srst_driver, name)

#endif
