SHELL	 = /bin/bash

cnf ?= .env
ifneq ($(shell test -e $(cnf) && echo -n yes),yes)
	ERROR := $(error $(cnf) file not defined in current directory)
endif

include $(cnf)
export $(shell sed 's/=.*//' $(cnf))

ifdef INCLUDE_MAKEFILE
	include ../../../${INCLUDE_MAKEFILE}	
endif

dummy:
	@echo "dummy"

# need implements the default targets for pipeline
build: dummy
deploy: dummy