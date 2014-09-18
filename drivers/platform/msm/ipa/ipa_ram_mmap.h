/* Copyright (c) 2012-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _IPA_RAM_MMAP_H_
#define _IPA_RAM_MMAP_H_

/*
 * This header defines the memory map of the IPA RAM (not all SRAM is
 * available for SW use)
 * In case of restricted bytes the actual starting address will be
 * advanced by the number of needed bytes
 */

#define IPA_RAM_NAT_OFST    0
#define IPA_RAM_NAT_SIZE    0

#define IPA_MEM_v1_RAM_HDR_OFST    (IPA_RAM_NAT_OFST + IPA_RAM_NAT_SIZE)
#define IPA_MEM_v1_RAM_HDR_SIZE    1664
#define IPA_MEM_v1_RAM_V4_FLT_OFST (IPA_MEM_v1_RAM_HDR_OFST +\
	IPA_MEM_v1_RAM_HDR_SIZE)
#define IPA_MEM_v1_RAM_V4_FLT_SIZE 2176
#define IPA_MEM_v1_RAM_V4_RT_OFST  (IPA_MEM_v1_RAM_V4_FLT_OFST +\
	IPA_MEM_v1_RAM_V4_FLT_SIZE)
#define IPA_MEM_v1_RAM_V4_RT_SIZE  512
#define IPA_MEM_v1_RAM_V6_FLT_OFST (IPA_MEM_v1_RAM_V4_RT_OFST +\
	IPA_MEM_v1_RAM_V4_RT_SIZE)
#define IPA_MEM_v1_RAM_V6_FLT_SIZE 1792
#define IPA_MEM_v1_RAM_V6_RT_OFST  (IPA_MEM_v1_RAM_V6_FLT_OFST +\
	IPA_MEM_v1_RAM_V6_FLT_SIZE)
#define IPA_MEM_v1_RAM_V6_RT_SIZE  512
#define IPA_MEM_v1_RAM_END_OFST    (IPA_MEM_v1_RAM_V6_RT_OFST +\
	IPA_MEM_v1_RAM_V6_RT_SIZE)

#define IPA_MEM_RAM_V6_RT_SIZE_DDR 16384
#define IPA_MEM_RAM_V4_RT_SIZE_DDR 16384
#define IPA_MEM_RAM_V6_FLT_SIZE_DDR 16384
#define IPA_MEM_RAM_V4_FLT_SIZE_DDR 16384
#define IPA_MEM_RAM_HDR_SIZE_DDR 4096

#define IPA_MEM_CANARY_SIZE 4
#define IPA_MEM_CANARY_VAL 0xdeadbeef

/*
 * IPA v2.0 and v2.1 SRAM memory layout:
 * +-------------+
 * | V4 FLT HDR  |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * | V6 FLT HDR  |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * | V4 RT HDR   |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * | V6 RT HDR   |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * |  MODEM HDR  |
 * +-------------+
 * |  APPS  HDR  |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * |  MODEM MEM  |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * | APPS V4 FLT |
 * +-------------+
 * | APPS V6 FLT |
 * +-------------+
 * |    CANARY   |
 * +-------------+
 * |   UC INFO   |
 * +-------------+
 */
#define IPA_MEM_v2_RAM_OFST_START 128
#define IPA_MEM_v2_RAM_V4_FLT_OFST IPA_MEM_v2_RAM_OFST_START
#define IPA_MEM_v2_RAM_V4_FLT_SIZE 88

/* V4 filtering header table is 8B aligned */
#if (IPA_MEM_v2_RAM_V4_FLT_OFST & 7)
#error V4 filtering header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_V6_FLT_OFST (IPA_MEM_v2_RAM_V4_FLT_OFST + \
		IPA_MEM_v2_RAM_V4_FLT_SIZE + 2*IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_V6_FLT_SIZE 88

/* V6 filtering header table is 8B aligned */
#if (IPA_MEM_v2_RAM_V6_FLT_OFST & 7)
#error V6 filtering header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_V4_RT_OFST (IPA_MEM_v2_RAM_V6_FLT_OFST + \
		IPA_MEM_v2_RAM_V6_FLT_SIZE + 2*IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_V4_NUM_INDEX 11
#define IPA_MEM_v2_V4_MODEM_RT_INDEX_LO 0
#define IPA_MEM_v2_V4_MODEM_RT_INDEX_HI 3
#define IPA_MEM_v2_V4_APPS_RT_INDEX_LO 4
#define IPA_MEM_v2_V4_APPS_RT_INDEX_HI 10
#define IPA_MEM_v2_RAM_V4_RT_SIZE (IPA_MEM_v2_RAM_V4_NUM_INDEX * 4)

