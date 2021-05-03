SHELL	 = /bin/bash

cnf ?= .env
ifeq ($(shell test -e $(cnf) && echo -n yes),yes)
	include $(cnf)
	export $(shell sed 's/=.*//' $(cnf))
endif

ifneq ($(shell test -e $(INCLUDE_MAKEFILE) && echo -n yes),yes)
	ifdef REMOTE_MAKEFILE
		REMOTE_MAKEFILE_RESULT := $(shell curl ${REMOTE_MAKEFILE} -o ${INCLUDE_MAKEFILE})	
	endif
endif

ifdef INCLUDE_MAKEFILE
	include ${INCLUDE_MAKEFILE}	
endif

dummy:
	@echo "dummy"

# need implements the default targets for pipeline
build: dummy
deploy: dummy
