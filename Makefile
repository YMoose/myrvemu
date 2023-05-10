CFLAGS=-O3 -Wall -Werror -Wimplicit-fallthrough
SRCS=$(wildcard src/*.c)
HDRS=$(wildcard src/*.h)
OBJS=$(patsubst src/%.c, obj/%.o, $(SRCS))
CC=clang
# $@: mak当前规则的目标文件名，通常用于在编译过程中生成目标文件
# $^：所有依赖文件的列表，以空格分隔。
# $<：第一个依赖文件的名称。
# $*：不包括后缀名的目标文件名。
# $?：比目标文件新的依赖文件列表。
rvemu: $(OBJS)
	@echo "$@"
	$(CC) $(CFLAGS) -lm -o $@ $^ $(LDFLAGS) 

$(OBJS): obj/%.o: src/%.c $(HDRS)
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf rvemu obj/

.PHONY: clean
