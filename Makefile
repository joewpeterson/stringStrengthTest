## Comment

SRC = strStrength.cpp
OBJ = strStrength.o

# Set costrStrengthler
CC = g++ 

# CostrStrengthler flag options
CXXFLAGS :=  
CXXFLAGS_DEBUG := -g -O0
CXXFLAGS_PROFILE := -pg

# if make DEBUG=1 is passed, costrStrengthle in debug mode
ifeq ($(DEBUG),1)
	CXXFLAGS := $(CXXFLAGS) $(CXXFLAGS_DEBUG)
endif
ifeq ($(PROFILE),1)
	CXXFLAGS := $(CXXFLAGS) $(CXXFLAGS_PROFILE)
endif

strStrength: $(OBJ)
	$(CC) $(CXXFLAGS) -o strStrength $(OBJ) 

strStrength.o: strStrength.cpp 
	$(CC) $(CXXFLAGS) -c $(SRC) -o $(OBJ) 
	
.PHONY: clean
clean:
	rm strStrength $(OBJ) 