/* V4 routing header table is 8B aligned */
#if (IPA_MEM_v2_RAM_V4_RT_OFST & 7)
#error V4 routing header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_V6_RT_OFST (IPA_MEM_v2_RAM_V4_RT_OFST + \
		IPA_MEM_v2_RAM_V4_RT_SIZE + IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_V6_NUM_INDEX 11
#define IPA_MEM_v2_V6_MODEM_RT_INDEX_LO 0
#define IPA_MEM_v2_V6_MODEM_RT_INDEX_HI 3
#define IPA_MEM_v2_V6_APPS_RT_INDEX_LO 4
#define IPA_MEM_v2_V6_APPS_RT_INDEX_HI 10
#define IPA_MEM_v2_RAM_V6_RT_SIZE (IPA_MEM_v2_RAM_V6_NUM_INDEX * 4)

/* V6 routing header table is 8B aligned */
#if (IPA_MEM_v2_RAM_V6_RT_OFST & 7)
#error V6 routing header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_MODEM_HDR_OFST (IPA_MEM_v2_RAM_V6_RT_OFST + \
		IPA_MEM_v2_RAM_V6_RT_SIZE + IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_MODEM_HDR_SIZE 320

/* header table is 8B aligned */
#if (IPA_MEM_v2_RAM_MODEM_HDR_OFST & 7)
#error header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_APPS_HDR_OFST (IPA_MEM_v2_RAM_MODEM_HDR_OFST + \
		IPA_MEM_v2_RAM_MODEM_HDR_SIZE)
#define IPA_MEM_v2_RAM_APPS_HDR_SIZE 72

/* header table is 8B aligned */
#if (IPA_MEM_v2_RAM_APPS_HDR_OFST & 7)
#error header table is not 8B aligned
#endif

#define IPA_MEM_v2_RAM_MODEM_OFST (IPA_MEM_v2_RAM_APPS_HDR_OFST + \
		IPA_MEM_v2_RAM_APPS_HDR_SIZE + IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_MODEM_SIZE 3276

/* modem memory is 4B aligned */
#if (IPA_MEM_v2_RAM_MODEM_OFST & 3)
#error modem memory is not 4B aligned
#endif

#define IPA_MEM_v2_RAM_APPS_V4_FLT_OFST (IPA_MEM_v2_RAM_MODEM_OFST + \
		IPA_MEM_v2_RAM_MODEM_SIZE + IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_APPS_V4_FLT_SIZE 2176

/* filtering rule is 4B aligned */
#if (IPA_MEM_v2_RAM_APPS_V4_FLT_OFST & 3)
#error filtering rule is not 4B aligned
#endif

#define IPA_MEM_v2_RAM_APPS_V6_FLT_OFST (IPA_MEM_v2_RAM_APPS_V4_FLT_OFST + \
		IPA_MEM_v2_RAM_APPS_V4_FLT_SIZE)
#define IPA_MEM_v2_RAM_APPS_V6_FLT_SIZE 1372

/* filtering rule is 4B aligned */
#if (IPA_MEM_v2_RAM_APPS_V6_FLT_OFST & 3)
#error filtering rule is not 4B aligned
#endif

#define IPA_MEM_v2_RAM_UC_INFO_OFST (IPA_MEM_v2_RAM_APPS_V6_FLT_OFST + \
		IPA_MEM_v2_RAM_APPS_V6_FLT_SIZE + IPA_MEM_CANARY_SIZE)
#define IPA_MEM_v2_RAM_UC_INFO_SIZE 292

/* uC info 4B aligned */
#if (IPA_MEM_v2_RAM_UC_INFO_OFST & 3)
#error uC info is not 4B aligned
#endif

#define IPA_MEM_v2_RAM_END_OFST (IPA_MEM_v2_RAM_UC_INFO_OFST + \
		IPA_MEM_v2_RAM_UC_INFO_SIZE)
#define IPA_MEM_v2_RAM_APPS_V4_RT_OFST IPA_MEM_v2_RAM_END_OFST
#define IPA_MEM_v2_RAM_APPS_V4_RT_SIZE 0
#define IPA_MEM_v2_RAM_APPS_V6_RT_OFST IPA_MEM_v2_RAM_END_OFST
#define IPA_MEM_v2_RAM_APPS_V6_RT_SIZE 0

#endif /* _IPA_RAM_MMAP_H_ */
