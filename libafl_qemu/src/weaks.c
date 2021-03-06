#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int64_t abi_long;
typedef uint64_t abi_ulong;

__attribute__((weak)) int libafl_qemu_write_reg(int reg, uint8_t* val) {
  (void)reg;
  (void)val;
  return 0;
}

__attribute__((weak)) int libafl_qemu_read_reg(int reg, uint8_t* val) {
  (void)reg;
  (void)val;
  return 0;
}

__attribute__((weak)) int libafl_qemu_num_regs(void) {
  return 0;
}

__attribute__((weak)) int libafl_qemu_set_breakpoint(uint64_t addr) {
  (void)addr;
  return 0;
}

__attribute__((weak)) int libafl_qemu_remove_breakpoint(uint64_t addr) {
  (void)addr;
  return 0;
}

__attribute__((weak)) int libafl_qemu_run() {
  return 0;
}

__attribute__((weak)) uint64_t libafl_load_addr() {
    return 0;
}

__attribute__((weak)) abi_long target_mmap(abi_ulong start, abi_ulong len,
                                           int target_prot, int flags, int fd,
                                           abi_ulong offset) {

  (void)start;
  (void)len;
  (void)target_prot;
  (void)flags;
  (void)fd;
  (void)offset;
  return 0;
}

__attribute__((weak)) int target_munmap(abi_ulong start, abi_ulong len) {
  (void)start;
  (void)len;
  return 0;
}

__attribute__((weak)) char* exec_path = NULL;
__attribute__((weak)) size_t guest_base = 0;

__attribute__((weak)) void (*libafl_exec_edge_hook)(uint64_t);
__attribute__((weak)) uint64_t (*libafl_gen_edge_hook)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_block_hook)(uint64_t);
__attribute__((weak)) uint64_t (*libafl_gen_block_hook)(uint64_t);

__attribute__((weak)) void (*libafl_exec_read_hook1)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_read_hook2)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_read_hook4)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_read_hook8)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_read_hookN)(uint64_t, uint64_t, uint32_t);
__attribute__((weak)) uint64_t (*libafl_gen_read_hook)(uint32_t);

__attribute__((weak)) void (*libafl_exec_write_hook1)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_write_hook2)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_write_hook4)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_write_hook8)(uint64_t, uint64_t);
__attribute__((weak)) void (*libafl_exec_write_hookN)(uint64_t, uint64_t, uint32_t);
__attribute__((weak)) uint64_t (*libafl_gen_write_hook)(uint32_t);

__attribute__((weak)) void (*libafl_exec_cmp_hook1)(uint64_t, uint8_t, uint8_t);
__attribute__((weak)) void (*libafl_exec_cmp_hook2)(uint64_t, uint16_t, uint16_t);
__attribute__((weak)) void (*libafl_exec_cmp_hook4)(uint64_t, uint32_t, uint32_t);
__attribute__((weak)) void (*libafl_exec_cmp_hook8)(uint64_t, uint64_t, uint64_t);
__attribute__((weak)) uint64_t (*libafl_gen_cmp_hook)(uint64_t, uint32_t);

struct syshook_ret {
    uint64_t retval;
    bool skip_syscall;
};
__attribute__((weak)) struct syshook_ret (*libafl_syscall_hook)(int, uint64_t,
                                          uint64_t, uint64_t, uint64_t, uint64_t,
                                          uint64_t, uint64_t, uint64_t);

typedef void GSList;

__attribute__((weak)) GSList * read_self_maps(void) {
    return NULL;
}
__attribute__((weak)) void free_self_maps(GSList *map_info) {
    (void)map_info;
}

struct libafl_mapinfo {
    uint64_t start, end;
    uint64_t offset;
    const char* path;
    int flags, is_priv;
};
__attribute__((weak)) GSList * libafl_maps_next(GSList *map_info, struct libafl_mapinfo* ret);
