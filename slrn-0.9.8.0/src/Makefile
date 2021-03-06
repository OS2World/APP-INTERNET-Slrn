# Makefile for slrn                               -*- sh -*-
# OS/2 specific version; assumes you're using EMX 0.9b or later.
# OS/2 specific version; assumes you're using EMX 0.9b or later.
#
# 1997, March 01, bjf: Added all necessary (and probably some unnecessay)
#                      dependencies to the $(OBJDIR)/*.o targets.
#
#
#---------------------------------------------------------------------------
# This file is divided into five configurable sections.  The last section
# is optional: Section 5 deals with setting up slrn to read the server name
# from a file. This is probably unnecessary on OS/2.

#-----------------------------------------------------------------------------
# 1. Choose a C compiler.  It must understand prototypes.
#-----------------------------------------------------------------------------
CC = gcc -O2 -Zcrtdll -Zmt -DOS2 -D__os2__#
#CC = gcc -g -Zcrtdll -Zmt -DOS2 -D__os2__#

#-----------------------------------------------------------------------------
# 2. On a few systems, additional libraries are required.
#-----------------------------------------------------------------------------
MISCLIBS = -lsocket -ltermcap -lvideo -luu -lcanlock -lssl -lcrypto # OS/2  

#-----------------------------------------------------------------------------
# 3. Directory where the slang library, slanglib.a, is located.
#    BUILD SLANG FIRST!!!!  If you do not have it, get it from its public FTP
#    space.  The current home is space.mit.edu:/pub/davis/slang.
#-----------------------------------------------------------------------------
SDIR = ../../slang/src#                  Location of slang.h
SLIBDIR = $(SDIR)/emxobjs#               Location of libslang.a

#-----------------------------------------------------------------------------
# 4. Location where object files are placed.
#-----------------------------------------------------------------------------
OBJDIR = objs#

#-----------------------------------------------------------------------------
# 5. If you want to read the server from a file, uncomment the following
#    lines and edit it as appropriate.  See INSTALL for more information.
#    It is also possible to provide defaults for other variables such as the
#    HOSTNAME, etc...  by editing the slrnfeat.h file.  Again, read INSTALL.
#-----------------------------------------------------------------------------
#NNTPSERVERFILE = -DNNTPSERVER_FILE=\"/usr/local/lib/news/nntp_server\"
#SLRNLIBDIR = -DSLRN_LIB_DIR=\"/usr/local/lib/news\"
#SLRNLIBDIR = -DSLRN_LIB_DIR=\"$(HOME)/lib/slrn\"

#----------------------------------------------------------------------------
# Nothing below here should require changing.
#----------------------------------------------------------------------------

OBJS = $(OBJDIR)/art.o \
       $(OBJDIR)/art_misc.o \
       $(OBJDIR)/art_sort.o \
       $(OBJDIR)/chmap.o \
       $(OBJDIR)/decode.o \
       $(OBJDIR)/editscore.o \
       $(OBJDIR)/group.o \
       $(OBJDIR)/hash.o \
       $(OBJDIR)/help.o \
       $(OBJDIR)/hooks.o \
       $(OBJDIR)/interp.o \
       $(OBJDIR)/menu.o \
       $(OBJDIR)/mime.o \
       $(OBJDIR)/misc.o \
       $(OBJDIR)/print.o \
       $(OBJDIR)/post.o \
       $(OBJDIR)/ranges.o \
       $(OBJDIR)/score.o \
       $(OBJDIR)/server.o \
       $(OBJDIR)/snprintf.o \
       $(OBJDIR)/slrn.o \
       $(OBJDIR)/sortdate.o \
       $(OBJDIR)/startup.o \
       $(OBJDIR)/ttymsg.o \
       $(OBJDIR)/util.o \
       $(OBJDIR)/slrndir.o \
       $(OBJDIR)/version.o \
       $(OBJDIR)/vfile.o \
       $(OBJDIR)/xover.o \
       $(OBJDIR)/grplens.o

OBJSpull = \
	$(OBJDIR)/nntplib.o \
	$(OBJDIR)/ranges.o \
	$(OBJDIR)/slrndir.o \
	$(OBJDIR)/slrnpull.o \
	$(OBJDIR)/snprintf.o \
	$(OBJDIR)/ttymsg.o \
	$(OBJDIR)/util.o \
	$(OBJDIR)/vfile.o

UUDECODE_OBJS = $(OBJDIR)/util.o $(OBJDIR)/snprintf.o $(OBJDIR)/ttymsg.o $(OBJDIR)/slrndir.o

