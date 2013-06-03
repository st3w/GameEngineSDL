SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .cpp .o

EXECUTABLE=GameEngineSDL

SOURCES = main.cpp GameEngine.cpp GameStateManager.cpp MainGameState.cpp MenuGameState.cpp  
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework SDL
LIBS = -lc -lc++
DEFINES = 
CPPFLAGS = -std=c++11 -stdlib=libc++ -g $(DEFINES)
INCLUDEDIRS = 
LIBDIRS =
LDFLAGS = $(FRAMEWORKS) $(LIBDIRS) $(LIBS) $(SDLFLAGS)

CC = clang++
LD = clang++
OBJECTS = $(SOURCES:.cpp=.o)

SDLMAIN = OSX/SDLMain.m
SDLOBJ  = $(SDLMAIN:.m=.o)

all: $(SOURCES) $(SDLMAIN) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(SDLOBJ) 
	$(LD) $(LDFLAGS) $(OBJECTS) $(SDLOBJ) -o $@

.cpp.o:
	$(CC) $(CPPFLAGS) $(INCLUDEDIRS) -c $< -o $@

OSX/%.o: OSX/%.m
	$(CC) $(INCLUDEDIRS) -c $< -o $@ 

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) $(SDLOBJ)
