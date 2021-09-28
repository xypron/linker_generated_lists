// SPDX-License-Identifier: BSD-2-Clause

/*
 * In the linker script this is the relevant line:
 * .opensbilist	: { KEEP(*(SORT(opensbilist*))); }
 */

#ifndef _LIST_H
#define _LIST_H 1

#define LIST(type, list) \
	list_start(type, list); \
	list_end(type, list);

#define list_entry(type, list, item) \
	type \
	__attribute__((section("opensbilist_"#list"_2_"#item))) \
	__attribute__((unused)) \
	__attribute__((__aligned__(1))) \
	opensbilist_##list##_0_##item

#define list_start(type, list) \
	type \
	__attribute__((section("opensbilist_"#list"_1_"))) \
	__attribute__((unused)) \
	__attribute__((__aligned__(16))) \
	opensbilist_##list##_0_##start[0]

#define list_end(type, list) \
	type \
	__attribute__((section("opensbilist_"#list"_3_"))) \
	__attribute__((unused)) \
	__attribute__((__aligned__(1))) \
	opensbilist_##list##_0_##end[0]

#define list_get_start(type, list) \
	(opensbilist_##list##_0_##start)

#define list_get_end(type, list) \
	(opensbilist_##list##_0_##end)

#endif
