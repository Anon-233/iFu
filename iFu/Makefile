default: compile

base_dir = $(abspath .)
src_dir = $(base_dir)/src/main
gen_dir = $(base_dir)/build
out_dir = $(base_dir)/outputs

SPLIT = true

SBT = sbt

CLI = scala-cli

compile: $(gen_dir)/iFuCore.v

$(gen_dir)/iFuCore.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run $(gen_dir) $(SPLIT)"

split:
	make SPLIT=false

log:
	make split > ./log

clean:
	rm -rf $(gen_dir)/iFuCore.* $(out_dir) test_run_dir

.PHONY: clean log split
