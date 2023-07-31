default: compile

base_dir = $(abspath .)
src_dir = $(base_dir)/src/main
gen_dir = $(base_dir)/generated_src
out_dir = $(base_dir)/outputs

SBT = sbt

compile: $(gen_dir)/iFuCore.v

$(gen_dir)/iFuCore.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run $(gen_dir)"

log:
	make > ./log

clean:
	rm -rf $(gen_dir) $(out_dir) test_run_dir

.PHONY: clean log