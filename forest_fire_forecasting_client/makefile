BINARY=client_main
CODEDIRS=. ./src ../web-socket/easy-socket-master
THREAD_AND_TEST= -pthread -lgtest 
INCDIRS=. ./include ../web-socket/easy-socket-master/include ../forest_fire_forecasting_server/gtest ../forest_fire_forecasting_server/gtest/internal ../forest_fire_forecasting_server/gtest/internal/custom

CC=g++
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD
# automatically add the -I onto each include directory
CFLAGS= -Wl,--no-as-needed $(THREAD_AND_TEST) $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
# regular expression replacement
OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all: $(BINARY)
	# make -C ../web-socket/easy-socket-master

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(THREAD_AND_TEST)

# only want the .c file dependency here, thus $< instead of $^.
#
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

# shell commands are a set of keystrokes away
distribute: clean
	tar zcvf dist.tgz *

# @ silences the printing of the command
# $(info ...) prints output
diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean distribute diff
