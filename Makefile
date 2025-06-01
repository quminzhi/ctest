EXEC := ctest 

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

.PHONY: db
db: ctags cscope

.PHONY: ctags
ctags:
	ctags -R --languages=C,C++ --exclude=.git

.PHONY: cscope
cscope:
	@find . -name "*.[ch]" -o -name "*.cpp" -o -name "*.hpp" > cscope.files
	cscope -b -q -k

.PHONY: clean-db
clean-db:
	rm -rf compile_commands.json ctags cscope.*

# clean
.PHONY: clean
clean:
	@rm -rf ./build
