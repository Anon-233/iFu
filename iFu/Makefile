default: compile

base_dir = $(abspath .)
src_dir = $(base_dir)/src/main
gen_dir = $(base_dir)/nscscc-la/vsrc/pipeline
out_dir = $(base_dir)/outputs

CHIPLAB_HOME = $(base_dir)

TEST = 3


SPLIT = true

SBT = sbt

compile: $(gen_dir)/iFuCore.v

$(gen_dir)/iFuCore.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run $(gen_dir) $(SPLIT)"

split:
	make SPLIT=false

log:
	make split > ./log

clean:
	rm -rf $(gen_dir)/iFuCore.sv $(out_dir) test_run_dir

run:
	$(CHIPLAB_HOME)/sims/verilator/run_prog/configure.sh --run func/func_lab$(TEST) && \
	make -C $(CHIPLAB_HOME)/sims/verilator/run_prog

.PHONY: clean log split