// SPDX-License-Identifier: BSD-2-Clause

#include <stdio.h>
#include "list.h"
#include "srst.h"

struct data {
	int a;
	float b;
	char c;
};

LIST(struct data, mylist);
LIST(char, letters);
LIST(struct srst_ops, srst_driver);

list_entry(struct data, mylist, item1) = {1, .1, 'a'};
list_entry(struct data, mylist, item2) = {2, .2, 'b'};
list_entry(struct data, mylist, item3) = {3, .3, 'c'};

list_entry(char, letters, c1) = 'x';
list_entry(char, letters, c2) = 'y';
list_entry(char, letters, c3) = 'z';
list_entry(char, letters, c0) = 'w';

int main()
{
	struct data *start, *item, *end;

	start = list_get_start(struct data, mylist);
	end = list_get_end(struct data, mylist);

	printf("\n");
	for (item = start; item < end; ++item)
		printf("%d, %f, %c\n", item->a, item->b, item->c);

	printf("\n");
	for (char *c = list_get_start(char, letters);
	     c < list_get_end(char, letters); ++c)
		printf("%c\n", *c);

	for (struct srst_ops *drv =
		list_get_start(struct srst_ops, srst_driver);
	     drv < list_get_end(struct srst_ops, srst_driver); ++drv) {
		printf("\n");
		printf("%s->check() returned %d\n",
		       drv->name, drv->check(1, 2));
		drv->execute(1, 2);
	}

	return 0;
}
