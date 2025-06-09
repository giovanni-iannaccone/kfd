CXX = gcc
EXEC = kfd

SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/kfd.c $(SRC_DIR)/jwt.c $(SRC_DIR)/random.c $(SRC_DIR)/uuid.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CXX) -c $< -o $@

clean:
	rm -f $(EXEC) *.gdb $(BUILD_DIR)/*.o

.PHONY: all clean