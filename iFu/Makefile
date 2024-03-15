default: compile

base_dir = $(abspath .)
src_dir = $(base_dir)/src/main
gen_dir = /host/chiplab/IP/myCPU

SBT = sbt

compile: $(gen_dir)/iFuCore.sv

$(gen_dir)/iFuCore.sv: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run $(gen_dir)"

log:
	make > ./log

clean:
	rm -rf $(gen_dir)/iFuCore.*

.PHONY: clean log
