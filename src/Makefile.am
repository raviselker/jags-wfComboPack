SUBDIRS = functions

jagsmod_LTLIBRARIES = wfComboPack.la

wfComboPack_la_SOURCES = wfComboPack.cc

wfComboPack_la_CPPFLAGS = -I$(includedir)/JAGS

wfComboPack_la_LIBADD = functions/wfComboPackfunc.la
if WINDOWS
wfComboPack_la_LIBADD += -ljags-$(JAGS_MAJOR)
else
wfComboPack_la_LIBADD += -ljags
endif

wfComboPack_la_LDFLAGS = -module -avoid-version
if WINDOWS
wfComboPack_la_LDFLAGS += -no-undefined
endif
