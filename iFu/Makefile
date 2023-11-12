default: compile

base_dir = $(abspath .)
src_dir = $(base_dir)/src/main
gen_dir = $(base_dir)/IP/myCPU
diff_dir = $(base_dir)/sims/verilator/run_prog
out_dir = $(base_dir)/outputs

LAB = 3 
SPLIT = true

SBT = sbt

compile: $(gen_dir)/iFuCore.v

$(gen_dir)/iFuCore.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run $(gen_dir) $(SPLIT)"

difftest:
	$(diff_dir)/configure.sh --run func/func_lab$(LAB)
	$(MAKE) -C $(diff_dir)

split:
	make SPLIT=false

log:
	make split > ./log

clean:
	rm -rf $(gen_dir)/iFuCore.sv $(out_dir) test_run_dir

.PHONY: clean log split