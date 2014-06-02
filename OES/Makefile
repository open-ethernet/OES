###################### include files & libs ########################################################
LIB_LOCATION=/usr/local/lib/
CFLAGS += $(EXTRA_BUILD_CFLAGS) -g -ggdb -Wall -Werror -fPIC
CFILES= oes_api_event.c oes_api_fdb.c
 
TARGET= liboesstub.so
INCLUDES= -I ./

all:
	make $(TARGET)

$(TARGET): $(CFILES) 
	gcc $(CFLAGS) --shared -o $(TARGET) $(CFILES) $(INCLUDES)

install:
	mkdir -p  $(LIB_LOCATION)
	cp $(TARGET) $(LIB_LOCATION)

clean:
	rm -f *.o *.so*
	rm -f $(TARGET) 
