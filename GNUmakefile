# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2024/1
# Prof. Marcelo Luiz Drumond Lanza
#
# Autor: Miguel de Azevedo Ferreira
# Descricao: Arquivo especifico para os sistemas operacionais da familia Linux.
#
# $Author: miguel.ferreira $
# $Date: 2024/04/21 23:28:57 $
# $Log: GNUmakefile,v $
# Revision 1.4  2024/04/21 23:28:57  miguel.ferreira
# Criacao das macros dos arquivos 05,06 e 07 implementadas com sucesso
#
# Revision 1.3  2024/04/20 07:39:27  miguel.ferreira
# Criacao e atualizacao da macro AULA0104OBJS e suas macros dependentes
#
# Revision 1.2  2024/04/20 01:17:11  miguel.ferreira
# Atualizacao do arquivo para incluir na execucao aula0103
#
# Revision 1.1  2024/04/19 22:37:43  miguel.ferreira
# Initial revision
#
# Revision 1.1  2024/04/19 22:25:47  miguel.ferreira
# Initial revision
#

OS = $(shell uname -s)

CC = gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALECT = ansi
STANDARD = -ansi

ifeq ($(dialeto), C90)
DIALECT = c90
STANDARD = -std=c90
endif

ifeq ($(dialeto), C89)
DIALECT = c89
STANDARD = -std=c89
endif

ifeq ($(dialeto), C99)
DIALECT = c99
STANDARD = -std=c99
endif

ifeq ($(dialeto), C11)
DIALECT = c11
STANDARD = -std=c11
endif

DEBUG =

ifeq ($(debug), DEPURACAO)
DEBUG = -DDEPURACAO
endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)
LFLAGS = -Wall

AULA01 = aula0102 aula0103 aula0104 aula0105 aula0106 aula0107

AULA0102OBJS = aula0101.o aula0102.o
AULA0103OBJS = aula0101.o aula0103.o
AULA0104OBJS = aula0101.o aula0104.o
AULA0105OBJS = aula0101.o aula0105.o
AULA0106OBJS = aula0101.o aula0106.o
AULA0107OBJS = aula0101.o aula0107.o

LIBS =

EXECS = $(AULA01)

ALL = $(LIBS) $(EXECS)

# Regra Implicita
.c.o:
        $(CC) $(CFLAGS) -c $<

all: $(ALL)

libs: $(LIBS)

execs: $(EXECS)


aula01: $(AULA01)

aula0102: $(AULA0102OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0103: $(AULA0103OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0104: $(AULA0104OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0105: $(AULA0105OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0106: $(AULA0106OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0107: $(AULA0107OBJS)
        $(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
        cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


.PHONY: clean-all clean clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c89 clean-c90 clean-c99 clean-c11

clean-all:
        rm -f *.o $(ALL) *-FreeBSD-* *-Linux-* *.core

clean:
        rm -f *.o $(ALL) *.core

clean-objs:
        rm -f *.o *.core

clean-bsd:
        rm -f *.o $(ALL) *-FreeBSD-* *.core

clean-linux:
        rm -f *.o $(ALL) *-Linux-* *.core

clean-gcc:
        rm -f *.o $(ALL) *-gcc-* *.core

clean-clang:
        rm -f *.o $(ALL) *-clang-* *.core

clean-ansi:
        rm -f *.o $(ALL) *-ansi *.core

clean-c89:
        rm -f *.o $(ALL) *-c89 *.core

clean-c90:
        rm -f *.o $(ALL) *-c90 *.core

clean-c99:
        rm -f *.o $(ALL) *-c99 *.core

clean-c11:
        rm -f *.o $(ALL) *-c11 *.core

# $RCSfile: GNUmakefile,v $
