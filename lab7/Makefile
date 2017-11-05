#all:
#	gcc menu.c linktable.c -o menu
#	makefile for menu
CC_PTHREAD_FLAGS	= -lpthread
CC_FLAGS		= -c
CC_OUTPUT_FLAGS		= -o
CC			= gcc
RM			= rm
RM_FLAGS 		= -f
TARGET	=	menu
OBJS	= linktable.o menu.o
all:	$(OBJS)
	$(CC) $(CC_OUTPUT_FLAGS) $(TARGET) $(OBJS)
.c.o:	$(CC) $(CC_FLAGS) $<
clean:
	$(RM) $(RM_FLAGS) $(OBJS) $(TARGET) *.bak 
