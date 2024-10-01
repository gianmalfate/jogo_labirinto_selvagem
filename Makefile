PROJECT_NAME =  labirinto
CC           =  gcc
GCCFLAGS     =  -Wall

BINFOLDER    =  bin
OUTFOLDER    =  $(BINFOLDER)/output
EXECFILE     =  $(OUTFOLDER)/$(PROJECT_NAME)

NCURSESINC   =  -Iinclude
NCURSESLIB   =  -Llibs

#Condiotional step for different OS
ifdef OS
    LIB		=  -lncurses

    MKDIR = mkdir
    FixMKPath = $(subst /,\,$1)
    
    RMDIR = rmdir /s /q
    FixRMPath = $1

else
    ifeq ($(shell uname), Linux)
        LIB = -lncurses

        MKDIR = mkdir -p
        FixMKPath = $1
        
        RMDIR = rm -r
        FixRMPath = $1
    endif
endif

#Condiotional step to check bin folder exists
ifeq ($(wildcard bin/*),$(OUTFOLDER))
    MKDIR = @echo
    FixMKPath = $1 already exist
endif

ifneq ($(wildcard $(BINFOLDER)),$(BINFOLDER))
    RMDIR = @echo
    FixRMPath = $1 dont exist
endif

all: binFolder compile

compile:
	$(CC) $(GCCFLAGS) $(NCURSESINC) src/*.c -o $(EXECFILE) $(NCURSESLIB) $(LIB)

compile-linux:
	$(CC) $(GCCFLAGS) src/another.c -o $(EXECFILE) $(LIB)

binFolder:
	$(MKDIR) $(call FixMKPath,$(OUTFOLDER))

run:
	$(EXECFILE)

clean:
	$(RMDIR) $(call FixRMPath,$(BINFOLDER))