CFLAGS = -I. -I$(SDIR) $(SLRNLIBDIR)

slrn.exe: $(OBJDIR) config.h slangversion $(OBJS)
	$(CC) $(OBJS) -o slrn.exe -L$(SLIBDIR) -lslang $(MISCLIBS)
	emxbind -s slrn.exe

slrnpull.exe: $(OBJDIR) config.h slangversion $(OBJSpull)
	$(CC) $(OBJSpull) -o slrnpull.exe -L$(SLIBDIR) -lslang -lsocket -lssl -lcrypto 
	emxbind -s slrnpull.exe

uudecode.exe: $(OBJDIR)/uudecode.o $(UUDECODE_OBJS)
	$(CC) $(CFLAGS) -o uudecode.exe $(OBJDIR)/uudecode.o \
 $(UUDECODE_OBJS) -L$(SLIBDIR) -lslang
	emxbind -s uudecode.exe

all:      slrn.exe slrnpull.exe uudecode.exe

$(OBJDIR):
	@mkdir $(OBJDIR)

config.h: slrnconf.h
	cp slrnconf.h config.h

$(OBJDIR)/art.o: art.c config.h slrnfeat.h jdmacros.h slrn.h group.h server.h \
                 nntpcodes.h art.h misc.h ttymsg.h post.h startup.h hash.h \
                 score.h menu.h util.h xover.h chmap.h decode.h mime.h \
                 snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/art.o art.c
$(OBJDIR)/art_misc.o: art.c config.h slrnfeat.h jdmacros.h slrn.h group.h server.h \
                 nntpcodes.h art.h misc.h ttymsg.h post.h startup.h hash.h \
                 score.h menu.h util.h xover.h chmap.h decode.h mime.h \
                 snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/art_misc.o art_misc.c
$(OBJDIR)/art_sort.o: art_sort.c jdmacros.h slrn.h group.h art.h art_sort.h \
                 misc.h hash.h util.h snprintf.h hooks.h menu.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/art_sort.o art_sort.c
$(OBJDIR)/chmap.o: chmap.c config.h slrnfeat.h jdmacros.h misc.h ttymsg.h \
                 util.h chmap.h group.h art.h charmaps.h \
                 snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/chmap.o chmap.c
$(OBJDIR)/editscore.o: editscore.c config.h slrnfeat.h jdmacros.h group.h \
                 art.h startup.h misc.h ttymsg.h score.h util.h snprintf.h \
		 ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/editscore.o editscore.c
$(OBJDIR)/group.o: group.c config.h slrnfeat.h jdmacros.h slrn.h group.h \
                 art.h misc.h ttymsg.h post.h server.h nntpcodes.h hash.h \
                 score.h menu.h util.h startup.h snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/group.o group.c
$(OBJDIR)/hash.o: hash.c config.h slrnfeat.h jdmacros.h hash.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/hash.o hash.c
$(OBJDIR)/help.o: help.c config.h slrnfeat.h jdmacros.h slrn.h misc.h \
                 ttymsg.h util.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/help.o help.c
$(OBJDIR)/hooks.o: hooks.c hooks.h slrn.h util.h config.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/hooks.o hooks.c
$(OBJDIR)/interp.o: interp.c config.h slrnfeat.h jdmacros.h slrn.h group.h \
                 art.h misc.h ttymsg.h startup.h server.h nntpcodes.h menu.h \
                 interp.h util.h snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/interp.o interp.c
$(OBJDIR)/menu.o: menu.c config.h slrnfeat.h jdmacros.h slrn.h menu.h misc.h \
                 ttymsg.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/menu.o menu.c
$(OBJDIR)/mime.o: mime.c config.h slrnfeat.h jdmacros.h server.h nntpcodes.h \
                 slrn.h misc.h ttymsg.h group.h art.h util.h mime.h snprintf.h \
		 ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/mime.o mime.c
$(OBJDIR)/misc.o: misc.c config.h slrnfeat.h jdmacros.h misc.h ttymsg.h \
                 group.h slrn.h post.h server.h nntpcodes.h util.h chmap.h \
                 mime.h snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/misc.o misc.c
$(OBJDIR)/post.o: post.c config.h slrnfeat.h jdmacros.h slrn.h server.h \
                 nntpcodes.h misc.h ttymsg.h post.h group.h art.h decode.h \
                 util.h chmap.h mime.h snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/post.o post.c
