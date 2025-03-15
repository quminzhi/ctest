EXEC := unixm

# run
.PHONY: run
run: build
	@./build/$(EXEC)

# build
.PHONY: build
build:
	@cmake -S . -B build && cmake --build build --parallel $(nproc)

# test
.PHONY: test
test:
	@cd ./build && ctest

# clean
.PHONY: clean
clean:
	@rm -rf ./build