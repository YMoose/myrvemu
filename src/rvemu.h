#ifndef  RVEMU_RVEMU_H
#define  RVEMU_RVEMU_H

#include "types.h"

// __FILE__     : 文本替换文件名称
// __LINE__     : 文本替换代码当前行
// __VA_ARGS__  : 文本替换可变参数
#define fatalf(fmt, ...) (fprintf(stderr, "fatal: %s:%d " fmt "\n", __FILE__, __LINE__, __VA_ARGS__), exit(1))
#define fatal(msg) fatalf("%s", (msg))

/*
 * 因为本项目实现的用户空间模拟器，类似于qemu-user
 * 仅用于运行Linux ELF程序
 * 所以需要通过抽象 mmu 来模拟linxu程序的行为
 */
typedef struct {
    u64 entry;
} mmu_t;

typedef struct {
    u64 general_propose_regs[32];
    u64 pc;
} state_t;

typedef struct {
    state_t state;
    mmu_t entry;
} machine_t;

#endif  /* RVEMU_RVEMU_H */


