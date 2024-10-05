#ifndef SYSTEM_DMA_H
#define SYSTEM_DMA_H

#include <ssb_types.h>
#include <PR/os.h>
#include <PR/ultratypes.h>

// loadovl.h? or a generic overlay header?
// all ends are exclusive (start..end)
typedef struct syOverlay
{
    uintptr_t rom_start;
    uintptr_t rom_end;
    void *ram_load_start;
    void *ram_text_start;
    void *ram_text_end;
    void *ram_data_start;
    void *ram_data_end;
    void *ram_noload_start;
    void *ram_noload_end;

} syOverlay;

typedef struct syHuffman
{
    struct syHuffman *left;
    struct syHuffman *right;
    s32 value;

} syHuffman;

extern OSPiHandle *gRomPiHandle;

extern void syDmaCreateMesgQueue(void);
extern void syDmaCopy(OSPiHandle *handle, uintptr_t phys_addr, uintptr_t virtual, size_t size, u8 direction);
extern void syDmaLoadOverlay(struct syOverlay *ovl);
extern void syDmaReadRom(uintptr_t rom_src, void *ram_src, size_t size);
extern void syDmaWriteRom(void *ram_src, uintptr_t rom_dst, size_t size);
extern OSPiHandle* syDmaSramPiInit(void);
extern void syDmaReadSram(uintptr_t rom_src, void *ram_dst, size_t size);
extern void syDmaWriteSram(void *ram_src, u32 rom_dst, size_t size);
extern void syDmaDecodeVpk0(u16* data, size_t size, void (*update_stream)(void), u8* out_buf);
extern void syDmaInitVpk0Stream(uintptr_t dev_addr, void *ram_addr, size_t size);
extern void syDmaFillVpk0Buf(void);
extern void syDmaReadVpk0Buf(uintptr_t dev_addr, void *ram_dst, void *ram_addr, size_t size);
extern void syDmaReadVpk0(uintptr_t dev_addr, void *ram_dst);

#endif /* SYSTEM_DMA_H */
