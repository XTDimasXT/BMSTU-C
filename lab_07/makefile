CC := gcc

SRCS_DIR := ./src
SRCS := $(wildcard $(SRCS_DIR)/*.c)
HDRS_DIR := ./inc
HDRS := $(wildcard $(HDRS_DIR)/*.h)
OBJS_DIR := ./out
$(shell mkdir -p $(OBJS_DIR))
OBJS := $(OBJS_DIR)/array_operations.o $(OBJS_DIR)/filter.o $(OBJS_DIR)/read_print.o $(OBJS_DIR)/sort.o
UNIT_DIR := ./unit_tests
UNIT_OBJS := $(OBJS_DIR)/check_filter.o $(OBJS_DIR)/check_sort.o
UNIT_SRCS := $(wildcard $(UNIT_DIR)/*.h)

CFLAGS := -I$(HDRS_DIR) -std=c99 -Wall -Werror -Wpedantic -Wextra
UFLAGS := $(shell pkg-config --cflags --libs check)
ULINKS := -lcheck -lrt -lpthread -lm

.PHONY = unit release debug coverage func clean

app.exe : $(OBJS) $(OBJS_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

unit_tests.exe : $(OBJS) $(UNIT_OBJS) $(OBJS_DIR)/check_main.o
	$(CC) $(CFLAGS) $(UFLAGS) $(ULINKS) $^ -o $@

$(OBJS_DIR)/%.o : $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) $(UFLAGS) -c $< -o $@

%.d : %.c
	@$(CC) $(CFLAGS) -M $< > $@

include $(SRCS:.c=.d)
include $(UNIT_SRCS:.c=.d)

unit: unit_tests.exe
	./unit_tests.exe

release: CFLAGS += -O2
release: app.exe

debug: CFLAGS += -ggdb
debug: app.exe

coverage: CFLAGS += --coverage
coverage: func
coverage:
	gcov $(SRCS_DIR)/*.c

func: app.exe
	bash ./func_tests/scripts/func_tests.sh

clean:
	$(RM) $(OBJS_DIR)/* $(SRCS_DIR)/*.d *.exe ./func_tests/test.txt
	$(RM) -r $(OBJS_DIR)
