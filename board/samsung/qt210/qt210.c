/**
 * Copyright (C) 2013 The Gotoos Open Source Project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation
 */

#include <linux/types.h>

struct mtd_info;
typedef struct mtd_info nand_info_t;

void board_init(void)
{

}

void flash_init(void)
{

}

void reset_cpu(void)
{

}

void timer_init(void)
{

}

int dram_init(void)
{
    return 0;
}

/*void board_nand_init(struct nand_chip *nand)
{

}*/

struct serial_device* __default_serial_console(void)
{
#if defined(CONFIG_SERIAL1)
#endif /* CONFIG_SERIAL1 */
}

struct serial_device *default_serial_console(void)
        __attribute__((weak, alias("__default_serial_console")));
