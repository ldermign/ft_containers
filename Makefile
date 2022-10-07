NAMEFT		= ft_containers

NAMESTL		= stl_containers

INCSDIR		= incs/

FTDIR 		= srcs/

TESTDIR		= tests/

OBJSDIR		= objs/

FTSRCS		= ${FTDIR}ft_containers.cpp \

# vector
FTSRCS		+= ${FTDIR}vector.cpp \

# tests
FTSRCS		+= ${TESTDIR}vector_iterator.cpp \

# stack
# SRCS		+= ${STACKDIR}stack.cpp

# stack
# SRCS		+= ${STACKDIR}

# map
# SRCS		+= ${MAPDIR}

# STD
# SRCS		+= ${SRDDIR}

FTOBJS 		= ${FTSRCS:%.cpp=${OBJSDIR}%.o}

STLOBJS 	= ${STLSRCS:%.cpp=${OBJSDIR}%.o}

FTDEPS		= ${FTSRCS:%.cpp=${OBJSDIR}%.d}

STLDEPS		= ${STLSRCS:%.cpp=${OBJSDIR}%.d}

CC			= c++

CFLAGS		= -Wall -Wextra -Werror --std=c++98 -I ${INCSDIR} -g3

RM			= rm -rf

all:		${NAMEFT} ${NAMESTL}

${NAMEFT}: 	${FTOBJS}
			${CC} ${CFLAGS} -o ${NAMEFT} ${FTOBJS}

${NAMESTL}:	${STLOBJS}
			${CC} ${CFLAGS} -o ${NAMESTL} ${FTOBJS}

-include	${FTDEPS} ${STLDEPS}

${FTOBJS}:	${OBJSDIR}%.o:%.cpp
			@mkdir -p $(dir $@)
			${CC} -I ${INCSDIR} -MMD -MP -DLIBRARY=ft -o $@ -c $< ${CFLAGS}

${STLOBJS}:	${OBJSDIR}%.o:%.cpp
			@mkdir -p $(dir $@)
			${CC} -I ${INCSDIR} -MMD -MP -DLIBRARY=stl -o $@ -c $< ${CFLAGS}

clean:
			${RM} ${FTOBJS} ${STLOBJS} ${OBJSDIR} ${FTDEPS} ${STLDEPS}

fclean:		clean
			${RM} ${NAMEFT} ${NAMESTL}

re:			fclean all

.PHONY:		all clean fclean re
