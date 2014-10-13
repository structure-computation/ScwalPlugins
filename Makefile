LIBRARIES = \
	FieldsComparatorPlugin \
	GmshPlugin \
	StepReaderPlugin \
	Scills3DPlugin
	
SHELL = /bin/bash
	
all: 
	for i in ${LIBRARIES}; do \
		make -C $$i; \
	done
	