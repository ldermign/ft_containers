NAMEFT		= ft_containers

NAMESTD		= std_containers

INCSDIR		= incs/

FTDIR 		= srcs/

TESTDIR		= tests/

OBJSDIR		= objs/

FTSRCS		= ${FTDIR}main.cpp \

# tests
FTSRCS		+=	${TESTDIR}test_vector_iterator.cpp \
				${TESTDIR}test_vector_container.cpp \
				${TESTDIR}test_vector_reverse_iterator.cpp

# stack
# SRCS		+= ${STACKDIR}stack.cpp

# stack
# SRCS		+= ${STACKDIR}

# map
# SRCS		+= ${MAPDIR}

# STD
# SRCS		+= ${SRDDIR}

FTOBJS 		= ${FTSRCS:%.cpp=${OBJSDIR}%.o}

STDOBJS 	= ${FTSRCS:%.cpp=${OBJSDIR}%_std.o}

FTDEPS		= ${FTSRCS:%.cpp=${OBJSDIR}%.d}

STDDEPS		= ${FTSRCS:%.cpp=${OBJSDIR}%_std.d}

CC			= c++

CFLAGS		= -Wall -Wextra -Werror --std=c++98 -I ${INCSDIR} -g3

RM			= rm -rf

all:		${NAMEFT} ${NAMESTD}

${NAMEFT}: 	${FTOBJS}
			${CC} ${CFLAGS} -o ${NAMEFT} ${FTOBJS}

${NAMESTD}:	${STDOBJS}
			${CC} ${CFLAGS} -o ${NAMESTD} ${STDOBJS}

-include	${FTDEPS} ${STDDEPS}

${FTOBJS}:	${OBJSDIR}%.o:%.cpp
			@mkdir -p $(dir $@)
			${CC} -I ${INCSDIR} -MMD -MP -DLIBRARY=ft -o $@ -c $< ${CFLAGS}

${STDOBJS}:	${OBJSDIR}%_std.o:%.cpp
			@mkdir -p $(dir $@)
			${CC} -I ${INCSDIR} -MMD -MP -DLIBRARY=std -o $@ -c $< ${CFLAGS}

clean:
			${RM} ${FTOBJS} ${STDOBJS} ${OBJSDIR} ${OBJSDIR} ${FTDEPS} ${STDDEPS}

fclean:		clean
			${RM} ${NAMEFT} ${NAMESTD}

re:			fclean all

.PHONY:		all clean fclean re