$(OBJDIR)/score.o: score.c config.h slrnfeat.h jdmacros.h slrn.h group.h \
                 misc.h ttymsg.h server.h nntpcodes.h hash.h util.h art.h \
                 xover.h score.h snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/score.o score.c
$(OBJDIR)/server.o: server.c config.h slrnfeat.h jdmacros.h slrn.h server.h \
                 nntpcodes.h misc.h ttymsg.h util.h startup.h spool.c \
                 snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/server.o server.c
$(OBJDIR)/slrn.o: slrn.c config.h slrnfeat.h jdmacros.h server.h nntpcodes.h \
                 slrn.h group.h misc.h ttymsg.h startup.h art.h score.h \
                 util.h chmap.h interp.h snprintf.h hooks.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/slrn.o slrn.c
$(OBJDIR)/snprintf.o: snprintf.h config.h util.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/snprintf.o snprintf.c
$(OBJDIR)/sortdate.o: sortdate.c config.h slrnfeat.h slrn.h util.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/sortdate.o sortdate.c
$(OBJDIR)/startup.o: startup.c config.h slrnfeat.h jdmacros.h slrn.h group.h \
                 misc.h ttymsg.h art.h post.h startup.h score.h util.h \
                 decode.h mime.h interp.h server.h nntpcodes.h chmap.h \
                 snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/startup.o startup.c
$(OBJDIR)/ranges.o: ranges.c ranges.h util.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/ranges.o ranges.c
$(OBJDIR)/ttymsg.o: ttymsg.c config.h ttymsg.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/ttymsg.o ttymsg.c
$(OBJDIR)/util.o: util.c config.h jdmacros.h util.h ttymsg.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/util.o util.c
$(OBJDIR)/version.o: version.c version.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/version.o version.c
$(OBJDIR)/decode.o: decode.c config.h slrnfeat.h decode.h util.h \
                 ttymsg.h jdmacros.h slrn.h misc.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/decode.o decode.c
$(OBJDIR)/uudecode.o: decode.c config.h slrnfeat.h decode.h util.h \
                 ttymsg.h jdmacros.h slrn.h misc.h snprintf.h
	$(CC) -c $(CFLAGS) -DSTANDALONE -o $(OBJDIR)/uudecode.o decode.c
$(OBJDIR)/xover.o: xover.c config.h slrnfeat.h jdmacros.h util.h ttymsg.h \
                 hash.h group.h art.h xover.h server.h nntpcodes.h \
                 snprintf.h ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/xover.o xover.c
$(OBJDIR)/vfile.o: vfile.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/vfile.o vfile.c
$(OBJDIR)/slrndir.o: slrndir.c config.h slrnfeat.h jdmacros.h util.h ttymsg.h \
                 hash.h group.h art.h slrndir.h server.h nntpcodes.h snprintf.h \
		 ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/slrndir.o slrndir.c
$(OBJDIR)/slrnpull.o: slrnpull.c config.h slrnfeat.h jdmacros.h ttymsg.h \
                 util.h sltcp.h nntplib.h nntpcodes.h score.c art.h xover.h \
                 score.h xover.c hash.h hash.c sortdate.c snprintf.h mime.c \
		 ranges.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/slrnpull.o slrnpull.c
$(OBJDIR)/sltcp.o: sltcp.c config.h sltcp.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/sltcp.o sltcp.c
$(OBJDIR)/nntplib.o: nntplib.c config.h jdmacros.h sltcp.h nntpcodes.h \
                 nntplib.h util.h ttymsg.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/nntplib.o nntplib.c
$(OBJDIR)/print.o: print.c config.h slrnfeat.h snprintf.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/print.o print.c
$(OBJDIR)/grplens.o: grplens.c config.h slrnfeat.h grplens.h
	$(CC) -c $(CFLAGS) -o $(OBJDIR)/grplens.o grplens.c

slangversion: $(OBJDIR)/chkslang.exe
	./$(OBJDIR)/chkslang.exe slrn 10003 10400

$(OBJDIR)/chkslang.exe: $(OBJDIR)/chkslang.o
	$(CC) $(OBJDIR)/chkslang.o -o $(OBJDIR)/chkslang.exe

$(OBJDIR)/chkslang.o: chkslang.c config.h jdmacros.h
	$(CC) -c -I$(SDIR) chkslang.c -o $(OBJDIR)/chkslang.o
clean:
	rm -rf *.o *~ $(OBJDIR) slrn.exe uudecode.exe *.log \
	core out out.* typescript files.pck* config.h

