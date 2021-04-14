cnf ?= .env
ifneq ($(wildcard $(cnf)),)
	include $(cnf)
	export $(shell sed 's/=.*//' $(cnf))
endif

ifeq ($(wildcard $(INCLUDE_MAKEFILE)),)
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
