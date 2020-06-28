#--------------------------------------------------------------------------------
# Updated on	:	June 5, 2020
# Author		:	SilverJolteon
#--------------------------------------------------------------------------------
CC			:=	gcc
CXX			:=	g++
#--------------------------------------------------------------------------------
TARGET		:=	HairColorEditor
SOURCES		:=	source
BUILD		:=	build
INCLUDES	:=	include
#---------------------------------------------------------------------------------
CFLAGS		:= 	-Iinclude
CXXFLAGS	:=	-static-libgcc -static-libstdc++
LDFLAGS		=	"-static"
LIBS		:=	
#---------------------------------------------------------------------------------
CFILES		:=	$(wildcard $(SOURCES)/*.c)
CPPFILES	:=	$(wildcard $(SOURCES)/*.cpp)
HFILES		:=	$(wildcard $(INCLUDES)/*.h) $(wildcard $(INCLUDES)/*.hpp)
OFILES		:=	$(CFILES:$(SOURCES)/%.c=$(BUILD)/%.o) $(CPPFILES:$(SOURCES)/%.cpp=$(BUILD)/%.o)
#---------------------------------------------------------------------------------
.PHONY: all clean
		
all: $(TARGET)

$(TARGET):$(OFILES)
	$(CXX) $^ $(LIBS) -o $@ $(LDFLAGS)
	
$(BUILD)/%.o: $(SOURCES)/%.c $(HFILES)
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
	
$(BUILD)/%.o: $(SOURCES)/%.cpp $(HFILES)
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
	
clean:
	@rm -fr $(BUILD) $(TARGET) CharaMakeHairColorParam.bcsv CharaMakeEyeColorParam.bcsv
	@echo Cleaned files