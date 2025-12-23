APP_NAME := solution

SOURCE_DIR := src
OBJECT_DIR := obj
BINARY_DIR := bin

CXX := clang++ 
CXXFLAGS := --std=c++20

SOURCES := $(wildcard $(SOURCE_DIR)/*.cc)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.cc, $(OBJECT_DIR)/%.o, $(SOURCES))

RM := rm -f

all: $(APP_NAME)

$(APP_NAME): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $(APP_NAME) $(OBJECTS) $(LDLIBS)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cc
	@mkdir -p $(OBJECT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(APP_NAME)
	rm -rf $(OBJECT_DIR) 