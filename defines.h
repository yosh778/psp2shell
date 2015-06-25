/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */

#ifndef DEFINES_H
#define DEFINES_H

#include <psp2/types.h>

#define align_mem(addr, align) (((addr) + ((align) - 1)) & ~((align) - 1))

extern int sceKernelAllocMemBlock(const char *name, int type, int size, void *optp);
extern int sceKernelGetMemBlockBase(SceUID uid, void **basep);


/* grabbed from: Hykem/vitasploit/include/FW_200_320/functions_ex.js */

#define SCE_OK 0x0

/* SceKernel */

#define SCE_KERNEL_MEMBLOCK_TYPE_USER_RW			0x0c20d060
#define SCE_KERNEL_MEMBLOCK_TYPE_USER_RW_UNCACHE		0x0c208060
#define SCE_KERNEL_MEMBLOCK_TYPE_USER_MAIN_PHYCONT_RW		0x0c80d060
#define SCE_KERNEL_MEMBLOCK_TYPE_USER_MAIN_PHYCONT_NC_RW	0x0d808060
#define SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW			0x09408060

/* SceGxm */

#define SCE_GXM_MEMORY_ATTRIB_READ	0x1
#define SCE_GXM_MEMORY_ATTRIB_WRITE	0x2
#define SCE_GXM_MEMORY_ATTRIB_RW	(SCE_GXM_MEMORY_ATTRIB_READ | SCE_GXM_MEMORY_ATTRIB_WRITE)


typedef int SceIoMode;
typedef int SceUID;
typedef int SceSSize;
typedef unsigned int SceSize;

#define PSP2_O_RDONLY    (0x0001)
#define PSP2_O_WRONLY    (0x0002)
#define PSP2_O_RDWR      (PSP2_O_RDONLY|PSP2_O_WRONLY)
#define PSP2_O_APPEND    (0x0100)
#define PSP2_O_CREAT     (0x0200)
#define PSP2_O_TRUNC     (0x0400)


// SceUID sceIoOpen(const char *filename, int flag, SceIoMode mode);
// SceSSize sceIoWrite(SceUID fd, const void *buf, SceSize nbyte);
// int sceIoClose(SceUID fd);
// FILE *fopen(const char *filename, const char *mode);


// SceUID sceIoDopen(const char *dirname);

// int    sceIoDclose(SceUID fd);




typedef struct SceIoStat {
	SceIoMode		st_mode;
	unsigned int	st_attr;
	SceOff			st_size;
	SceDateTime		st_ctime;
	SceDateTime		st_atime;
	SceDateTime		st_mtime;
	unsigned int	st_private[6];
} SceIoStat;

typedef struct SceIoDirent {
	SceIoStat	d_stat;
	char		d_name[256];
	void		*d_private;
	int			dummy;
} SceIoDirent;




#define FIO_S_IFMT			(0xF000)
#define FIO_S_IFDIR			(0x1000)

#define FIO_S_ISDIR(m)	(((m) & FIO_S_IFMT) == FIO_S_IFDIR)


#endif
