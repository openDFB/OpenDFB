// Copyright (C) 2008,2009,2010 by Tom Kao & MISOO Team & Yonghua Jin. All rights reserved.
// Released under the terms of the GNU Library or Lesser General Public License (LGPL).
// Author: Tom Kao(中文名：高焕堂)，MISOO团队，Yonghua Jin(中文名：金永华)
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//    * Redistributions of source code must retain the above copyright
//	notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
//	copyright notice, this list of conditions and the following disclaimer
//	in the documentation and/or other materials provided with the
//	distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "oopc.h"

// 是否支持调试信息打印(内存分配和释放的详细信息），缺省关闭打印
//#define LW_OOPC_PRINT_DEBUG_INFO

#ifdef LW_OOPC_PRINT_DEBUG_INFO
    #define oopc_dbginfo printf
#else
    #define oopc_dbginfo
#endif

#define LW_OOPC_MAX_PATH   260
#define LW_OOPC_MEMORY_DETECTOR_RST "memory_detector_result.txt"

typedef struct OOPC_MemAllocUnit
{
    char file[LW_OOPC_MAX_PATH];    // 文件名
    int line;                       // 行号
    void* addr;                     // 内存地址
    size_t size;                    // 内存块大小
    struct OOPC_MemAllocUnit* next;     // 下一个内存块
} OOPC_MemAllocUnit;

#ifdef LW_OOPC_SUPPORT_MEMORY_LEAK_DETECTOR

static OOPC_MemAllocUnit* oopc_memAllocList = 0;

void* oopc_malloc(size_t size, const char* type, const char* file, int line)
{
    void* addr = malloc(size);
    if (addr != 0)
    {
        OOPC_MemAllocUnit* pMemAllocUnit = malloc(sizeof(OOPC_MemAllocUnit));
        if (!pMemAllocUnit)
        {
            fprintf(stderr, "lw_oopc: error! malloc alloc unit failed.\n");
            exit(1);
        }

        if (strlen(file) >= LW_OOPC_MAX_PATH)
        {
            fprintf(stderr, "lw_oopc: error! file name is more than %d character: %s\n", LW_OOPC_MAX_PATH, file);
            exit(1);
        }

        strcpy(pMemAllocUnit->file, file);

        pMemAllocUnit->line = line;
        pMemAllocUnit->addr = addr;
        pMemAllocUnit->size = size;
        pMemAllocUnit->next = oopc_memAllocList;
        oopc_memAllocList = pMemAllocUnit;

        oopc_dbginfo("lw_oopc: alloc memory in %p, size: %d, object type: %s, file: %s, line: %d\n", addr, size, type, file, line);
    }

    return addr;
}

void oopc_free(void* memblock)
{
    OOPC_MemAllocUnit* prevUnit = 0;
    OOPC_MemAllocUnit* currUnit = oopc_memAllocList;

    while(currUnit != 0)
    {
        if (currUnit->addr == memblock)
        {
            oopc_dbginfo("lw_oopc: free memory in %p, size: %d\n", currUnit->addr, currUnit->size);
            if (prevUnit == 0)
            {
                oopc_memAllocList = currUnit->next;
                free(currUnit->addr);
                return;
            }

            prevUnit->next = currUnit->next;
            return;
        }
        else
        {
            prevUnit = currUnit;
            currUnit = currUnit->next;
        }
    }

    if (currUnit == 0)
    {
        fprintf(stderr, "lw_oopc: error! you attemp to free invalid memory.\n");
        exit(1);
    }
}

void oopc_report()
{
    OOPC_MemAllocUnit* currUnit = oopc_memAllocList;
    FILE* fp = fopen(LW_OOPC_MEMORY_DETECTOR_RST, "w+");

    if(!fp)
    {
        fprintf(stderr, "lw_oopc: error occured, open file: %s failed.\n", LW_OOPC_MEMORY_DETECTOR_RST);
    }

    if (currUnit != 0)
    {
        fprintf(stderr, "lw_oopc: memory leak:\n");
        if(fp)
        {
            fprintf(fp, "lw_oopc: memory leak:\n");
        }

        while(currUnit != 0)
        {
            fprintf(stderr, "memory leak in: %p, size: %d, file: %s, line: %d\n", currUnit->addr, currUnit->size, currUnit->file, currUnit->line);
            if(fp)
            {
                fprintf(fp, "memory leak in: %p, size: %d, file: %s, line: %d\n", currUnit->addr, currUnit->size, currUnit->file, currUnit->line);
            }
            currUnit = currUnit->next;
        }
    }
    else
    {
        printf("lw_oopc: no memory leak.\n");
        if(fp)
        {
            fprintf(fp, "lw_oopc: no memory leak.\n");
        }
    }

    if(fp)
    {
        fclose(fp);
    }
}
#else

void oopc_report()
{
}

#endif