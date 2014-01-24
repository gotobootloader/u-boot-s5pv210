/**
 * Copyright (C) 2013 The Gotoos Open Source Project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High level configuration options (easy to change) */
#define CONFIG_S5PC110 1

#define CONFIG_EVT1 1
#define CONFIG_MCP_SINGLE 1
#define CONFIG_ONENAND
#define CONFIG_MEMORY_UPPER_CODE
/* We don't need IRQ/FIQ stuff */
#undef CONFIG_USE_IRQ

#if defined(CONFIG_EVT1)
/* Set AFC value */
#define AFC_ON  0x00000000
#define AFC_OFF 0x10000010
#endif

#define CONFIG_SW_WORKAROUND 1   /* Software around */
#if defined(CONFIG_SW_WORKROUND)
#define CONFIG_CHECK_MPLL_LOCK 1 /* Check MPLL is locked. */
#endif

#define BOOT_ONENAND 0x1
#define BOOT_NAND    0x2
#define BOOT_MMCSD   0x3
#define BOOT_NOR     0x4
#define BOOT_SEC_DEV 0x5

#define CONFIG_ENV_SIZE      0x4000    /* Total size of Environment Sector */
#define CONFIG_BAUDRATE      11520
#define CONFIG_ENV_IS_IN_NAND
/* Offset of environment data (variable area) to the beginning of flash
 * memory; for instance, with bottom boot type flash chips the second
 * secotor can be used; the offset for this sector is given here.
 */
#define CONFIG_ENV_OFFSET 0x0007c000

/* Stack size */
#define CONFIG_STACK_SIZE (512 * 1024)

/* Max number of sectors on a Flash chip */
#define CONFIG_SYS_MAX_FLASH_SECT 512
/* Max number of Flash memory banks */
#define CONFIG_SYS_MAX_FLASH_BANKS 1

/* DRAM: 0x2000_0000 - 0x5fff_ffff */

/* Physical start address of SDRAM. _Must_ be 0 here */
#define CONFIG_SYS_SDRAM_BASE   0x30000000
#define CONFIG_SYS_LOAD_ADDR    CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_SDRAM_BASE + CONFIG_STACK_SIZE)

/* Physical start address of text codes at SDRAM. */
#define CONFIG_ENABLE_MMU
#ifdef CONFIG_ENABLE_MMU
#define CONFIG_SYS_TEXT_BASE 0xc3e00000
#define CONFIG_UBOOT_BASE    0xc3e00000
#else
#define CONFIG_SYS_TEXT_BASE 0x23e00000
#define CONFIG_UBOOT_BASE    0x23e00000
#endif

#define CONFIG_PHY_UBOOT_BASE (CONFIG_SYS_SDRAM_BASE + 0x3e00000)
/* Total memory required by uboot */
#define CONFIG_UBOOT_SIZE (2 * 1024 * 1024)

#define CONFIG_NR_DRAM_BANKS 1      /* We have 1 bank of DRAM */
#define SDRAM_BANK_SIZE 0x20000000  /* 512 MB */
/* SDRAM Bank #1 */
#define PHYS_SDRAM_1      CONFIG_SYS_SDRAM_BASE
#define PHYS_SDRAM_1_SIZE SDRAM_BANK_SIZE

/* NAND configuration */
#define CONFIG_CMD_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE 1
#define CONFIG_SYS_NAND_BASE (0xE7200000)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN (CONFIG_ENV_SIZE + 896 * 1024)
/* max. Number of arguments accepted for monitor commands */
#define CONFIG_SYS_MAXARGS 16
/* Buffer size for Console output */
#define CONFIG_SYS_PBSIZE 384
/* Buffer size for input from the Console */
#define CONFIG_SYS_CBSIZE 256

#define CONFIG_SERIAL1 1  /* we use UART1 on qt210 */

#define CONFIG_SYS_TIMER_RATE 0

#endif  /* __CONFIG_H */
