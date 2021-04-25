cnf ?= .env
ifneq ($(wildcard $(cnf)),)
	include $(cnf)
	export $(shell sed 's/=.*//' $(cnf))
endif

ifdef INCLUDE_MAKEFILE
	include ../../${INCLUDE_MAKEFILE}	
endif

dummy:
	@echo "dummy-terraform"

# need implements the default targets for pipeline
build: dummy
deploy: dummy
