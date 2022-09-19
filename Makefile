NAME		= ft_containers

INCSDIR		= incs/

SRCSDIR 	= srcs/

OBJSDIR		= objs/

SRCS		= ${SRCSDIR}ft_containers.cpp \

OBJS 		= ${SRCS:%.cpp=${OBJSDIR}%.o}

DEPS		= ${SRCS:%.cpp=${OBJSDIR}%.d}

CC			= c++

CFLAGS		= -Wall  -Wextra -Werror --std=c++98 -I ${INCSDIR} -g3

RM			= rm -rf

all:		${NAME}

${NAME}: 	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

-include	${DEPS}

${OBJS}:	${OBJSDIR}%.o:%.cpp
			@mkdir -p $(dir $@)
			${CC} -I ${INCSDIR} -MMD -MP -o $@ -c $< ${CFLAGS}

clean:
			${RM} ${OBJS} ${OBJSDIR} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
