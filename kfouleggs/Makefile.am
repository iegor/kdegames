INCLUDES = -I$(top_builddir)/libksirtet -I$(top_srcdir)/libksirtet -I$(top_srcdir)/libksirtet/base -I$(top_srcdir)/libkdegames -I$(top_srcdir)/libkdegames/highscore $(all_includes)

SUBDIRS = pics

KDE_CXXFLAGS = $(KDE_USE_FPIE)

bin_PROGRAMS      = kfouleggs
kfouleggs_LDADD   = $(top_builddir)/libksirtet/common/libksirtetcommon.la
kfouleggs_LDFLAGS = $(KDE_USE_PIE) $(all_libraries) $(KDE_RPATH)
kfouleggs_SOURCES = piece.cpp board.cpp ai.cpp field.cpp main.cpp prefs.kcfgc
METASOURCES       = board.moc ai.moc field.moc main.moc

rcdir   = $(kde_datadir)/kfouleggs
rc_DATA = kfouleggsui.rc

xdg_apps_DATA = kfouleggs.desktop
kde_kcfg_DATA = kfouleggs.kcfg

appdatadir = $(kde_datadir)/kfouleggs
appdata_DATA = eventsrc

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kfouleggs.pot

# for system-wide highscore file
DESTBIN = $(DESTDIR)$(bindir)/$(bin_PROGRAMS)
DESTHIGHSCORES = $(DESTDIR)$(HIGHSCORE_DIRECTORY)
DESTSCORES = $(DESTDIR)$(HIGHSCORE_DIRECTORY)/$(bin_PROGRAMS).scores

install-data-local:
	@(test x$(HIGHSCORE_DIRECTORY) != x \
	&& echo "********************************************************" \
	&& echo "" \
	&& echo "This game is installed sgid \"games\" to use the" \
	&& echo "system-wide highscore file (in "$(HIGHSCORE_DIRECTORY)")." \
	&& echo "" \
	&& echo "If the system-wide highscore file does not exist, it is" \
        && echo "created with the correct ownership and permissions. See the" \
        && echo "INSTALL file in \"kdegames/libkdegames/highscore\" for details." \
	&& echo "" \
	&& echo "********************************************************" \
	) || true

install-exec-hook:
	@(test x$(HIGHSCORE_DIRECTORY) != x \
        && ((chown $(highscore_user):$(highscore_group) $(DESTBIN)) \
	|| echo "Error: Could not install the game with correct permissions !!" \
	)) || true

	@(test x$(HIGHSCORE_DIRECTORY) != x \
		&& ((mkdir -p $(DESTHIGHSCORES) && chown $(highscore_user):$(highscore_group) $(DESTHIGHSCORES) \
		&& chmod 750 $(DESTHIGHSCORES)) \
	|| echo "Error: Could not create the highscore directory with correct permissions !!" \
	)) || true

	@(test x$(HIGHSCORE_DIRECTORY) != x \
        && ((chown $(highscore_user):$(highscore_group) $(DESTBIN)) \
	|| echo "Error: Could not install the game with correct permissions !!" \
	)) || true

	@(test ${setgid} = true \
        && ((chmod 2755  $(DESTBIN)) \
	|| echo "Error: Could not install the game with correct permissions !!" \
	)) || true

	@(test x$(HIGHSCORE_DIRECTORY) != x \
        && ((touch $(DESTSCORES) && chown $(highscore_user):$(highscore_group) $(DESTSCORES) \
	&& chmod 0660 $(DESTSCORES)) \
	|| echo "Error: Could not create system-wide highscore file with correct permissions !!" \
	)) || true

field.o: ../libksirtet/common/commonprefs.h ../libksirtet/base/baseprefs.h
main.o: ../libksirtet/common/commonprefs.h ../libksirtet/base/baseprefs.h
prefs.o: ../libksirtet/common/commonprefs.h ../libksirtet/base/baseprefs.h

